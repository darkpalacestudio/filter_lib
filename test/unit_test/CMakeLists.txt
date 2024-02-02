file(GLOB_RECURSE TESTFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)
add_executable(filter_lib_unit_test ${TESTFILES})
target_link_libraries(filter_lib_unit_test gtest_main filter_lib)
