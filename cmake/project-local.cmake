################################################################################
# Configuration Options
################################################################################
# We might be linking with a shared library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(rcppsw_CHECK_LANGUAGE "CXX")

# Each conference tag=minor increment. Each minor feature added=patch increment.
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 4)
set(PROJECT_VERSION_PATCH 3)
set(RCPPSW_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

if (NOT DEFINED RCPPSW_AL_MT_SAFE_TYPES)
  set(RCPPSW_AL_MT_SAFE_TYPES YES)
endif()

libra_configure_version(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/version/version.cpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/src/version/version.cpp
  rcppsw_components_SRC
 )

 if(NOT RCPPSW_ER_PLUGIN)
   set(RCPPSW_ER_PLUGIN  LOG4CXX)
 endif()

 if (NOT RCPPSW_SUMMARY)
   set(RCPPSW_SUMMARY YES)
 endif()

 if(NOT RCPPSW_LIBTYPE)
   set(RCPPSW_LIBTYPE STATIC)
 endif()

################################################################################
# Components
################################################################################
libra_component_register_as_src(
rcppsw_config_SRC
  rcppsw
  "${rcppsw_SRC}"
  config
  "src/config")
libra_component_register_as_src(
rcppsw_abi_SRC
  rcppsw
  "${rcppsw_SRC}"
  abi
  "src/abi")
libra_component_register_as_src(
rcppsw_control_SRC
  rcppsw
  "${rcppsw_SRC}"
  control
  "src/control")
libra_component_register_as_src(
rcppsw_math_SRC
  rcppsw
  "${rcppsw_SRC}"
  math
  "src/math")
libra_component_register_as_src(
rcppsw_metrics_SRC
  rcppsw
  "${rcppsw_SRC}"
  metrics
  "src/metrics")
libra_component_register_as_src(
rcppsw_multiprocess_SRC
  rcppsw
  "${rcppsw_SRC}"
  multiprocess
  "src/multiprocess")
libra_component_register_as_src(
rcppsw_multithread_SRC
  rcppsw
  "${rcppsw_SRC}"
  multithread
  "src/multithread")
libra_component_register_as_src(
rcppsw_patterns_SRC
  rcppsw
  "${rcppsw_SRC}"
  patterns
  "src/patterns")
libra_component_register_as_src(
rcppsw_spatial_SRC
  rcppsw
  "${rcppsw_SRC}"
  spatial
  "src/spatial")
libra_component_register_as_src(
rcppsw_types_SRC
  rcppsw
  "${rcppsw_SRC}"
  types
  "src/types")
libra_component_register_as_src(
rcppsw_utils_SRC
  rcppsw
  "${rcppsw_SRC}"
  utils
  "src/utils")
libra_component_register_as_src(
  rcppsw_er_SRC
  rcppsw
  "${rcppsw_SRC}"
  er
  "src/er")
libra_component_register_as_src(
  rcppsw_init_SRC
  rcppsw
  "${rcppsw_SRC}"
  init
  "src/init")

# Root project (not used in find_package())
if (NOT rcppsw_FIND_COMPONENTS)
  set(rcppsw_FIND_COMPONENTS
    abi
    config
    control
    er
    init
    math
    metrics
    multiprocess
    multithread
    patterns
    spatial
    types
    utils
    )
endif()

libra_requested_components_check(rcppsw)

################################################################################
# External Projects
################################################################################

# ticpp
ExternalProject_Add(ticpp
  GIT_REPOSITORY https://github.com/wxFormBuilder/ticpp.git
  GIT_TAG master
  CONFIGURE_COMMAND ${CMAKE_COMMAND}
  -DCMAKE_BUILD_TYPE=RelWithDebInfo
  -DCMAKE_INSTALL_PREFIX=${LIBRA_DEPS_PREFIX}
  -DCMAKE_POSITION_INDEPENDENT_CODE=ON
  ../ticpp-src
  PATCH_COMMAND git apply ${CMAKE_CURRENT_SOURCE_DIR}/scripts/ticpp.patch || true
  BUILD_COMMAND make CFLAGS="-fPIC"
  INSTALL_COMMAND make install
  SOURCE_DIR ${CMAKE_BINARY_DIR}/ticpp-src
  BINARY_DIR ${CMAKE_BINARY_DIR}/ticpp-build
  )
add_library(ticpp_ticpp::ticpp_ticpp SHARED IMPORTED GLOBAL)
set_target_properties(ticpp_ticpp::ticpp_ticpp PROPERTIES
  IMPORTED_LOCATION ${LIBRA_DEPS_PREFIX}/lib/libticpp.a
  )

if (NOT ${LIBRA_RTD_BUILD})
  if(CMAKE_CROSSCOMPILING)
    set(BOOST_ROOT ${LIBRA_DEPS_PREFIX})
  endif()

  # set(Boost_USE_STATIC_LIBS        OFF)  # only find static libs
  set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
  set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
  # set(Boost_USE_MULTITHREADED      OFF)
  set(Boost_USE_STATIC_RUNTIME     OFF)
  find_package(Boost 1.71.0
    COMPONENTS
    system
    thread
    graph
    stacktrace_basic
    program_options
    REQUIRED)
endif()

find_package(rcsw)

find_package(log4cxx QUIET) # optional

# Cmake module only available with newer versions of log4cxx
if (NOT ${log4cxx_FOUND})
  set(RCPPSW_ER_OLD_LOG4CXX ON)
  message(STATUS "Found log4cxx < 0.12")
else()
  set(RCPPSW_ER_OLD_LOG4CXX OFF)
  message(STATUS "Found log4cxx >= 0.12")
endif()

################################################################################
# Libraries
################################################################################
# Create the source for the SINGLE library to build by combining the
# source of the selected components
foreach(component ${rcppsw_FIND_COMPONENTS})
  if(${rcppsw_${component}_FOUND})
    list(APPEND rcppsw_components_SRC ${rcppsw_} ${rcppsw_${component}_SRC})
  endif()
endforeach()

# Define RCPPSW library
set(rcppsw_LIBRARY rcppsw)
add_library(
  ${rcppsw_LIBRARY}
  ${RCPPSW_LIBTYPE}
  ${rcppsw_components_SRC}
  )

set_target_properties(${rcppsw_LIBRARY}
  PROPERTIES
  OUTPUT_NAME ${rcppsw_LIBRARY}
  )

# Setting this results in TWO files being installed: the actual
# library with the version embedded, and a symlink to the actual
# library with the same name sans the embedded version (if rcppsw is
# built as a shared library).
set_target_properties(${rcppsw_LIBRARY}
  PROPERTIES
  VERSION ${rcppsw_VERSION}
  SOVERSION ${rcppsw_VERSION}
  )

########################################
# Include directories
########################################
target_include_directories(
  ${rcppsw_LIBRARY}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${rcsw_INCLUDE_DIRS}>
  $<BUILD_INTERFACE:${LIBRA_DEPS_PREFIX}/include>
  $<INSTALL_INTERFACE:include>
  )
target_include_directories(
  ${rcppsw_LIBRARY}
  SYSTEM PUBLIC
  $<BUILD_INTERFACE:${LIBRA_DEPS_PREFIX}/include>
  $<BUILD_INTERFACE:${log4cxx_INCLUDE_DIR}>
  $<BUILD_INTERFACE:${Boost_INCLUDE_DIRS}>
  )

########################################
# Link Libraries
########################################
target_link_libraries(${rcppsw_LIBRARY}
  rcsw::rcsw
  ${Boost_LIBRARIES}
  pthread
  dl
  )

target_link_libraries(${rcppsw_LIBRARY}
  ticpp_ticpp::ticpp_ticpp
  )

########################################
# Compile Options/Definitions
########################################

if(${RCPPSW_AL_MT_SAFE_TYPES})
  target_compile_definitions(${rcppsw_LIBRARY} PUBLIC RCPPSW_AL_MT_SAFE_TYPES)
endif()

target_compile_definitions(${rcppsw_LIBRARY}
  PUBLIC
  LIBRA_ERL=LIBRA_ERL_${LIBRA_ERL}
)

target_compile_definitions(${rcppsw_LIBRARY}
  PUBLIC
  RCPPSW_ER_PLUGIN=RCPPSW_ER_PLUGIN_${RCPPSW_ER_PLUGIN}
)
target_compile_definitions(${rcppsw_LIBRARY}
  PUBLIC
  RCPPSW_ER_PLUGIN_PATH=${RCPPSW_ER_PLUGIN_PATH}
)

if (NOT "${LIBRA_ERL}" MATCHES "NONE")
  if("${RCPPSW_ER_PLUGIN}" MATCHES "LOG4CXX")
    if( ${RCPPSW_ER_OLD_LOG4CXX})
      target_compile_definitions(${rcppsw_LIBRARY} PUBLIC RCPPSW_ER_OLD_LOG4CXX)
    endif()
    target_link_libraries(${rcppsw_LIBRARY} log4cxx)  
  endif()
endif()

target_compile_definitions(${rcppsw_LIBRARY}
  INTERFACE
  LIBRA_ER=LIBRA_ER_${LIBRA_ER}
  )

################################################################################
# Installation and Deployment
################################################################################
# Installation
libra_configure_exports_as(${rcppsw_LIBRARY} ${CMAKE_INSTALL_PREFIX})
libra_register_target_for_install(${rcppsw_LIBRARY} ${CMAKE_INSTALL_PREFIX})
libra_register_headers_for_install(include/${rcppsw_LIBRARY} ${CMAKE_INSTALL_PREFIX})

# Deployment
if(NOT CPACK_PACKAGE_NAME)
  set(CPACK_PACKAGE_NAME ${rcppsw_LIBRARY})
endif()
libra_register_copyright_for_install(${CPACK_PACKAGE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/changelog)
  libra_register_changelog_for_install(${CPACK_PACKAGE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/changelog)
endif()

libra_configure_cpack(
  "DEB"
  "RCPPSW is a collection of reusable C++ software (design patterns, boost gaps,
etc.), independent of any C++ project."

  "John Harwell"
  "https://jharwell.github.io/rcppsw"
  "John Harwell <john.r.harwell@gmail.com>")


################################################################################
# Status
################################################################################
if(${RCPPSW_SUMMARY})
  message("")
  message("${BoldBlue}--------------------------------------------------------------------------------")
  message("${BoldBlue}                          RCPPSW Configuration Summary")
  message("${BoldBlue}--------------------------------------------------------------------------------")
  message("")


  set(fields
    RCPPSW_VERSION
    RCPPSW_LIBTYPE
    RCPPSW_AL_MT_SAFE_TYPES
    RCPPSW_ER_PLUGIN
    RCPPSW_ER_PLUGIN_PATH
  )
  libra_config_summary_prepare_fields("${fields}")

message(STATUS "Build version.........................: ${ColorBold}${EMIT_RCPPSW_VERSION}${ColorReset} [RCPPSW_VERSION]")
message(STATUS "Library type..........................: ${ColorBold}${EMIT_RCPPSW_LIBTYPE}${ColorReset} [RCPPSW_LIBTYPE={STATIC,SHARED}]")
message(STATUS "Enable std::atomic types..............: ${ColorBold}${EMIT_RCPPSW_AL_MT_SAFE_TYPES}${ColorReset} [RCPPSW_AL_MT_SAFE_TYPES]")
message(STATUS "Event reporting plugin................: ${ColorBold}${EMIT_RCPPSW_ER_PLUGIN}${ColorReset} [RCPPSW_ER_PLUGIN]")
message(STATUS "Event reporting custom plugin path....: ${ColorBold}${EMIT_RCPPSW_ER_PLUGIN_PATH}${ColorReset} [RCPPSW_ER_PLUGIN_PATH]")

message("")
message("${BoldBlue}--------------------------------------------------------------------------------${ColorReset}")

endif()
