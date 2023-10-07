#include "include/three.h"

#include <gtest/gtest.h>

TEST(test_01, defaultConstructor)
{
    Three t;
    std::string s;
    t.convertToString(s);
    EXPECT_TRUE(s == "");
}

TEST(test_01, fillConstructor)
{
    Three t(3);
    std::string s;
    t.convertToString(s);
    EXPECT_TRUE(s == "000");
}

TEST(test_01, fillConstructor2)
{
    Three t(3, '2');
    std::string s;
    t.convertToString(s);
    EXPECT_TRUE(s == "222");
}

TEST(test_01, initializerListConstructor)
{
    Three t{'2', '0', '1'};
    std::string s;
    t.convertToString(s);
    EXPECT_TRUE(s == "201");
}

TEST(test_01, copyStringConstructor)
{
    Three t("201");
    std::string s;
    t.convertToString(s);
    EXPECT_TRUE(s == "201");
}

TEST(test_01, copyConstructor)
{
    Three t{'2', '0', '1'};
    Three t2(t);
    std::string s;
    t2.convertToString(s);
    EXPECT_TRUE(s == "201");
}

TEST(test_01, moveConstructor)
{
    Three t1{'2', '0', '1'};
    Three t2{'1', '1'};
    Three t3(t1.sum(t2));
    std::string s;
    t3.convertToString(s);
    EXPECT_TRUE(s == "212");
}

TEST(test_02, thorwFillConstructor)
{
    ASSERT_THROW(Three t(1, '3'), std::underflow_error);
}

TEST(test_02, throwInitializerListConstructor)
{
    
    ASSERT_THROW(Three t{'3'}, std::underflow_error);
}

TEST(test_02, throwCopyStringConstructor)
{    
    EXPECT_THROW(Three t("3"), std::underflow_error);
}

TEST(test_03, equal)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '0', '1'};

    ASSERT_TRUE(t1.equals(t2) == true);
}

TEST(test_03, equalDifferentLength)
{
    Three t1 {'1', '0'};
    Three t2 {'1', '0', '1'};

    ASSERT_TRUE(t1.equals(t2) == false);
}

TEST(test_03, equalDifferentValues)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '0', '0'};

    ASSERT_TRUE(t1.equals(t2) == false);
}

TEST(test_04, moreForEquals)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '0', '1'};

    ASSERT_TRUE(t1.more(t2) == false);
}

TEST(test_04, more)
{
    Three t1 {'1', '1', '0'};
    Three t2 {'1', '0', '1'};

    ASSERT_TRUE(t1.more(t2) == true);
}

TEST(test_04, moreDifferentLength)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '0'};

    ASSERT_TRUE(t1.more(t2) == true);
}

TEST(test_05, lessForEquals)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '0', '1'};

    ASSERT_TRUE(t1.less(t2) == false);
}

TEST(test_05, less)
{
    Three t1 {'1', '1', '0'};
    Three t2 {'1', '0', '1'};

    ASSERT_TRUE(t1.less(t2) == false);
}

TEST(test_05, lessDifferentLength)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '0'};

    ASSERT_TRUE(t1.less(t2) == false);
}

TEST(test_06, sum)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '1', '0'};
    Three t3 {'2', '1', '1'};

    ASSERT_TRUE(t1.sum(t2).equals(t3));
}

TEST(test_06, sum2)
{
    Three t2 {'1', '0', '1'};
    Three t1 {'1', '1', '0'};
    Three t3 {'2', '1', '1'};

    ASSERT_TRUE(t1.sum(t2).equals(t3));
}

TEST(test_06, sumDifferentLength)
{
    Three t1 {'1', '0', '1', '1'};
    Three t2 {'1', '1', '0'};
    Three t3 {'1', '1', '2', '1'};

    ASSERT_TRUE(t1.sum(t2).equals(t3));
}

TEST(test_06, sumDifferentLength2)
{
    Three t2 {'1', '0', '1', '1'};
    Three t1 {'1', '1', '0'};
    Three t3 {'1', '1', '2', '1'};

    ASSERT_TRUE(t1.sum(t2).equals(t3));
}

TEST(test_06, sumOver)
{
    Three t1 {'2'};
    Three t2 {'2'};
    Three t3 {'1', '1'};

    ASSERT_TRUE(t1.sum(t2).equals(t3));
}

