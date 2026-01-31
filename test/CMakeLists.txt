include_directories(unity/src ../inc)

add_executable(sanity_tests 
    test_sanity.c 
    unity/src/unity.c 
    ../src/util.c
)

add_test(NAME SanityTests COMMAND sanity_tests)
set(CTEST_OUTPUT_ON_FAILURE ON)