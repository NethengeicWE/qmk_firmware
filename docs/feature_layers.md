# Layers {#layers}

One of the most powerful and well used features of QMK Firmware is the ability to use layers.  For most people, this amounts to a function key that allows for different keys, much like what you would see on a laptop or tablet keyboard.

For a detailed explanation of how the layer stack works, checkout [Keymap Overview](keymap#keymap-and-layers).

## Switching and Toggling Layers {#switching-and-toggling-layers}

These functions allow you to activate layers in various ways. Note that layers are not generally independent layouts -- multiple layers can be activated at once, and it's typical for layers to use `KC_TRNS` to allow keypresses to pass through to lower layers. When using momentary layer switching with MO(), LM(), TT(), or LT(), make sure to leave the key on the above layers transparent or it may not work as intended.

* `DF(layer)` - switches the default layer. The default layer is the always-active base layer that other layers stack on top of. See below for more about the default layer. This might be used to switch from QWERTY to Dvorak layout. Note that this is a temporary switch that only persists until the keyboard loses power.
* `PDF(layer)` - sets a persistent default layer. This switch, which will last through a power loss, might be used to switch from QWERTY to Dvorak layout and only switch again when you want to.
* `MO(layer)` - momentarily activates *layer*. As soon as you let go of the key, the layer is deactivated.
* `LM(layer, mod)` - Momentarily activates *layer* (like `MO`), but with modifier(s) *mod* active. Only supports layers 0-15. The modifiers this keycode accept are prefixed with `MOD_`, not `KC_`. These modifiers can be combined using bitwise OR, e.g. `LM(_RAISE, MOD_LCTL | MOD_LALT)`.
* `LT(layer, kc)` - momentarily activates *layer* when held, and sends *kc* when tapped. Only supports layers 0-15.
* `OSL(layer)` - momentarily activates *layer* until the next key is pressed. See [One Shot Keys](one_shot_keys) for details and additional functionality.
* `TG(layer)` - toggles *layer*, activating it if it's inactive and vice versa
* `TO(layer)` - activates *layer* and de-activates all other layers (except your default layer). This function is special, because instead of just adding/removing one layer to your active layer stack, it will completely replace your current active layers, uniquely allowing you to replace higher layers with a lower one. This is activated on keydown (as soon as the key is pressed).
* `TT(layer)` - Layer Tap-Toggle. If you hold the key down, *layer* is activated, and then is de-activated when you let go (like `MO`). If you repeatedly tap it, the layer will be toggled on or off (like `TG`). It needs 5 taps by default, but you can change this by defining `TAPPING_TOGGLE` -- for example, `` to toggle on just two taps.

See also the [Layer Lock key](features/layer_lock), which locks the highest
active layer until pressed again.

### Caveats {#caveats}

Currently, the `layer` argument of `LT()` is limited to layers 0-15, and the `kc` argument to the [Basic Keycode set](keycodes_basic), meaning you can't use keycodes like `LCTL()`, `KC_TILD`, or anything greater than `0xFF`. This is because QMK uses 16-bit keycodes, of which 4 bits are used for the function identifier and 4 bits for the layer, leaving only 8 bits for the keycode.

For a similar reason, the `layer` argument of `LM()` is also limited to layers 0-15 and the `mod` argument must fit within 5 bits. As a consequence, although left and right modifiers are supported by `LM()`, it is impossible to mix and match left and right modifiers. Specifying at least one right-hand modifier in a combination such as `MOD_RALT|MOD_LSFT` will convert *all* the listed modifiers to their right-hand counterpart. So, using the aforementionned mod-mask will actually send <kbd>Right Alt</kbd>+<kbd>Right Shift</kbd>. Make sure to use the `MOD_xxx` constants over alternative ways of specifying modifiers when defining your layer-mod key.

| `LM(1,KC_LSFT)` | `LM(1,MOD_MASK_SHIFT)` | `LM(1,MOD_BIT(KC_LSFT))` | `LM(1,MOD_LSFT)` |
|:---------------:|:----------------------:|:------------------------:|:----------------:|
|       ❌        |          ❌            |           ❌             |        ✅        |

Expanding this would be complicated, at best. Moving to a 32-bit keycode would solve a lot of this, but would double the amount of space that the keymap matrix uses. And it could potentially cause issues, too. If you need to apply modifiers to your tapped keycode, [Tap Dance](features/tap_dance#example-5-using-tap-dance-for-advanced-mod-tap-and-layer-tap-keys) can be used to accomplish this.

## Working with Layers {#working-with-layers}

Care must be taken when switching layers, it's possible to lock yourself into a layer with no way to deactivate that layer (without unplugging your keyboard.) We've created some guidelines to help users avoid the most common problems.

### Beginners {#beginners}

If you are just getting started with QMK you will want to keep everything simple. Follow these guidelines when setting up your layers:

* Setup layer 0 as your default, "base" layer. This is your normal typing layer, and could be whatever layout you want (qwerty, dvorak, colemak, etc.). It's important to set this as the lowest layer since it will typically have most or all of the keyboard's keys defined, so would block other layers from having any effect if it were above them (i.e., had a higher layer number).
* Arrange your layers in a "tree" layout, with layer 0 as the root. Do not try to enter the same layer from more than one other layer.
* In a layer's keymap, only reference higher-numbered layers. Because layers are processed from the highest-numbered (topmost) active layer down, modifying the state of lower layers can be tricky and error-prone.

### Intermediate Users {#intermediate-users}

Sometimes you need more than one base layer. For example, if you want to switch between QWERTY and Dvorak, switch between layouts for different countries, or switch your layout for different videogames. Your base layers should always be the lowest numbered layers. When you have multiple base layers you should always treat them as mutually exclusive. When one base layer is on the others are off.

### Advanced Users {#advanced-users}

Once you have a good feel for how layers work and what you can do, you can get more creative. The rules listed in the beginner section will help you be successful by avoiding some of the tricker details but they can be constraining, especially for ultra-compact keyboard users. Understanding how layers work will allow you to use them in more advanced ways.

Layers stack on top of each other in numerical order. When determining what a keypress does, QMK scans the layers from the top down, stopping when it reaches the first active layer that is not set to `KC_TRNS`. As a result if you activate a layer that is numerically lower than your current layer, and your current layer (or another layer that is active and higher than your target layer) has something other than `KC_TRNS`, that is the key that will be sent, not the key on the layer you just activated. This is the cause of most people's "why doesn't my layer get switched" problem.

Sometimes, you might want to switch between layers in a macro or as part of a tap dance routine. `layer_on` activates a layer, and `layer_off` deactivates it. More layer-related functions can be found in [action_layer.h](https://github.com/qmk/qmk_firmware/blob/master/quantum/action_layer.h).

## Functions {#functions}

There are a number of functions (and variables) related to how you can use or manipulate the layers.

|Function                                      |Description                                                                                              |
|----------------------------------------------|---------------------------------------------------------------------------------------------------------|
| `layer_state_set(layer_mask)`                | Directly sets the layer state (avoid unless you know what you are doing).                               |
| `layer_clear()`                              | Clears all layers (turns them all off).                                                                 |
| `layer_move(layer)`                          | Turns specified layer on, and all other layers off.                                                     |
| `layer_on(layer)`                            | Turns specified layer on, leaves all other layers in existing state.                                    |
| `layer_off(layer)`                           | Turns specified layer off, leaves all other layers in existing state.                                   |
| `layer_invert(layer)`                        | Inverts/toggles the state of the specified layer                                                        |
| `layer_or(layer_mask)`                       | Turns on layers based on matching bits between specifed layer and existing layer state.                 |
| `layer_and(layer_mask)`                      | Turns on layers based on matching enabled bits between specifed layer and existing layer state.         |
| `layer_xor(layer_mask)`                      | Turns on layers based on non-matching bits between specifed layer and existing layer state.             |
| `layer_debug(layer_mask)`                    | Prints out the current bit mask and highest active layer to debugger console.                           |
| `default_layer_set(layer_mask)`              | Directly sets the default layer state (avoid unless you know what you are doing).                       |
| `default_layer_or(layer_mask)`               | Turns on layers based on matching bits between specifed layer and existing default layer state.         |
| `default_layer_and(layer_mask)`              | Turns on layers based on matching enabled bits between specifed layer and existing default layer state. |
| `default_layer_xor(layer_mask)`              | Turns on layers based on non-matching bits between specifed layer and existing default layer state.     |
| `default_layer_debug(layer_mask)`            | Prints out the current bit mask and highest active default layer to debugger console.                   |
| [`set_single_default_layer(layer)`](ref_functions.md#setting-the-persistent-default-layer)            | Sets the default layer, but does _not_ write it to persistent memory (EEPROM). | 
| [`set_single_persistent_default_layer(layer)`](ref_functions.md#setting-the-persistent-default-layer) | Sets the default layer and writes it to persistent memory (EEPROM).  |
| [`update_tri_layer(x, y, z)`](ref_functions.md#update_tri_layerx-y-z) | Checks if layers `x` and `y` are both on, and sets `z` based on that (on if both on, otherwise off). |
| [`update_tri_layer_state(state, x, y, z)`](ref_functions.md#update_tri_layer_statestate-x-y-z) | Does the same as `update_tri_layer(x, y, z)`, but from `layer_state_set_*` functions. |

In addition to the functions that you can call, there are a number of callback functions that get called every time the layer changes. This passes the layer state to the function, where it can be read or modified.

|Callback                                             |Description                                                                             |
|-----------------------------------------------------|----------------------------------------------------------------------------------------|
| `layer_state_set_kb(layer_state_t state)`           | Callback for layer functions, for keyboard.                                            |
| `layer_state_set_user(layer_state_t state)`         | Callback for layer functions, for users.                                               |
| `default_layer_state_set_kb(layer_state_t state)`   | Callback for default layer functions, for keyboard. Called on keyboard initialization. |
| `default_layer_state_set_user(layer_state_t state)` | Callback for default layer functions, for users. Called on keyboard initialization.    |

::: tip
For additional details on how you can use these callbacks, check out the [Layer Change Code](custom_quantum_functions#layer-change-code) document.
:::

It is also possible to check the state of a particular layer using the following functions and macros.

|Function                         |Description                                                                                      |Aliases
|---------------------------------|-------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| `layer_state_is(layer)`         | Checks if the specified `layer` is enabled globally.                                            | `IS_LAYER_ON(layer)`, `IS_LAYER_OFF(layer)`                           |
| `layer_state_cmp(state, layer)` | Checks `state` to see if the specified `layer` is enabled. Intended for use in layer callbacks. | `IS_LAYER_ON_STATE(state, layer)`, `IS_LAYER_OFF_STATE(state, layer)` |

## Layer Change Code {#layer-change-code}

This runs code every time that the layers get changed.  This can be useful for layer indication, or custom layer handling.

### Example `layer_state_set_*` Implementation

This example shows how to set the [RGB Underglow](features/rgblight) lights based on the layer, using the Planck as an example.

```c
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _LOWER:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _PLOVER:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _ADJUST:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}
```

### Example: Keycode to cycle through layers

This example shows how to implement a custom keycode to cycle through a range of layers.

```c
// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum keycodes {
  KC_CYCLE_LAYERS = QK_USER,
};

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   4

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CYCLE_LAYERS:
      // Our logic will happen on presses, nothing is done on releases
      if (!record->event.pressed) { 
        // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
        return false;
      }

      uint8_t current_layer = get_highest_layer(layer_state);

      // Check if we are within the range, if not quit
      if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
        return false;
      }

      uint8_t next_layer = current_layer + 1;
      if (next_layer > LAYER_CYCLE_END) {
          next_layer = LAYER_CYCLE_START;
      }
      layer_move(next_layer);
      return false;

    // Process other keycodes normally
    default:
      return true;
  }
}

// Place `KC_CYCLE_LAYERS` as a keycode in your keymap
```

Use the `IS_LAYER_ON_STATE(state, layer)` and `IS_LAYER_OFF_STATE(state, layer)` macros to check the status of a particular layer.

Outside of `layer_state_set_*` functions, you can use the `IS_LAYER_ON(layer)` and `IS_LAYER_OFF(layer)` macros to check global layer state.

### `layer_state_set_*` Function Documentation

* Keyboard/Revision: `layer_state_t layer_state_set_kb(layer_state_t state)`
* Keymap: `layer_state_t layer_state_set_user(layer_state_t state)`


The `state` is the bitmask of the active layers, as explained in the [Keymap Overview](keymap#keymap-layer-status)
