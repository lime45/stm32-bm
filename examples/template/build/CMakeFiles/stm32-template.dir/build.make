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
CMAKE_SOURCE_DIR = /home/cbrowning/src/stm32-bm/examples/template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cbrowning/src/stm32-bm/examples/template/build

# Include any dependencies generated for this target.
include CMakeFiles/stm32-template.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stm32-template.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stm32-template.dir/flags.make

CMakeFiles/stm32-template.dir/main.c.obj: CMakeFiles/stm32-template.dir/flags.make
CMakeFiles/stm32-template.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cbrowning/src/stm32-bm/examples/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stm32-template.dir/main.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stm32-template.dir/main.c.obj   -c /home/cbrowning/src/stm32-bm/examples/template/main.c

CMakeFiles/stm32-template.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stm32-template.dir/main.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cbrowning/src/stm32-bm/examples/template/main.c > CMakeFiles/stm32-template.dir/main.c.i

CMakeFiles/stm32-template.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stm32-template.dir/main.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cbrowning/src/stm32-bm/examples/template/main.c -o CMakeFiles/stm32-template.dir/main.c.s

CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s.obj: CMakeFiles/stm32-template.dir/flags.make
CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s.obj: /home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cbrowning/src/stm32-bm/examples/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building ASM object CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s.obj"
	/usr/bin/arm-none-eabi-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s.obj -c /home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s

CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.obj: CMakeFiles/stm32-template.dir/flags.make
CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.obj: /home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cbrowning/src/stm32-bm/examples/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.obj   -c /home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c

CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c > CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.i

CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c -o CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.s

# Object files for target stm32-template
stm32__template_OBJECTS = \
"CMakeFiles/stm32-template.dir/main.c.obj" \
"CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s.obj" \
"CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.obj"

# External object files for target stm32-template
stm32__template_EXTERNAL_OBJECTS =

stm32-template.elf: CMakeFiles/stm32-template.dir/main.c.obj
stm32-template.elf: CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f031x6.s.obj
stm32-template.elf: CMakeFiles/stm32-template.dir/home/cbrowning/src/STM32CubeF0/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c.obj
stm32-template.elf: CMakeFiles/stm32-template.dir/build.make
stm32-template.elf: CMakeFiles/stm32-template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cbrowning/src/stm32-bm/examples/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable stm32-template.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stm32-template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stm32-template.dir/build: stm32-template.elf

.PHONY : CMakeFiles/stm32-template.dir/build

CMakeFiles/stm32-template.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stm32-template.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stm32-template.dir/clean

CMakeFiles/stm32-template.dir/depend:
	cd /home/cbrowning/src/stm32-bm/examples/template/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cbrowning/src/stm32-bm/examples/template /home/cbrowning/src/stm32-bm/examples/template /home/cbrowning/src/stm32-bm/examples/template/build /home/cbrowning/src/stm32-bm/examples/template/build /home/cbrowning/src/stm32-bm/examples/template/build/CMakeFiles/stm32-template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stm32-template.dir/depend
