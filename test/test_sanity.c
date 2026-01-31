#include "unity.h"
#include "mzip/util.h"

// Before test
void setUp(void) {}

// After test
void tearDown(void) {}

void test_is_zero(void)
{
    int num = 0;
    TEST_ASSERT_EQUAL_INT(is_zero(num), 1);
    int anotherNum = 5;
    TEST_ASSERT_EQUAL_INT(is_zero(anotherNum), 0);
} 

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_is_zero);
    return UNITY_END();
}