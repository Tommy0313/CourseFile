
include(FetchContent)

# GTest
option(FETCH_GOOGLETEST "Download googletest source" ON)
if(FETCH_GOOGLETEST)
    FetchContent_Declare(
        googletest
        # TODO: modify to URL and URL_HASH
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
else()
    # reference: https://cmake.org/cmake/help/latest/module/FindGTest.html
    find_package(GTest REQUIRED)
endif()

