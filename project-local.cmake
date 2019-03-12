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

################################################################################
# External Projects                                                            #
################################################################################
# RCSW
add_subdirectory(ext/rcsw)

# TICPP, which emits hundreds of compiler warnings if I compile with my usual
# robust set of warnings.
add_subdirectory(ext/ticpp)
target_compile_options(ticpp PRIVATE -Wno-old-style-cast -Wno-suggest-override
  -Wno-effc++ -Wno-overloaded-virtual -Wno-missing-declarations
  -Wno-suggest-attribute=const -Wno-suggest-attribute=pure)
# Boost
find_package(Boost 1.58.0 COMPONENTS system filesystem thread graph)
set(Boost_USE_STATIC_LIBS OFF)

################################################################################
# Includes                                                                     #
################################################################################
if (BUILD_FOR_MSI)
  set(ARGOS_INSTALL_PREFIX /home/gini/shared/swarm)
elseif(BUILD_FOR_TRAVIS)
  set(ARGOS_INSTALL_PREFIX /usr/local)
else()
  set(ARGOS_INSTALL_PREFIX /opt/data/local)
endif()

set(${target}_INCLUDE_DIRS
  "${${target}_INC_PATH}"
  ${rcsw_INCLUDE_DIRS})
set(${target}_SYS_INCLUDE_DIRS
  ${Boost_INCLUDE_DIRS}
  ${ARGOS_INSTALL_PREFIX}/include
  ${CMAKE_CURRENT_SOURCE_DIR})

################################################################################
# Libraries                                                                    #
################################################################################
set(${target}_LIBRARIES
  rcsw
  ticpp
  ${Boost_LIBRARIES}
  )

set(${target}_LIBRARY_DIRS ${rcsw_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})

# No need to link with this--it has been compiled out
if (NOT WITH_ER_NREPORT)
  set(${target}_LIBRARIES ${${target}_LIBRARIES} log4cxx)
endif()

if (BUILD_FOR_MSI)
  set(${target}_LIBRARY_DIRS ${${target}_LIBRARY_DIRS} ${ARGOS_INSTALL_PREFIX}/lib/argos3)
endif()

if (NOT TARGET ${target})
  add_library(${target} STATIC ${${target}_SRC})
  target_link_libraries(${target} ${${target}_LIBRARIES})
  target_include_directories(${target} PUBLIC ${${target}_INCLUDE_DIRS})
  target_include_directories(${target} SYSTEM PRIVATE "${${target}_SYS_INCLUDE_DIRS}")

  if ("${WITH_HAL_CONFIG}" MATCHES "argos-footbot")
    target_include_directories(${target} SYSTEM PRIVATE /usr/include/lua5.2)

    target_compile_definitions(${target} PUBLIC HAL_CONFIG=HAL_CONFIG_ARGOS_FOOTBOT)
  endif()
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
