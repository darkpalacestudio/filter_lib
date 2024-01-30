file(GLOB_RECURSE TESTFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)
add_executable(filter_lib_test ${TESTFILES})

target_link_libraries(filter_lib_test PUBLIC
        filter_lib
        Catch2::Catch2WithMain
        ApprovalTests::ApprovalTests
)
