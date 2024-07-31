# minaxv1
The reckless work from humble college students
[minaxv1]

Why I make this keyboard:
1.I really dont like moving right hand between mouse and keyboard,sometime to press shortcut,others input num by numberpad.
2.Dealing with the vacation study plan of the college base.
3.An old saying: To do a good job, one must first sharpen one's tools.
What is the difference between going to the battlefield without a pen and going to class without a gun:(


* Keyboard Maintainer: [br Zhang](https://github.com/NethengeicWE)
* Hardware Supported: STM32F103C8T6(or BluePill)
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):
    make minaxv1:default

Flashing example for this keyboard:
    make minaxv1:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* stm32duino

Enter the bootloader in 3 ways:
* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
