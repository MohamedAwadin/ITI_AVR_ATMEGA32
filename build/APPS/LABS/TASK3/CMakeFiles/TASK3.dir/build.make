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
CMAKE_SOURCE_DIR = /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build

# Include any dependencies generated for this target.
include APPS/LABS/TASK3/CMakeFiles/TASK3.dir/depend.make

# Include the progress variables for this target.
include APPS/LABS/TASK3/CMakeFiles/TASK3.dir/progress.make

# Include the compile flags for this target's objects.
include APPS/LABS/TASK3/CMakeFiles/TASK3.dir/flags.make

APPS/LABS/TASK3/CMakeFiles/TASK3.dir/src/main.c.obj: APPS/LABS/TASK3/CMakeFiles/TASK3.dir/flags.make
APPS/LABS/TASK3/CMakeFiles/TASK3.dir/src/main.c.obj: ../APPS/LABS/TASK3/src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object APPS/LABS/TASK3/CMakeFiles/TASK3.dir/src/main.c.obj"
	cd /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/APPS/LABS/TASK3 && /usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TASK3.dir/src/main.c.obj   -c /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/src/main.c

APPS/LABS/TASK3/CMakeFiles/TASK3.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TASK3.dir/src/main.c.i"
	cd /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/APPS/LABS/TASK3 && /usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/src/main.c > CMakeFiles/TASK3.dir/src/main.c.i

APPS/LABS/TASK3/CMakeFiles/TASK3.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TASK3.dir/src/main.c.s"
	cd /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/APPS/LABS/TASK3 && /usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3/src/main.c -o CMakeFiles/TASK3.dir/src/main.c.s

# Object files for target TASK3
TASK3_OBJECTS = \
"CMakeFiles/TASK3.dir/src/main.c.obj"

# External object files for target TASK3
TASK3_EXTERNAL_OBJECTS =

APPS/LABS/TASK3/TASK3: APPS/LABS/TASK3/CMakeFiles/TASK3.dir/src/main.c.obj
APPS/LABS/TASK3/TASK3: APPS/LABS/TASK3/CMakeFiles/TASK3.dir/build.make
APPS/LABS/TASK3/TASK3: CTOS/MCAL/MDIO/libMDIO.a
APPS/LABS/TASK3/TASK3: APPS/LABS/TASK3/CMakeFiles/TASK3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TASK3"
	cd /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/APPS/LABS/TASK3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TASK3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
APPS/LABS/TASK3/CMakeFiles/TASK3.dir/build: APPS/LABS/TASK3/TASK3

.PHONY : APPS/LABS/TASK3/CMakeFiles/TASK3.dir/build

APPS/LABS/TASK3/CMakeFiles/TASK3.dir/clean:
	cd /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/APPS/LABS/TASK3 && $(CMAKE_COMMAND) -P CMakeFiles/TASK3.dir/cmake_clean.cmake
.PHONY : APPS/LABS/TASK3/CMakeFiles/TASK3.dir/clean

APPS/LABS/TASK3/CMakeFiles/TASK3.dir/depend:
	cd /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32 /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/APPS/LABS/TASK3 /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/APPS/LABS/TASK3 /home/awadin/ITI_9Monthes/AVR/Avr_Cmake/ITI_AVR_ATMEGA32/build/APPS/LABS/TASK3/CMakeFiles/TASK3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : APPS/LABS/TASK3/CMakeFiles/TASK3.dir/depend
