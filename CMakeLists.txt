cmake_minimum_required(VERSION 3.16)
project(MouseAutomater C CXX ASM)

set(CMAKE_CXX_STANDARD 20)

add_executable(MouseAutomater main.cpp InpRepl.cpp InpRepl.h WinInController.cpp WinInController.h InputMsg.cpp InputMsg.h)