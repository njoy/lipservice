########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.14 )
project( lipservice LANGUAGES CXX )

########################################################################
# Project-wide setup
########################################################################

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

option( lipservice_unit_tests
    "Compile the ENDFtk unit tests and integrate with ctest" ON
    )

########################################################################
# Dependencies
########################################################################

include( cmake/lipservice_dependencies.cmake )

########################################################################
# Project targets
########################################################################

add_library( lipservice INTERFACE )
target_include_directories( lipservice INTERFACE src/ )
target_link_libraries( lipservice
    INTERFACE ENDFtk
    INTERFACE catch-adapter
    INTERFACE hana-adapter
    INTERFACE json-adapter
    INTERFACE utility
    )

#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    # unit testing
    if( lipservice_unit_tests )
        include( cmake/unit_testing.cmake )
    endif()

endif()
