cmake_minimum_required(VERSION 3.28)
project(FlightManageSystem)

set(CMAKE_CXX_STANDARD 17)

# Add the source files
add_executable(FlightManageSystem main.cpp
        user.cpp
        user.h
        manager.cpp
        manager.h
        plane.h
        plane.cpp
        login.cpp
        login.h
)

target_link_libraries(FlightManageSystem)