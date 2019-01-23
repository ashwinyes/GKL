project(GKL)
cmake_minimum_required(VERSION 2.8)

# add jni include path
find_package(Java 1.8 REQUIRED)
find_package(JNI)
include_directories(${JNI_INCLUDE_DIRS})

# common compiler and linker settings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3")
set(CMAKE_CXX_COMPILER "/opt/cavium/gcc-openmpi/gcc-8.1.0/bin/g++")
set(CMAKE_CC_COMPILER "/opt/cavium/gcc-openmpi/gcc-8.1.0/bin/gcc")
set(CMAKE_C_COMPILER "/opt/cavium/gcc-openmpi/gcc-8.1.0/bin/gcc")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if(APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++")
elseif(UNIX)
  set(CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++ -static-libgcc")
endif()

# add CMakeLists.txt in subdirectories
set(NATIVE_DIR ${PROJECT_SOURCE_DIR}/src/main/native)

add_subdirectory("${NATIVE_DIR}/pairhmm")
add_subdirectory("${NATIVE_DIR}/utils")
