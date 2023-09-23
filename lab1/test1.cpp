#include <gtest/gtest.h>
#include "convert.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(convert(0)=="sıfır");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(convert(1)=="bir");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(convert(2)=="iki");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(convert(3)=="üç");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(convert(4)=="dört");
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(convert(5)=="beş");
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(convert(6)=="altı");
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(convert(7)=="yedi");
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(convert(8)=="sekiz");
}

TEST(test_10, basic_test_set)
{
    ASSERT_TRUE(convert(9)=="dokuz");
}

TEST(test_11, basic_test_set)
{
    ASSERT_TRUE(convert(10)=="on");
}

TEST(test_12, basic_test_set)
{
    ASSERT_TRUE(convert(20)=="yirmi");
}

TEST(test_13, basic_test_set)
{
    ASSERT_TRUE(convert(30)=="otuz");
}

TEST(test_14, basic_test_set)
{
    ASSERT_TRUE(convert(40)=="kırk");
}

TEST(test_15, basic_test_set)
{
    ASSERT_TRUE(convert(50)=="elli");
}

TEST(test_16, basic_test_set)
{
    ASSERT_TRUE(convert(60)=="altmış");
}

TEST(test_17, basic_test_set)
{
    ASSERT_TRUE(convert(70)=="yetmiş");
}

TEST(test_18, basic_test_set)
{
    ASSERT_TRUE(convert(80)=="seksen");
}

TEST(test_19, basic_test_set)
{
    ASSERT_TRUE(convert(90)=="doksan");
}

TEST(test_20, basic_test_set)
{
    ASSERT_TRUE(convert(99)=="doksan dokuz");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
