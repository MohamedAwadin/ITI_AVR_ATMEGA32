# ITI_AVR_ATMEGA32

## Build and Flash Instructions

1. Navigate to the Task Directory(ex: Task1):

    ```bash
    cd APPS/LABS/TASK1
    mkdir build && cd build
    ```

2. Configure the Build:

    ```bash
    cmake ..
    ```

3. Build the Firmware:
    
    ```bash
    make
    ```

4. Flash the Firmware:

    ```bash
    make burn_Task1.elf
    ```


