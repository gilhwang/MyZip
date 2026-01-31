file(GLOB SOURCES "*.c")
string(LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_PATH_LEN)
add_compile_options("-D__RELATIVE_FILE__=&__FILE__[${SOURCE_PATH_LEN}]")

add_executable(mzip ${SOURCES})
target_compile_definitions(mzip PRIVATE $<$<CONFIG:Debug>:DEBUG>)

# target_link_libraries(mzip PRIVATE m)