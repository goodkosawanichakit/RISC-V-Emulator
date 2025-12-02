cmake_minimum_required(VERSION 3.10)
project(RISC-V-Emulator C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB SOURCES "src/*.c")

add_executable(riscv_emu ${SOURCES})

target_include_directories(riscv_emu PUBLIC include)
