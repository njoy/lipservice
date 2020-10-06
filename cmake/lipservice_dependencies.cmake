include( FetchContent )


########################################################################
# Forward declarations
########################################################################


########################################################################
# Declare project dependencies
########################################################################

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  http://github.com/njoy/ENDFtk
    GIT_TAG         origin/feature/guards
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  http://github.com/njoy/catch-adapter
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( hana-adapter
    GIT_REPOSITORY  http://github.com/njoy/hana-adapter
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( json-adapter
    GIT_REPOSITORY  http://github.com/njoy/json-adapter
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( header-utilities
    GIT_REPOSITORY  https://github.com/njoy/header-utilities
    GIT_TAG         origin/build/fetchcontent-guards
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( utility
    GIT_REPOSITORY  http://github.com/njoy/utility
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( range-v3-adapter
    GIT_REPOSITORY  https://github.com/njoy/range-v3-adapter
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )



########################################################################
# Load dependencies
########################################################################

FetchContent_MakeAvailable(
    ENDFtk
    catch-adapter
    hana-adapter
    json-adapter
    utility
    )
