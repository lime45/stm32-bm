cmake_minimum_required(VERSION 3.13)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/stm32_gcc.cmake)

project(stm32-template C ASM)
set(STM32_CUBE_F0_PATH /home/cbrowning/src/STM32CubeF0)
find_package(CMSIS COMPONENTS STM32F031K6 REQUIRED)
# Find CMSIS for all F4 devices: 
#find_package(CMSIS COMPONENTS STM32F4 REQUIRED)
# Find CMSIS for all devices: 
#find_package(CMSIS REQUIRED)

set(PROJECT_SOURCES
    main.c
)

add_executable(stm32-template ${PROJECT_SOURCES})
target_link_libraries(stm32-template CMSIS::STM32::F031K6 STM32::NoSys)
