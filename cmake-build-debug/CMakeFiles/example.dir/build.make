# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/dariusz/bin/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/dariusz/bin/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dariusz/Arduino/MSP430/msp430-learing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dariusz/Arduino/MSP430/msp430-learing/cmake-build-debug

# Utility rule file for example.

# Include the progress variables for this target.
include CMakeFiles/example.dir/progress.make

CMakeFiles/example: example.elf


example: CMakeFiles/example
example: CMakeFiles/example.dir/build.make
	/usr/bin/msp430-size example.elf
.PHONY : example

# Rule to build all files generated by this target.
CMakeFiles/example.dir/build: example

.PHONY : CMakeFiles/example.dir/build

CMakeFiles/example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example.dir/clean

CMakeFiles/example.dir/depend:
	cd /home/dariusz/Arduino/MSP430/msp430-learing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Arduino/MSP430/msp430-learing /home/dariusz/Arduino/MSP430/msp430-learing /home/dariusz/Arduino/MSP430/msp430-learing/cmake-build-debug /home/dariusz/Arduino/MSP430/msp430-learing/cmake-build-debug /home/dariusz/Arduino/MSP430/msp430-learing/cmake-build-debug/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example.dir/depend

