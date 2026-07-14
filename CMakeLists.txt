cmake_minimum_required(VERSION 3.20)
project(University_Management_System CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(include)

add_executable(University_Management_System
        src/main.cpp
        src/Student.cpp
        src/Repository.cpp
        src/Service.cpp
        src/gui.cpp
        src/teste.cpp
)
target_link_libraries(University_Management_System PRIVATE Qt6::Widgets)