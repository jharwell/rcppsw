################################################################################
# External Projects                                                            #
################################################################################
ExternalProject_Add(rcsw
  SOURCE_DIR "$ENV{rcsw}"
  BINARY_DIR "$ENV{rcsw}/build"
  STEP_TARGETS build
  EXCLUDE_FROM_ALL TRUE
)


################################################################################
# Includes                                                                     #
################################################################################
include_directories("$ENV{rcsw}/include")

################################################################################
# Submodules                                                                   #
################################################################################
add_subdirectory(src/dbg)
add_subdirectory(src/multithread)
add_subdirectory(src/utils)
if (WITH_MPI)
  add_subdirectory(src/multiprocess)
endif()

################################################################################
# Libraries                                                                    #
################################################################################
get_filename_component(target ${CMAKE_CURRENT_LIST_DIR} NAME)

add_library(${target} SHARED
  $<TARGET_OBJECTS:dbg>
  $<TARGET_OBJECTS:multithread>
  $<TARGET_OBJECTS:utils>
  )

if(WITH_MPI)
add_library(${target} SHARED
  $<TARGET_OBJECTS:multiprocess>)
endif()

add_dependencies(${target} rcsw-build)
