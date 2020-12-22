cmake_minimum_required(VERSION 2.7)
project(p3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -Wno-unused-result -Wno-deprecated-declarations -Wconversion -Wvla")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

add_executable(p3_part1 P1main.cpp P1parkinglot.cpp P1slot.cpp P1TicketMachine.cpp P1vehicle.cpp)
add_executable(p3_part2 P2parkinglot.cpp P2main.cpp P2figure.cpp)

target_link_libraries(p3_part2 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)