################################################################################
# External Projects                                                            #
################################################################################
ExternalProject_Add(
project_rcsw
  SOURCE_DIR "$ENV{rcsw}"
  BINARY_DIR "$ENV{rcsw}/build"
  STEP_TARGETS build
  EXCLUDE_FROM_ALL TRUE
)
ExternalProject_Get_Property(project_rcsw binary_dir)
ExternalProject_Get_Property(project_rcsw source_dir)
add_library(rcsw SHARED IMPORTED)
set_property(TARGET rcsw PROPERTY IMPORTED_LOCATION ${binary_dir}/lib/librcsw.so)

################################################################################
# Includes                                                                     #
################################################################################
include_directories(${source_dir}/include)

################################################################################
# Submodules                                                                   #
################################################################################
get_filename_component(target ${CMAKE_CURRENT_LIST_DIR} NAME)

list(APPEND ${target}_SUBDIRS src/common)
list(APPEND ${target}_SUBDIRS src/multithread)
list(APPEND ${target}_SUBDIRS src/utils)
list(APPEND ${target}_SUBDIRS src/patterns/state_machine)
if (WITH_MPI)
  list(APPEND ${target}_SUBDIRS src/multiprocess)
endif()

################################################################################
# Libraries                                                                    #
################################################################################
add_library(${target} $<TARGET_OBJECTS:common>
  $<TARGET_OBJECTS:multithread>
  $<TARGET_OBJECTS:utils>
  $<TARGET_OBJECTS:state_machine>)

foreach(d ${${target}_SUBDIRS})
  add_subdirectory(${d})
endforeach()

target_link_libraries(${target} rcsw-build)
