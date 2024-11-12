cmake_minimum_required(VERSION 3.23)
project(cpp-binary)

include(ExternalProject)

message("CMakeLists.txt for cpp-subs")
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
# Define the library
############################################################
add_library(${PACKAGE_NAME} SHARED 
    ${SOURCES}
)

target_include_directories(${PACKAGE_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

############################################################
# Check for and install dependencies
############################################################

include("${CMAKE_BINARY_DIR}/Release/generators/conan_toolchain.cmake")

# Configure the PLPLOT library

include("${CMAKE_SOURCE_DIR}/../../cmake_common/plplot_install.cmake")

find_package(SOFA REQUIRED)
find_package(PCRE2 REQUIRED)
find_package(SUBS REQUIRED)

if (NOT SOFA_FOUND)
    message(FATAL_ERROR "SOFA library not found.")
endif()
if (NOT PCRE2_FOUND)
    message(FATAL_ERROR "PCRE2 library not found.")
endif()
if (NOT PLPLOT_FOUND)
    message(FATAL_ERROR "PLPLOT library not found.")
endif()
if (NOT SUBS_FOUND)
    message(FATAL_ERROR "SUBS library not found.")
endif()

target_include_directories(${PACKAGE_NAME}
    PUBLIC 
        $<BUILD_INTERFACE:${PLPLOT_INCLUDE_DIR}>
)
target_link_libraries(${PACKAGE_NAME} 
    PUBLIC 
        sofa::sofa 
        pcre2::pcre2
        ${PLPLOT_LIB_DIR}/libplplotcxx.dylib
        subs::subs
)


############################################################
# Install
############################################################

# Library
# Note: may not work on windows
# Specify where the library binary will go
install(TARGETS ${PACKAGE_NAME}
    EXPORT ${PACKAGE_NAME}Targets              # Export the library target for package config
    LIBRARY DESTINATION lib              # For shared libraries
    ARCHIVE DESTINATION lib              # For static libraries
    RUNTIME DESTINATION bin              # For executables (if any)
    INCLUDES DESTINATION include         # Where to put public headers
)

# Header files
install(DIRECTORY include/ 
    DESTINATION include
)

# # Create and install CMake package configuration files
include(CMakePackageConfigHelpers)

# # Configure the version file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME}ConfigVersion.cmake"
    VERSION 0.1
    COMPATIBILITY AnyNewerVersion
)

configure_file(binaryConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME}Config.cmake"
    @ONLY
)

# # Install the config files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME}ConfigVersion.cmake"
    DESTINATION lib/cmake/${PACKAGE_NAME}
)

# # Export the library target so other projects can import it
install(EXPORT ${PACKAGE_NAME}Targets
    FILE ${PACKAGE_NAME}Targets.cmake
    NAMESPACE binary::
    DESTINATION lib/cmake/${PACKAGE_NAME}
)