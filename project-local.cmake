################################################################################
# Configuration Options                                                        #
################################################################################
set(WITH_HAL_CONFIG "argos-footbot" CACHE STRING "Specify the Hardware Abstraction Layer (HAL) target")
define_property(
  CACHED_VARIABLE PROPERTY "WITH_HAL_CONFIG"
		BRIEF_DOCS "Specify the Hardware Abstraction Layer (HAL) target"
		FULL_DOCS "Must be exactly one of: [argos-footbot]"
	        )
set(${target}_CHECK_LANGUAGE "CXX")
set(${target}_HAS_RECURSIVE_DIRS YES)

################################################################################
# External Projects                                                            #
################################################################################
# RCSW
add_subdirectory(ext/rcsw)

# TICPP, which emits hundreds of compiler warnings if I compile with my usual
# robust set of warnings.
add_subdirectory(ext/ticpp)
target_compile_options(ticpp PRIVATE -Wno-old-style-cast -Wno-suggest-override
  -Wno-effc++ -Wno-overloaded-virtual)

# Boost
find_package(Boost 1.58.0 COMPONENTS system filesystem thread graph)
set(Boost_USE_STATIC_LIBS OFF)

################################################################################
# Includes                                                                     #
################################################################################
if (BUILD_ON_MSI)
  set(ARGOS_INSTALL_PREFIX /home/gini/shared/swarm)
else()
  set(ARGOS_INSTALL_PREFIX /opt/data/local)
endif()

set(${target}_INCLUDE_DIRS "${${target}_INC_PATH}" ${rcsw_INCLUDE_DIRS})
set(${target}_SYS_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS} ${ARGOS_INSTALL_PREFIX})

################################################################################
# Submodules                                                                   #
################################################################################
list(APPEND ${target}_SUBDIRS er)
list(APPEND ${target}_SUBDIRS multithread)
list(APPEND ${target}_SUBDIRS utils)
list(APPEND ${target}_SUBDIRS control)
list(APPEND ${target}_SUBDIRS task_allocation)
list(APPEND ${target}_SUBDIRS params)
list(APPEND ${target}_SUBDIRS metrics)
list(APPEND ${target}_SUBDIRS ds)
list(APPEND ${target}_SUBDIRS math)

if (WITH_MPI)
  list(APPEND ${target}_SUBDIRS multiprocess)
endif()

foreach(d ${${target}_SUBDIRS})
  add_subdirectory(src/${d})
  target_include_directories(${target}-${d} PUBLIC "${${target}_INCLUDE_DIRS}")
  target_include_directories(${target}-${d} SYSTEM PRIVATE "${${target}_SYS_INCLUDE_DIRS}")
endforeach()

list(APPEND ${target}_pattern_SUBDIRS state_machine)

foreach(d ${${target}_pattern_SUBDIRS})
  add_subdirectory(src/patterns/${d})
  target_include_directories(${target}-${d} PUBLIC "${${target}_INCLUDE_DIRS}")
  target_include_directories(${target}-${d} SYSTEM PRIVATE "${${target}_SYS_INCLUDE_DIRS}")
endforeach()

list(APPEND ${target}_metrics_SUBDIRS tasks)

foreach(d ${${target}_metrics_SUBDIRS})
  add_subdirectory(src/metrics/${d})
  target_include_directories(${target}-${d} PUBLIC "${${target}_INCLUDE_DIRS}")
  target_include_directories(${target}-${d} SYSTEM PRIVATE "${${target}_SYS_INCLUDE_DIRS}")
endforeach()

list(APPEND ${target}_robotics_SUBDIRS steering2D)
list(APPEND ${target}_robotics_SUBDIRS kinematics2D)

foreach(d ${${target}_robotics_SUBDIRS})
  add_subdirectory(src/robotics/${d})

  target_include_directories(${target}-${d} PUBLIC "${${target}_INCLUDE_DIRS}")
  target_include_directories(${target}-${d} SYSTEM PRIVATE "${${target}_SYS_INCLUDE_DIRS}")

  if ("${WITH_HAL_CONFIG}" MATCHES "argos-footbot")
    target_compile_definitions(${target}-${d} PUBLIC HAL_CONFIG=HAL_CONFIG_ARGOS_FOOTBOT)
    target_include_directories(${target}-${d} PUBLIC /usr/include/lua5.2)
    target_include_directories(${target}-${d} SYSTEM PUBLIC ${ARGOS_INSTALL_PREFIX}/include)
  endif()
endforeach()

################################################################################
# Libraries                                                                    #
################################################################################
set(${target}_LIBRARIES
  rcsw
  ticpp
  ${Boost_LIBRARIES}
  )
set(${target_LIBRARY_DIRS} ${rcsw_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})

if (BUILD_ON_MSI)
  set(${target}_LIBRARY_DIRS ${${target}_LIBRARY_DIRS} ${ARGOS_INSTALL_PREFIX}/lib/argos3)
endif()

if (NOT TARGET ${target})
  add_library(${target} STATIC
    $<TARGET_OBJECTS:${target}-er>
    $<TARGET_OBJECTS:${target}-ds>
    $<TARGET_OBJECTS:${target}-multithread>
    $<TARGET_OBJECTS:${target}-utils>
    $<TARGET_OBJECTS:${target}-state_machine>
    $<TARGET_OBJECTS:${target}-steering2D>
    $<TARGET_OBJECTS:${target}-kinematics2D>
    $<TARGET_OBJECTS:${target}-task_allocation>
    $<TARGET_OBJECTS:${target}-params>
    $<TARGET_OBJECTS:${target}-tasks>
    $<TARGET_OBJECTS:${target}-math>
    $<TARGET_OBJECTS:${target}-metrics>
    $<TARGET_OBJECTS:${target}-control>)
  target_link_libraries(${target} ${${target}_LIBRARIES})
  target_include_directories(${target} PUBLIC ${${target}_INCLUDE_DIRS})
endif()

# Fix so we can build rcsw unit tests from this repo as well
if (WITH_TESTS)
  target_include_directories(rcsw-tests PUBLIC ${${target}_INCLUDE_DIRS})
endif()

################################################################################
# Exports                                                                      #
################################################################################
if (NOT IS_ROOT_PROJECT)
  set(${target}_INCLUDE_DIRS "${${target}_INCLUDE_DIRS}" PARENT_SCOPE)
  set(${target}_SYS_INCLUDE_DIRS "${${target}_SYS_INCLUDE_DIRS}" PARENT_SCOPE)
  set(${target}_LIBRARIES "${${target}_LIBRARIES}" PARENT_SCOPE)
  set(${target}_LIBRARY_DIRS "${${target}_LIBRARY_DIRS}" PARENT_SCOPE)
endif()
