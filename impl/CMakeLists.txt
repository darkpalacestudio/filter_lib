file(GLOB_RECURSE FILTER_LIB_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_library(filter_lib ${FILTER_LIB_FILES})
set_target_properties(filter_lib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(filter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    target_compile_options(filter_lib PRIVATE "/W4")
    target_compile_options(filter_lib PUBLIC "/EHsc")
else ()
    target_compile_options(filter_lib PRIVATE "-Wall")
    target_compile_options(filter_lib PRIVATE "-Wextra")
    target_compile_options(filter_lib PRIVATE "-fpermissive")
endif ()
