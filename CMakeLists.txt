cmake_minimum_required(VERSION 3.20)
project(ritangle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Always build with debug info unless told otherwise
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# One executable per .cpp file in src/
file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)

foreach(source ${SOURCES})
    get_filename_component(name ${source} NAME_WE)
    # EXCLUDE_FROM_ALL: only built when you run/debug that file,
    # so a broken or unfinished file never blocks the others
    add_executable(${name} EXCLUDE_FROM_ALL ${source})
    target_compile_options(${name} PRIVATE -Wal‰l -Wextra)
endforeach()