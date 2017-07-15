cmake_minimum_required(VERSION 3.7)
project(DemoEmbededPython)

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
LINK_LIBRARIES(${PYTHON_LIBRARIES})
#if (${PYTHON_VERSION_MAJOR} EQUAL 3)
#    FIND_PACKAGE(Boost COMPONENTS python3)
#else()
#    FIND_PACKAGE(Boost COMPONENTS python)
#endif()

########## Boost dependency
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED OFF)
#set(Boost_USE_STATIC_RUNTIME OFF)
#find_package(Boost 1.55.0 COMPONENTS system REQUIRED)
#if(Boost_FOUND)
#    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
#    LINK_LIBRARIES(${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
#endif()

######## Complier message
set(CMAKE_BUILD_TYPE Release)
message(STATUS "System: ${CMAKE_SYSTEM}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

######## Set output directories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build/lib)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")
endif()

######## find all the source files.
file(GLOB HEADER_FILES *.h)
file(GLOB SOURCE_FILES *.cpp)

######## Set executable file name, and add the source files for it.
add_executable(DemoEmbededPython ${HEADER_FILES} ${SOURCE_FILES})