TEST(test_06, sumOver2)
{
    Three t1 {'2', '1', '2'};
    Three t2 {'1'};
    Three t3 {'2', '2', '0'};

    ASSERT_TRUE(t1.sum(t2).equals(t3));
}

TEST(test_06, sumZero)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'0'};

    ASSERT_TRUE(t1.sum(t2).equals(t1));
}

TEST(test_06, sumZero2)
{
    Three t2 {'2', '1', '1'};
    Three t1 {'0'};

    ASSERT_TRUE(t1.sum(t2).equals(t2));
}

TEST(test_07, add)
{
    Three t1 {'1', '0', '1'};
    Three t2 {'1', '1', '0'};
    Three t3 {'2', '1', '1'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, add2)
{
    Three t2 {'1', '0', '1'};
    Three t1 {'1', '1', '0'};
    Three t3 {'2', '1', '1'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, addDifferentLength)
{
    Three t1 {'1', '0', '1', '1'};
    Three t2 {'1', '1', '0'};
    Three t3 {'1', '1', '2', '1'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, addDifferentLength2)
{
    Three t2 {'1', '0', '1', '1'};
    Three t1 {'1', '1', '0'};
    Three t3 {'1', '1', '2', '1'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, addOver)
{
    Three t1 {'2'};
    Three t2 {'2'};
    Three t3 {'1', '1'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, addOver2)
{
    Three t1 {'2', '1', '2'};
    Three t2 {'1'};
    Three t3 {'2', '2', '0'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, addOver3)
{
    Three t2 {'2', '1', '2'};
    Three t1 {'1'};
    Three t3 {'2', '2', '0'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, addZero)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'0'};
    Three t3 {'2', '1', '1'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_07, addZero2)
{
    Three t2 {'2', '1', '1'};
    Three t1 {'0'};
    Three t3 {'2', '1', '1'};

    t1.add(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_08, subtractionError)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'1', '1', '1', '1'};

    EXPECT_THROW(t1.subtraction(t2), std::underflow_error);
}

TEST(test_08, subtractionError2)
{
    Three t1 {'1', '1', '1'};
    Three t2 {'2', '1', '1'};

    EXPECT_THROW(t1.subtraction(t2), std::underflow_error);
}

TEST(test_08, subtraction)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'1', '1', '1'};
    Three t3 {'1', '0', '0'};

    ASSERT_TRUE(t1.subtraction(t2).equals(t3));
}

TEST(test_08, subtractionExtra)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'1', '2', '1'};
    Three t3 {'2', '0'};

    ASSERT_TRUE(t1.subtraction(t2).equals(t3));
}

TEST(test_08, subtractionExtra2)
{
    Three t1 {'1', '0', '0'};
    Three t2 {'1'};
    Three t3 {'2', '2'};

    ASSERT_TRUE(t1.subtraction(t2).equals(t3));
}

TEST(test_08, subtractionZero)
{
    Three t1 {'1', '0', '0'};
    Three t2 {'0'};

    ASSERT_TRUE(t1.subtraction(t2).equals(t1));
}

TEST(test_08, subtractionAll)
{
    Three t1 {'1', '0', '0'};
    Three t2 {'0'};

    ASSERT_TRUE(t1.subtraction(t1).equals(t2));
}

TEST(test_09, removeError)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'1', '1', '1', '1'};

    EXPECT_THROW(t1.remove(t2), std::underflow_error);
}

TEST(test_09, removeError2)
{
    Three t1 {'1', '1', '1'};
    Three t2 {'2', '1', '1'};

    EXPECT_THROW(t1.remove(t2), std::underflow_error);
}

TEST(test_09, remove)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'1', '1', '1'};
    Three t3 {'1', '0', '0'};

    t1.remove(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_09, removeExtra)
{
    Three t1 {'2', '1', '1'};
    Three t2 {'1', '2', '1'};
    Three t3 {'2', '0'};

    t1.remove(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_09, removeExtra2)
{
    Three t1 {'1', '0', '0'};
    Three t2 {'1'};
    Three t3 {'2', '2'};

    t1.remove(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_09, removeZero)
{
    Three t1 {'1', '0', '0'};
    Three t2 {'0'};
    Three t3 {'1', '0', '0'};

    t1.remove(t2);

    ASSERT_TRUE(t1.equals(t3));
}

TEST(test_09, removeAll)
{
    Three t1 {'1', '0', '0'};
    Three t2 {'0'};

    t1.remove(t1);

    ASSERT_TRUE(t1.equals(t2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
