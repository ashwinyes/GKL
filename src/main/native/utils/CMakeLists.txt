#---------------------------------------------------------------------
# utils
#---------------------------------------------------------------------
include_directories(../common)
include_directories(/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.aarch64/include)
include_directories(/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.aarch64/include/linux)

find_package(OpenMP)

set(TARGET gkl_utils)
add_library(${TARGET} SHARED utils.cc)
if(OPENMP_FOUND)
  set_target_properties(${TARGET} PROPERTIES COMPILE_OPTIONS ${OpenMP_CXX_FLAGS})
  target_link_libraries(${TARGET} ${OpenMP_CXX_FLAGS})
endif()
install(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR})
