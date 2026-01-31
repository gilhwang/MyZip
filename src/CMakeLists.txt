file(GLOB SOURCES "*.c")

add_executable(mzip ${SOURCES})

# target_link_libraries(mzip PRIVATE m)