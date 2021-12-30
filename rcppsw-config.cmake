################################################################################
# Configuration Options                                                        #
################################################################################
set(${target}_CHECK_LANGUAGE "CXX")

# Each conference tag=minor increment. Each minor feature added=patch increment.
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 3)
set(PROJECT_VERSION_PATCH 0)

################################################################################
# External Projects                                                            #
################################################################################
# TICPP, which emits hundreds of compiler warnings if I compile with my usual
# robust set of warnings.
if (NOT TARGET ticpp)
  add_subdirectory(ext/ticpp)

  target_compile_options(ticpp_ticpp PRIVATE
    -Wno-old-style-cast
    -Wno-suggest-override
    -Wno-effc++
    -Wno-overloaded-virtual
    -Wno-missing-declarations
    -Wno-suggest-attribute=const
    -Wno-suggest-attribute=pure
    -Wno-suggest-final-types
    -Wno-suggest-final-methods
    -Wno-switch-default
    )
endif()

# Boost
find_package(Boost 1.71.0
  COMPONENTS
  system
  filesystem
  thread
  graph
  stacktrace_basic
  REQUIRED)
set(Boost_USE_STATIC_LIBS OFF)

# RCSW
find_package(rcsw
  COMPONENTS
  algorithm
  REQUIRED
  )

################################################################################
# Includes                                                                     #
################################################################################
set(${target}_INCLUDE_DIRS
  ${rcsw_INCLUDE_DIRS}
  )

################################################################################
# Libraries                                                                    #
################################################################################

set(${target}_LIBRARIES
  ticpp::ticpp
  ${Boost_LIBRARIES}
  pthread
  dl
  )

set(${target}_LIBRARY_DIRS ${rcsw_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})

if ("${LIBRA_ER}" MATCHES "ALL")
  set(${target}_LIBRARIES ${${target}_LIBRARIES} log4cxx)
endif()

# Define RCPPSW library
set(${target}_LIBRARY_NAME ${target}-${CMAKE_SYSTEM_PROCESSOR})
if (NOT TARGET ${${target}_LIBRARY_NAME})
  # The actual library
  add_library(
    ${${target}_LIBRARY_NAME}
    STATIC
    ${${target}_SRC}
    )

  # Single-component alias
  add_library(
    ${target}::${target}
    ALIAS
    ${${target}_LIBRARY_NAME}
    )

  # Alias so we plug into the LIBRA framework properly
  add_library(
    ${target}
    ALIAS
    ${${target}_LIBRARY_NAME}
    )

  target_include_directories(
    ${${target}_LIBRARY_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>  # <prefix>/rcppsw
    )
  target_include_directories(${${target}_LIBRARY_NAME} PUBLIC "${${target}_INCLUDE_DIRS}")
  # target_include_directories(${${target}_LIBRARY_NAME} SYSTEM PRIVATE "${${target}_SYS_INCLUDE_DIRS}")
  # target_link_libraries(${${target}_LIBRARY_NAME} ${${target}_LIBRARIES})
  # target_link_directories(${${target}_LIBRARY_NAME} PUBLIC ${${target}_LIBRARY_DIRS})

endif()

################################################################################
# Installation                                                                 #
################################################################################
# Define package dependencies
set(${target}_PACKAGE_DEPENDS
  ${_PACKAGE_DEPENDS}
  )

set(CPACK_DEBIAN_PACKAGE_DEPENDS
  ${cosm_PACKAGE_DEPENDS}
  )

################################################################################
# Exports                                                                      #
################################################################################
if (NOT IS_ROOT_PROJECT)
  # set(${target}_INCLUDE_DIRS "${${target}_INCLUDE_DIRS}" PARENT_SCOPE)
  # set(${target}_SYS_INCLUDE_DIRS "${${target}_SYS_INCLUDE_DIRS}" PARENT_SCOPE)
  set(${target}_LIBRARIES "${${target}_LIBRARIES}" PARENT_SCOPE)
  set(${target}_LIBRARY_DIRS "${${target}_LIBRARY_DIRS}" PARENT_SCOPE)
  set(${target}_LIBRARY_NAME "${${target}_LIBRARY_NAME}" PARENT_SCOPE)
endif()
