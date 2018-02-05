################################################################################
# External Projects                                                            #
################################################################################
set(${target}_CHECK_LANGUAGE "CXX")
set(${target}_HAS_RECURSIVE_DIRS YES)

# RCSW
add_subdirectory(ext/rcsw)
include_directories(${rcsw_INCLUDE_DIRS})

# Boost
find_package(Boost 1.58.0 COMPONENTS system filesystem thread)
set(Boost_USE_STATIC_LIBS OFF)

################################################################################
# Includes                                                                     #
################################################################################
set(${target}_INCLUDE_DIRS "${${target}_INC_PATH}")

################################################################################
# Submodules                                                                   #
################################################################################
list(APPEND ${target}_SUBDIRS er)
list(APPEND ${target}_SUBDIRS multithread)
list(APPEND ${target}_SUBDIRS utils)
list(APPEND ${target}_SUBDIRS control)
list(APPEND ${target}_SUBDIRS task_allocation)
list(APPEND ${target}_SUBDIRS common)

if (WITH_MPI)
  list(APPEND ${target}_SUBDIRS multiprocess)
endif()

foreach(d ${${target}_SUBDIRS})
  add_subdirectory(src/${d})
  target_include_directories(${target}-${d} PUBLIC "${${target}_INCLUDE_DIRS}")
endforeach()

list(APPEND ${target}_pattern_SUBDIRS state_machine)
foreach(d ${${target}_pattern_SUBDIRS})
  add_subdirectory(src/patterns/${d})
  target_include_directories(${target}-${d} PUBLIC "${${target}_INCLUDE_DIRS}")
endforeach()

################################################################################
# Libraries                                                                    #
################################################################################
set(${target}_LIBS
  rcsw
  ${Boost_LIBRARIES}
  )

if (NOT TARGET ${target})
  add_library(${target} STATIC
    $<TARGET_OBJECTS:${target}-er>
    $<TARGET_OBJECTS:${target}-multithread>
    $<TARGET_OBJECTS:${target}-utils>
    $<TARGET_OBJECTS:${target}-state_machine>
    $<TARGET_OBJECTS:${target}-task_allocation>
    $<TARGET_OBJECTS:${target}-common>
    $<TARGET_OBJECTS:${target}-control>)
  target_link_libraries(${target} "${${target}_LIBS}")
endif()

################################################################################
# Exports                                                                      #
################################################################################
if (NOT IS_ROOT_PROJECT)
  set(${target}_INCLUDE_DIRS "${${target}_INCLUDE_DIRS}" ${rcsw_INCLUDE_DIRS} PARENT_SCOPE)
  set(${target}_LIBS "${${target}_LIBS}" PARENT_SCOPE)
endif()
