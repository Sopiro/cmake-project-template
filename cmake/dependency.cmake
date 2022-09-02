ExternalProject_Add(
    dep_spe
    GIT_REPOSITORY "https://github.com/Sopiro/SPE.git"
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
    dep_spe
)

set(DEP_LIBS_DEMO
    spe
)