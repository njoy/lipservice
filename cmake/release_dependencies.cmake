cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  https://github.com/njoy/catch-adapter
    GIT_TAG         fb84b82ebf7a4789aa43cea560680cf745c6ee4f
    )

FetchContent_Declare( disco
    GIT_REPOSITORY  https://github.com/njoy/disco
    GIT_TAG         a1a7ddb2c0f69465524d8640ee29988b714a881e
    )

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  https://github.com/njoy/ENDFtk
    GIT_TAG         b6618b396f51e802b7ee19ba529533c27e6ac302 # tag: v0.1.0
    )

FetchContent_Declare( hana-adapter
    GIT_REPOSITORY  https://github.com/njoy/hana-adapter
    GIT_TAG         f58e8973c9a614dc4f3720b5581a762c61bdbb40
    )

FetchContent_Declare( header-utilities
    GIT_REPOSITORY  https://github.com/njoy/header-utilities
    GIT_TAG         cc2610fee15e255c151e8e22aca1e8b3d1a96b39
    )

FetchContent_Declare( Log
    GIT_REPOSITORY  https://github.com/njoy/Log
    GIT_TAG         52962b7796afe37ef1d8f7edb4bf9ecb1b868d15
    )

FetchContent_Declare( nlohmann_json
    GIT_REPOSITORY  https://github.com/nlohmann/json
    GIT_TAG         e7b3b40b5a95bc74b9a7f662830a27c49ffc01b4 # tag: v3.7.3
    )
set(JSON_BuildTests OFF CACHE INTERNAL "")

FetchContent_Declare( range-v3-adapter
    GIT_REPOSITORY  https://github.com/njoy/range-v3-adapter
    GIT_TAG         252679d4737c8f755d87c0e1eed6c37394a2ec59
    )

FetchContent_Declare( spdlog
    GIT_REPOSITORY  https://github.com/gabime/spdlog
    GIT_TAG         a51b4856377a71f81b6d74b9af459305c4c644f8
    )
set( SPDLOG_BUILD_TESTING CACHE BOOL OFF )

FetchContent_Declare( utility
    GIT_REPOSITORY  https://github.com/njoy/utility
    GIT_TAG         4e72b708d153450bdbc7fc2b45651d71f9a183dc
    )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    catch-adapter
    disco
    ENDFtk
    hana-adapter
    header-utilities
    Log
    nlohmann_json
    range-v3-adapter
    spdlog
    utility
    )
