set(HEADER_FILES
    ../include/test/test.h
)
set(SOURCE_FILES
    main.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "src" FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../include" PREFIX "include" FILES ${HEADER_FILES})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../extern
)

find_package(OpenMP REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC
    OpenMP::OpenMP_CXX
    muli
)
