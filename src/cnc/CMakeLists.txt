make_static_shared_lib(
    NAME cnc
    CSTANDARD ${CSTANDARD}
    HEADERS ${COMMAND_DIR}
    SOURCES InputParser.cpp
    DEPS fmt utility
    SRC_GROUP_FILES "${COMMAND_DIR}")
