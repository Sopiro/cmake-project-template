add_executable(test
    test.cpp
)

set_target_properties(test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    test.cpp
)

target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

find_package(OpenMP REQUIRED)
target_link_libraries(test PUBLIC doctest OpenMP::OpenMP_CXX)
    