cmake_minimum_required(VERSION 3.5)

# Project name and version
project(BuzvisApp VERSION 1.0 LANGUAGES CXX)

# Find required Qt components
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

# Include directories
include_directories(include)

# Source files
add_executable(BuzvisApp
    src/main.cpp
    src/app/BuzvisApp.cpp
    src/modules/CalendarManager.cpp
    src/modules/TaskManager.cpp
    src/modules/CommunicationHandler.cpp
    src/ui/mainwindow.cpp
)

# Link Qt libraries
target_link_libraries(BuzvisApp Qt5::Core Qt5::Widgets Qt5::Gui)
