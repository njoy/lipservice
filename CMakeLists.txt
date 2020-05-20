########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.16 )
project( lipservice LANGUAGES CXX )

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
