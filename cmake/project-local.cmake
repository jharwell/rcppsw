################################################################################
# Configuration Options                                                        #
################################################################################
# We are might be linking with a shared library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(rcppsw_CHECK_LANGUAGE "CXX")

# Each conference tag=minor increment. Each minor feature added=patch increment.
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 3)
set(PROJECT_VERSION_PATCH 0)

if (NOT DEFINED RCPPSW_AL_MT_SAFE_TYPES)
  set(RCPPSW_AL_MT_SAFE_TYPES YES)
endif()

################################################################################
# Components                                                                   #
################################################################################
component_register_as_src(
rcppsw_config_SRC
  rcppsw
  "${rcppsw_SRC}"
  config
  "src/config")
component_register_as_src(
rcppsw_control_SRC
  rcppsw
  "${rcppsw_SRC}"
  control
  "src/control")
component_register_as_src(
rcppsw_math_SRC
  rcppsw
  "${rcppsw_SRC}"
  math
  "src/math")
component_register_as_src(
rcppsw_metrics_SRC
  rcppsw
  "${rcppsw_SRC}"
  metrics
  "src/metrics")
component_register_as_src(
rcppsw_multiprocess_SRC
  rcppsw
  "${rcppsw_SRC}"
  multiprocess
  "src/multiprocess")
component_register_as_src(
rcppsw_multithread_SRC
  rcppsw
  "${rcppsw_SRC}"
  multithread
  "src/multithread")
component_register_as_src(
rcppsw_patterns_SRC
  rcppsw
  "${rcppsw_SRC}"
  patterns
  "src/patterns")
component_register_as_src(
rcppsw_types_SRC
  rcppsw
  "${rcppsw_SRC}"
  types
  "src/types")
component_register_as_src(
rcppsw_utils_SRC
  rcppsw
  "${rcppsw_SRC}"
  utils
  "src/utils")
component_register_as_src(
  rcppsw_er_SRC
  rcppsw
  "${rcppsw_SRC}"
  er
  "src/er")
# Root project (not used in find_package())
if (NOT rcppsw_FIND_COMPONENTS)
  set(rcppsw_FIND_COMPONENTS
    config
    control
    er
    math
    metrics
    multiprocess
    multithread
    patterns
    utils
    types
    )
endif()

requested_components_check(rcppsw)

################################################################################
# External Projects                                                            #
################################################################################
# TICPP, which emits hundreds of compiler warnings if I compile with my usual
# robust set of warnings.
add_subdirectory(ext/ticpp)
set_property(TARGET ticpp_ticpp PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_options(ticpp_ticpp PRIVATE
  -Wno-old-style-cast
  -Wno-useless-cast
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

if (NOT ${LIBRA_RTD_BUILD})
if(CMAKE_CROSSCOMPILING)
  set(BOOST_ROOT ${LIBRA_DEPS_PREFIX})
endif()

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      OFF)
set(Boost_USE_STATIC_RUNTIME     OFF)
find_package(Boost 1.71.0
  COMPONENTS
  system
  filesystem
  thread
  graph
  stacktrace_basic
  program_options
  REQUIRED)
endif()


find_package(rcsw)

# Log4cxx
if ("${LIBRA_ER}" MATCHES "ALL")
  set(log4cxx_ROOT ${LIBRA_DEPS_PREFIX})
  find_package(log4cxx)
endif()

################################################################################
# Libraries                                                                    #
################################################################################
# Create the source for the SINGLE library to build by combining the
# source of the selected components

foreach(component ${rcppsw_FIND_COMPONENTS})
  if(${rcppsw_${component}_FOUND})
    list(APPEND rcppsw_components_SRC ${rcppsw_} ${rcppsw_${component}_SRC})
  endif()
endforeach()

# Define RCPPSW library
add_library(
  rcppsw
  STATIC
  ${rcppsw_components_SRC}
  )

# Ensure the whole archive is linked
target_link_options(rcppsw
  INTERFACE
  -Wl,--whole-archive ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/librcppsw.a -Wl,--no-whole-archive
  )
target_include_directories(
  rcppsw
  PUBLIC
  $<BUILD_INTERFACE:${rcppsw_DIR}/include>
  $<BUILD_INTERFACE:${rcsw_INCLUDE_DIRS}>
  $<INSTALL_INTERFACE:include>
  )
target_include_directories(
  rcppsw
  SYSTEM PUBLIC
  $<BUILD_INTERFACE:${rcppsw_DIR}/ext>
  $<BUILD_INTERFACE:${log4cxx_INCLUDE_DIR}>
  $<BUILD_INTERFACE:${Boost_INCLUDE_DIRS}>
  )
target_link_libraries(rcppsw
  rcsw::rcsw
  ticpp::ticpp
  ${Boost_LIBRARIES}
  pthread
  dl
  )
if(${RCPPSW_AL_MT_SAFE_TYPES})
  target_compile_definitions(rcppsw PUBLIC RCPPSW_AL_MT_SAFE_TYPES)
endif()

if ("${LIBRA_ER}" MATCHES "ALL")
  target_link_directories(rcppsw PUBLIC ${LIBRA_DEPS_PREFIX}/lib)
  target_link_libraries(rcppsw log4cxx)
endif()


################################################################################
# Installation                                                                 #
################################################################################
configure_exports_as(rcppsw)

# Install ticpp
register_target_for_install(ticpp_ticpp ${CMAKE_INSTALL_PREFIX}/system)
register_headers_for_install(${CMAKE_CURRENT_SOURCE_DIR}/ext/ticpp ${CMAKE_INSTALL_PREFIX}/system)

# Install rcppsw
register_target_for_install(rcppsw ${CMAKE_INSTALL_PREFIX})
register_headers_for_install(include/rcppsw ${CMAKE_INSTALL_PREFIX})

################################################################################
# Status                                                                       #
################################################################################
libra_config_summary()

message(STATUS "")
message(STATUS "")
message(STATUS "RCPPSW Configuration Summary:")
message(STATUS "")
message(STATUS "Enable std::atomic types..............: RCPPSW_AL_MT_SAFE_TYPES=${RCPPSW_AL_MT_SAFE_TYPES}")

if(CMAKE_CROSSCOMPILING)
  message(STATUS "Boost root hint.......................: BOOST_ROOT=${BOOST_ROOT}")
endif()
