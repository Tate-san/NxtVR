cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT "NxtVR")

#set(PICO_SDK_FETCH_FROM_GIT OFF)
# Initialize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/usr/share/pico-sdk")
set(PICO_EXTRAS_PATH "/usr/share/pico-extras")

set(PICO_BOARD pico CACHE STRING "Board type")


OPTION(DEBUG ON)

IF(DEBUG)
    ADD_DEFINITIONS(-DDEBUG)
ENDIF(DEBUG)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(${PROJECT} C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(${PROJECT}
                ${CMAKE_CURRENT_SOURCE_DIR}/nxtvr.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/hid/callbacks.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/hid/usb_descriptors.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/hid/hid_handler.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/sensors/sensor.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/sensors/mpu6050/mpu6050.cpp
                )

pico_set_program_name(${PROJECT} ${PROJECT})
pico_set_program_version(${PROJECT} "0.1")

pico_enable_stdio_uart(${PROJECT} 1)
pico_enable_stdio_usb(${PROJECT} 1)

# Add the standard library to the build
target_link_libraries(${PROJECT}
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(${PROJECT} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/sensors
  ${CMAKE_CURRENT_LIST_DIR}/hid
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(${PROJECT}
        hardware_pio
        hardware_i2c
        tinyusb_device
        tinyusb_board
        )

pico_add_extra_outputs(${PROJECT})

