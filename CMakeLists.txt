cmake_minimum_required(VERSION 3.28.3)

# Project name and version
project(BuzvisApp VERSION 1.0 LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# Set the compiler to clang
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_MAKE_PROGRAM "/usr/bin/ninja")

set(CMAKE_PREFIX_PATH "/home/karan/.pyenv/versions/3.9.20")


# Use ninja as the generator
# set(CMAKE_GENERATOR Ninja)
# set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_PREFIX_PATH "/home/karan/.pyenv/versions/python3.9.20")



#Adding fmt with FetchContent
include(FetchContent)                                   # enable FetchContent
FetchContent_Declare(                                   # declare fmt repo
    fmt                                                  # name of the content
    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"   # the repository
    GIT_TAG "11.0.2"                                     # the tag
    GIT_SHALLOW On
)
FetchContent_MakeAvailable(fmt)                         # make available



# Find required Qt components
# Enable Qt's AUTOMOC for moc generation
set(CMAKE_AUTOMOC ON)
# Find required Qt components
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

# Find Python 3.9 with development headers
find_package(Python3 3.9 REQUIRED COMPONENTS Development)

# include_directories(/usr/include/python3.9)
# Include directories for Python
include_directories(${Python3_INCLUDE_DIRS})

# Link directories for Python
link_directories(${Python3_LIBRARY_DIRS})

# Include directories for the project
include_directories(include)

# Add Python directories manually if using pyenv

# set(PYTHON_INCLUDE_DIR "/home/karan/.pyenv/versions/3.9.20/include/python3.9")
# set(PYTHON_LIBRARY_DIR "/home/karan/.pyenv/versions/3.9.20/lib")

# Include directories for libraries
# include_directories(include)

# Source files or executables
# Add executable and source files
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/app/BuzvisApp.cpp
    src/modules/ASRHandler.cpp
    src/modules/SpeechSynthesis.cpp
    src/modules/CalendarManager.cpp
    src/modules/TaskManager.cpp
    src/modules/CommunicationHandler.cpp
    src/ui/mainwindow.cpp
)

# Link Qt libraries# Link Qt libraries, Python libraries, and fmt
target_link_libraries(${PROJECT_NAME}
Qt5::Core
Qt5::Widgets
Qt5::Gui
${Python3_LIBRARIES}
fmt::fmt  # Link fmt library
)

# Message to display Python paths found
message(STATUS "Python3 include directories: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3 libraries: ${Python3_LIBRARIES}")


# set(CMAKE_PREFIX_PATH "/venv/lib/python3.12/site-packages")

#set(CMAKE_PYTHON_INTERPRETER "/venv/bin/python")  # Adjust for your virtual environment


