################################################################################
# Configuration Options                                                        #
################################################################################
# We might be linking with a shared library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(rcppsw_CHECK_LANGUAGE "CXX")

# Each conference tag=minor increment. Each minor feature added=patch increment.
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 3)
set(PROJECT_VERSION_PATCH 0)

if (NOT DEFINED RCPPSW_AL_MT_SAFE_TYPES)
  set(RCPPSW_AL_MT_SAFE_TYPES YES)
endif()

if (NOT DEFINED RCPPSW_ER_OLD_LOG4CXX)
  set(RCPPSW_ER_OLD_LOG4CXX OFF)
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
component_register_as_src(
  rcppsw_init_SRC
  rcppsw
  "${rcppsw_SRC}"
  init
  "src/init")

# Root project (not used in find_package())
if (NOT rcppsw_FIND_COMPONENTS)
  set(rcppsw_FIND_COMPONENTS
    config
    control
    er
    init
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
# ticpp
add_library(ticpp_ticpp::ticpp_ticpp STATIC IMPORTED GLOBAL)
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

# Configure version
execute_process(COMMAND git rev-list --count HEAD
  OUTPUT_VARIABLE RCPPSW_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/src/version.cpp
  @ONLY
  )
list(APPEND rcppsw_components_SRC "${CMAKE_CURRENT_BINARY_DIR}/src/version.cpp")

# Define RCPPSW library
set(rcppsw_LIBRARY rcppsw)
add_library(
  ${rcppsw_LIBRARY}
  STATIC
  ${rcppsw_components_SRC}
  )


set(rcppsw_LIBRARY_NAME ${rcppsw_LIBRARY})
set_target_properties(${rcppsw_LIBRARY} PROPERTIES OUTPUT_NAME ${rcppsw_LIBRARY_NAME})

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
  ticpp_ticpp::ticpp_ticpp
  ${Boost_LIBRARIES}
  pthread
  dl
  )

########################################
# Compile Options/Definitions
########################################

if(${RCPPSW_AL_MT_SAFE_TYPES})
  target_compile_definitions(${rcppsw_LIBRARY} PUBLIC RCPPSW_AL_MT_SAFE_TYPES)
endif()

if ("${LIBRA_ER}" MATCHES "ALL")
  if(NOT ${RCPPSW_ER_OLD_LOG4CXX})
    target_link_directories(${rcppsw_LIBRARY} PUBLIC ${LIBRA_DEPS_PREFIX}/lib)
  else()
    target_compile_definitions(${rcppsw_LIBRARY} PUBLIC RCPPSW_ER_OLD_LOG4CXX)
  endif()
  target_link_libraries(${rcppsw_LIBRARY} log4cxx)
endif()

target_compile_definitions(${rcppsw_LIBRARY}
  INTERFACE
  LIBRA_ER=LIBRA_ER_${LIBRA_ER}
  )

################################################################################
# Installation                                                                 #
################################################################################
configure_exports_as(${rcppsw_LIBRARY} ${CMAKE_INSTALL_PREFIX})

# Install rcppsw
register_target_for_install(${rcppsw_LIBRARY} ${CMAKE_INSTALL_PREFIX})
register_headers_for_install(include/${rcppsw_LIBRARY} ${CMAKE_INSTALL_PREFIX})

################################################################################
# Status                                                                       #
################################################################################
libra_config_summary()

message(STATUS "")
message(STATUS "")
message(STATUS "RCPPSW Configuration Summary:")
message(STATUS "")

message(STATUS "Enable std::atomic types..............: RCPPSW_AL_MT_SAFE_TYPES=${RCPPSW_AL_MT_SAFE_TYPES}")
message(STATUS "Use old log4cxx.......................: RCPPSW_ER_OLD_LOG4CXX=${RCPPSW_ER_OLD_LOG4CXX}" )

if(CMAKE_CROSSCOMPILING)
  message(STATUS "Boost root hint.......................: BOOST_ROOT=${BOOST_ROOT}")
endif()
