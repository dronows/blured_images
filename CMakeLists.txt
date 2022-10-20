# CMakeList.txt: проект CMake для blured; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("blured")
set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON) 
set(CMAKE_PREFIX_PATH "F:\\Qt\\5.12.12\\msvc2017_64\\lib\\cmake" )

find_package(Qt5 COMPONENTS Gui Core Widgets REQUIRED)
add_executable (blured "blured.cpp" "blured.h" "main.cpp" "blur.ui")

target_link_libraries(blured Qt5::Gui Qt5::Core Qt5::Widgets) 
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
