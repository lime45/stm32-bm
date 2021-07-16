cmake_minimum_required(VERSION 3.13)
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(tools /usr)
set(CMAKE_C_COMPILER ${tools}/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-none-eabi-g++)
set(CMAKE_C_OBJCOPY ${tools}/bin/arm-none-eabi-objcopy CACHE PATH "" FORCE)
set(CMAKE_FLASH_TOOL ${tools}/bin/st-flash)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(stm32-bm C ASM)
set(MCU_SPEC cortex-m0)
add_compile_options(-g -O3 -mcpu=${MCU_SPEC} -mthumb -Wall)
add_link_options(-g -O3 -mcpu=${MCU_SPEC} -mthumb -Wall -nostdlib -lc --specs=nosys.specs -DVVC_F0 -DSTM32F031x6)
set(LD_SCRIPT ${CMAKE_SOURCE_DIR}/ld/STM32F031K6T6.ld)
set(PROJECT_SOURCES
	src/main.c
    src/interrupts_c.c
    src/peripherals.c
	src/core.S
	src/vector_table.S
	freertos/Source/list.c
	freertos/Source/queue.c
    freertos/Source/portable/GCC/ARM_CM0/port.c
	freertos/Source/tasks.c
    freertos/Source/portable/MemMang/heap_4.c
	)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LD_SCRIPT}")
add_executable(bm ${PROJECT_SOURCES})
target_include_directories(bm PUBLIC include vendor_include freertos/Source/include freertos/Source/portable/GCC/ARM_CM0/)
target_link_libraries(bm c gcc)
set_target_properties(bm PROPERTIES LINK_DEPENDS ${LD_SCRIPT})
add_custom_target(bm.bin ALL DEPENDS bm)
add_custom_command(TARGET bm.bin COMMAND ${CMAKE_C_OBJCOPY} ARGS -O binary bm bm.bin)
add_custom_target(bm.flash ALL DEPENDS bm.bin)
set_target_properties(bm.flash PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_custom_command(TARGET bm.flash COMMAND ${CMAKE_FLASH_TOOL} ARGS write bm.bin 0x8000000)
