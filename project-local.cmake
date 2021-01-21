################################################################################
# Configuration Options                                                        #
################################################################################
set(${target}_CHECK_LANGUAGE "CXX")

################################################################################
# External Projects                                                            #
################################################################################
# RCSW
add_subdirectory(ext/rcsw)

# TICPP, which emits hundreds of compiler warnings if I compile with my usual
# robust set of warnings.
if (NOT TARGET ticpp)
  add_subdirectory(ext/ticpp)
  target_compile_options(ticpp PRIVATE -Wno-old-style-cast -Wno-suggest-override
    -Wno-effc++ -Wno-overloaded-virtual -Wno-missing-declarations
    -Wno-suggest-attribute=const -Wno-suggest-attribute=pure
    -Wno-suggest-final-types -Wno-suggest-final-methods -Wno-switch-default)
endif()

# Boost
find_package(Boost 1.71.0 COMPONENTS system filesystem thread graph REQUIRED)
set(Boost_USE_STATIC_LIBS OFF)

################################################################################
# Includes                                                                     #
################################################################################
set(${target}_INCLUDE_DIRS
  ${${target}_INC_PATH}
  ${rcsw_INCLUDE_DIRS})
set(${target}_SYS_INCLUDE_DIRS
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

if ("${LIBRA_ER}" MATCHES "ALL")
  set(${target}_LIBRARIES ${${target}_LIBRARIES} log4cxx)
endif()

if (BUILD_FOR_MSI)
  set(${target}_LIBRARY_DIRS ${${target}_LIBRARY_DIRS})
endif()

if (NOT TARGET ${target})
  add_library(${target} STATIC ${${target}_SRC})
  target_link_libraries(${target} ${${target}_LIBRARIES})
  target_include_directories(${target} PUBLIC ${${target}_INCLUDE_DIRS})
  target_include_directories(${target} SYSTEM PRIVATE "${${target}_SYS_INCLUDE_DIRS}")
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
