# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/build

# Utility rule file for flash_Task3.elf.

# Include the progress variables for this target.
include CMakeFiles/flash_Task3.elf.dir/progress.make

CMakeFiles/flash_Task3.elf: Task3.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Converting Task3.elf ELF to HEX file"
	avr-objcopy -O ihex Task3.elf Task3.elf.hex

flash_Task3.elf: CMakeFiles/flash_Task3.elf
flash_Task3.elf: CMakeFiles/flash_Task3.elf.dir/build.make

.PHONY : flash_Task3.elf

# Rule to build all files generated by this target.
CMakeFiles/flash_Task3.elf.dir/build: flash_Task3.elf

.PHONY : CMakeFiles/flash_Task3.elf.dir/build

CMakeFiles/flash_Task3.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flash_Task3.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flash_Task3.elf.dir/clean

CMakeFiles/flash_Task3.elf.dir/depend:
	cd /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3 /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3 /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/build /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/build /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/build/CMakeFiles/flash_Task3.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flash_Task3.elf.dir/depend

