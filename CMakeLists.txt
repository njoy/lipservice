project( lipservice )

if( NOT DEFINED lipservice_DEPENDENCIES )
    set( lipservice_DEPENDENCIES TRUE )
endif()

add_library( lipservice INTERFACE )
target_include_directories( lipservice INTERFACE src/ )
target_link_libraries( lipservice INTERFACE ENDFtk INTERFACE catch-adapter INTERFACE hana-adapter INTERFACE json-adapter INTERFACE utility )
