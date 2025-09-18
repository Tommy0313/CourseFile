#include "Money.hpp"
#include <gtest/gtest.h>


TEST(MoneyTest, TestTypeOOP) {
    Money money(MoneyType::OOP,10);

    ASSERT_EQ(MoneyType::OOP,money.GetType());
    ASSERT_EQ(10,money.GetAmount());
}
TEST(MoneyTest, TestTypePUA) {
    Money money(MoneyType::PUA,20);

    ASSERT_EQ(MoneyType::PUA,money.GetType());
    ASSERT_EQ(20,money.GetAmount());
}
TEST(MoneyTest, TestTypeFS) {
    Money money(MoneyType::FS,228922);

    ASSERT_EQ(MoneyType::FS,money.GetType());
    ASSERT_EQ(228922,money.GetAmount());
}
TEST(MoneyTest, TestTypeOOTD) {
    Money money(MoneyType::OOTD,114514);

    ASSERT_EQ(MoneyType::OOTD,money.GetType());
    ASSERT_EQ(114514,money.GetAmount());
}
TEST(MoneyTest, TestTypeTWP) {
    Money money(MoneyType::TWP,48763);

    ASSERT_EQ(MoneyType::TWP,money.GetType());
    ASSERT_EQ(48763,money.GetAmount());
}