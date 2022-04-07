set(DEFAULT_CXX_FLAGS -Werror -Wall -Wextra -pedantic)
set(REL_CXX_FLAGS -O3 -DNDEBUG)
set(LIB_CXX_FLAGS -fPIC -g)

make_static_shared_lib(
    NAME cnc
    CSTANDARD ${CSTANDARD}
    HEADERS ${COMMAND_DIR}
    SOURCES InputParser.cpp
    DEPS fmt utility
    SRC_GROUP_FILES "${COMMAND_DIR}")

target_compile_options(cnc PRIVATE ${DEFAULT_CXX_FLAGS} ${REL_CXX_FLAGS} ${LIB_CXX_FLAGS})
