#---------------------------------------------------------------------
# common
#---------------------------------------------------------------------
if(NOT APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-as-needed")
endif()
set_property(SOURCE neon_impl.cc APPEND_STRING PROPERTY COMPILE_FLAGS " -flax-vector-conversions")

#---------------------------------------------------------------------
# common includes
#---------------------------------------------------------------------
include_directories(../common)
include_directories(/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.aarch64/include)
include_directories(/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.aarch64/include/linux)

#---------------------------------------------------------------------
# pairhmm_shacc (stub version)
#---------------------------------------------------------------------
set(TARGET gkl_pairhmm_shacc)
add_library(${TARGET} SHARED shacc_pairhmm_stub.cc)
install(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR})

#---------------------------------------------------------------------
# pairhmm
#---------------------------------------------------------------------
set(TARGET gkl_pairhmm)
add_library(${TARGET} SHARED IntelPairHmm.cc neon_impl.cc pairhmm_common.cc)
if (APPLE)
  target_link_libraries(${TARGET} gkl_pairhmm_shacc)
endif()
install(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR})

#---------------------------------------------------------------------
# pairhmm_omp
#---------------------------------------------------------------------
find_package(OpenMP)

if(OPENMP_FOUND)
  set(TARGET gkl_pairhmm_omp)
  add_library(${TARGET} SHARED IntelPairHmm.cc neon_impl.cc pairhmm_common.cc)
  set_target_properties(${TARGET} PROPERTIES COMPILE_OPTIONS ${OpenMP_CXX_FLAGS})
  target_link_libraries(${TARGET} ${OpenMP_CXX_FLAGS})
  install(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR})
endif()

#---------------------------------------------------------------------
# pairhmm_fpga
#---------------------------------------------------------------------
set(TARGET gkl_pairhmm_fpga)
add_library(${TARGET} SHARED IntelPairHmm.cc neon_impl.cc pairhmm_common.cc)
target_link_libraries(${TARGET} gkl_pairhmm_shacc)
install(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR})
