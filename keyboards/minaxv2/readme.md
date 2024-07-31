# minaxv2
> Nobody Makes Meaningless.   

[**minaxv2**]  
Why I make this keyboard:
1. I really dont like moving right hand between mouse and keyboard,sometime to press shortcut,others input num by numberpad.  
1. Dealing with the vacation study plan of the college base.  
1. An old saying: To do a good job, one must first sharpen one's tools.  
What is the difference between going to the battlefield without a pen and going to class without a gun:(  

Difference between v1 and v2:
1. Add gaps between numpad and main key to distingurish area and provide more space for PCB Layout.
1. Add OLED screen embeded into vertical enter key to display information (Working)
1. A more complete shell using aluminum alloy (Planning)

Keyboard Maintainer: [NWE](https://github.com/NethengeicWE)  
Hardware Supported: STM32F103CBT6(or BluePill)  
Hardware Availability: TaoBao 

Make example for this keyboard (after setting up your build environment):  
    qmk compile -kb minaxv2 -km default -j 0

Flashing example for this keyboard:  
    make minaxv1:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* stm32duino

Enter the bootloader in 3 ways:
* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape.In this project,you need to hold the Escape Key) and plug in the keyboard
* **Boot Pin**: Boot0 = 1 while boot1 = 0
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
