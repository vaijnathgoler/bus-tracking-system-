cmake_minimum_required(VERSION 3.10)
project(BusTrackingSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(bus_tracking_system
    src/main.cpp
    src/Bus.cpp
    src/GPS.cpp
    src/TrackingSystem.cpp
)