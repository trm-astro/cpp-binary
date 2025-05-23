cmake_minimum_required(VERSION 3.23)
project(cpp-binary)

include(ExternalProject)

message("\nCMakeLists.txt for cpp-binary")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

set(PACKAGE_NAME binary)

############################################################
# Define sources
############################################################

set(SOURCES
    src/eclipses.cc
    src/orbital_ang_mom.cc
    src/rcirc.cc
    src/jdotgr.cc
    src/mr_main_sequence.cc
    src/orbital_omega.cc
    src/rmin.cc
    src/kepler_omega.cc
    src/mr_wd_eggleton.cc
    src/orbital_period.cc
    src/zeta_wd_eggleton.cc
    src/mr_wd_nauenberg.cc
    src/orbital_separation.cc
    src/zeta_main_sequence.cc
    src/zeta_wd_nauenberg.cc
    src/gyrate.cc
    src/vellipse.cc
)

############################################################
# Check for and install dependencies
############################################################

# Configure the PLPLOT library
if(NOT DEFINED CMAKE_COMMON)
    set(CMAKE_COMMON ${PROJECT_SOURCE_DIR}/../../cmake_common)
endif()
if(NOT DEFINED PLPLOT_FOUND)
    include("${CMAKE_COMMON}/plplot_install.cmake")
endif()

############################################################
# Define the library
############################################################
add_library(${PACKAGE_NAME} SHARED 
    ${SOURCES}
)

target_include_directories(${PACKAGE_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${PLPLOT_INCLUDE_DIR}
)

target_link_libraries(${PACKAGE_NAME}
    PUBLIC 
        subs
        # potentially link plplot here too
)

# Set RPATH properties
# set_target_properties(${PACKAGE_NAME} PROPERTIES
#     INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
#     INSTALL_RPATH_USE_LINK_PATH TRUE
# )

############################################################
# Create an executable
############################################################

# No executable in this code, this is a library

############################################################
# Install
############################################################
include("${CMAKE_COMMON}/install_lib.cmake") # Get the generic install function

install_lib(${PACKAGE_NAME})

message("cpp-binary CMakeLists.txt complete\n")