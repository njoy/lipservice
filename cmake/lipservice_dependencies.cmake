include( FetchContent )


########################################################################
# Forward declarations
########################################################################


########################################################################
# Declare project dependencies
########################################################################

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  http://github.com/njoy/ENDFtk
    GIT_TAG         origin/build/fetchcontent
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

FetchContent_Declare( utility
    GIT_REPOSITORY  http://github.com/njoy/utility
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
