# ITI_AVR_ATMEGA32 Project

## Overview

This Branch is a collection of embedded software tasks and drivers designed for the **ATmega32 microcontroller**.

## Structure

### **APPS/LABS**: 
Contains the application code for various tasks and Tests.

------ 
### **COTS**: 
#### **MCAL Drivers**
The MCAL layer provides low-level drivers for interfacing with the microcontroller's peripherals.

1. **MDIO (Digital Input/Output Driver)**:
   - Handles GPIO (General Purpose Input/Output) operations.
   

2. **MPORT (Port Driver)**:
   - Manages port-level configurations and operations.

3. **MEXTINT (External Interupt Driver)**:
   - Manages External Interupt HW Pins configurations and operations.



#### **HAL Drivers**
The HAL layer provides drivers for interfacing with external hardware components.

1. **HLED (LED Driver)**:
   - Controls LEDs connected to the microcontroller.
   
2. **HSWITCH (Switch Driver)**:
   - Reads the state of mechanical switches.
   

3. **HSEVENSEG (Seven-Segment Display Driver)**:
   - Drives seven-segment displays.
   

4. **HLCD (LCD Driver)**:
   - Interfaces with alphanumeric LCDs.
   - Supports both 4-bit and 8-bit modes.

5. **HKEYPAD (Key Pad Driver)**:
   - Interfaces with KeyPad .

---
### **COMMON**: 

Common utilities like bit manipulation macros, memory mapping, and standard data types.




## Build and Flash Instructions

1. Navigate to the desired task directory (e.g., `TASK_SevSeg_Test`):

    ```bash
    cd APPS/LABS/TASK_SevSeg_Test
    ```

2. Create a build directory and configure the build:

    ```bash
    mkdir build && cd build
    cmake ..
    ```

3. Build the firmware:

    ```bash
    make
    ```

4. Flash the firmware to the ATmega32 microcontroller:

    ```bash
    make burn_TASK_SevSeg_Test.elf
    ```

