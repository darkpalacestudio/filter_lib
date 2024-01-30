message(STATUS "Add CPM.cmake")
# download CPM.cmake
file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.6/CPM.cmake
        ${CMAKE_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=11c3fa5f1ba14f15d31c2fb63dbc8628ee133d81c8d764caad9a8db9e0bacb07
)
include(${CMAKE_BINARY_DIR}/cmake/CPM.cmake)

message(STATUS "Fetching external libraries started")

if (FILTERLIB_ENABLE_TESTS)
    message(STATUS "Fetching catch2")
    CPMAddPackage(
            NAME catch2
            GITHUB_REPOSITORY catchorg/Catch2
            GIT_TAG v3.5.2
            OPTIONS
            CATCH_INSTALL_DOCS OFF
            CATCH_INSTALL_HELPERS OFF
            CATCH_BUILD_TESTING OFF
    )

    message(STATUS "Fetching approvaltests")
    CPMAddPackage(
            NAME approvaltests
            GITHUB_REPOSITORY approvals/ApprovalTests.cpp
            GIT_TAG master
    )
endif ()
