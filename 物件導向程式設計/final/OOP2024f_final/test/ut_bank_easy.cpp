#include "Bank.hpp"
#include "Checker.cpp"
#include <gtest/gtest.h>

Checker checker;

TEST(BankEZPart,CanCalculateMoney){
    Bank bank("2024-12-25");
    auto tmp = bank.Calculator(1400,MoneyType::OOP);
    ASSERT_EQ(checker.check(tmp),1400);
    ASSERT_EQ(tmp[0].GetType(),MoneyType::OOP);
}
TEST(BankEZPart,CanExchangeMoney){
    Bank bank("2024-12-25");
    std::vector<Money> a;
    for(int i=0;i<5;i++){
        a.push_back(Money(MoneyType::OOP,500));
    }
    for(int i=0;i<5;i++){
        a.push_back(Money(MoneyType::OOP,50));
    }
    auto tmp = bank.Exchange(a,MoneyType::FS);
    ASSERT_EQ(checker.check(tmp),1375);
    ASSERT_EQ(tmp[0].GetType(),MoneyType::FS);
}
TEST(BankEZPart,CannotChangeTime){
    Bank bank("2024-12-25");
    auto first = bank.GetTime();

    bank.UpdateTime("2024-12-24");

    ASSERT_EQ(first,bank.GetTime());
}
TEST(BankEZPart,CanChangeTime){
    Bank bank("2024-12-25");
    auto first = bank.GetTime();

    bank.UpdateTime("2025-12-24");

    ASSERT_EQ("2025-12-24",bank.GetTime());
}