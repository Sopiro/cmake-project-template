ExternalProject_Add(
    dep-muli
    GIT_REPOSITORY "https://github.com/Sopiro/Muli.git"
    GIT_TAG "master"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    TEST_COMMAND ""
    CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
    -DBUILD_DEMO_PROJECT=OFF
)

set(DEP_LIST_DEMO
    dep-muli
)

set(DEP_LIBS_DEMO
    muli
)