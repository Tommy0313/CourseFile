#include "PersonalAccount.hpp"
#include "BusinessAccount.hpp"
#include <gtest/gtest.h>

TEST(AccountTest, BusinessAccountAccountShouldHaveCorrectInfo) {
    BusinessAccount ba("Never Gonna Give You Up",AccountType::Business);

    ASSERT_EQ(ba.GetUser(),"Never Gonna Give You Up");
    ASSERT_EQ(ba.GetTotal(),0);
    ASSERT_EQ(ba.GetAccountInfo(),AccountType::Business);
}
TEST(AccountTest, BusinessAccountAccountCanDepositMoney) {
    BusinessAccount ba("Never Gonna Give You Up",AccountType::Business);

    ba.Modify(Operation::Deposit,MoneyType::FS,2000);
    ba.Modify(Operation::Deposit,MoneyType::OOP,8763);
    ba.Modify(Operation::Deposit,MoneyType::PUA,2000);
    ba.Modify(Operation::Deposit,MoneyType::OOTD,2000);
    ba.Modify(Operation::Deposit,MoneyType::TWP,2000);
    ASSERT_EQ(ba.GetTotal(),48763);
}
TEST(AccountTest, BusinessAccountAccountCanWithdrawMoney) {
    BusinessAccount ba("Never Gonna Give You Up",AccountType::Business);

    ba.Modify(Operation::Deposit,MoneyType::FS,2000);
    ba.Modify(Operation::Deposit,MoneyType::OOP,8763);
    ba.Modify(Operation::Deposit,MoneyType::PUA,2000);
    ba.Modify(Operation::Deposit,MoneyType::OOTD,2000);
    ba.Modify(Operation::Deposit,MoneyType::TWP,2000);

    ba.Modify(Operation::Withdraw,MoneyType::FS,10000);

    ASSERT_EQ(ba.GetTotal(),28763);
}
TEST(AccountTest, BusinessAccountAccountWithdrawMoneyThrowExcept) {
    BusinessAccount ba("Never Gonna Give You Up",AccountType::Business);

    ba.Modify(Operation::Deposit,MoneyType::FS,2000);

    ASSERT_THROW(ba.Modify(Operation::Withdraw,MoneyType::FS,10000), std::out_of_range);
    ASSERT_THROW(ba.Modify(Operation::Withdraw,MoneyType::OOTD,10000), std::out_of_range);
    ASSERT_THROW(ba.Modify(Operation::Withdraw,MoneyType::OOP,10000), std::out_of_range);
    ASSERT_THROW(ba.Modify(Operation::Withdraw,MoneyType::TWP,10000), std::out_of_range);
    ASSERT_THROW(ba.Modify(Operation::Withdraw,MoneyType::PUA,10000), std::out_of_range);
}

TEST(AccountTest,PersonalAccountBasicInfo){
    PersonalAccount pa("Rick",AccountType::Personal,MoneyType::OOTD);

    ASSERT_EQ(pa.GetMoneyInfo(),MoneyType::OOTD);
    ASSERT_EQ(pa.GetTotal(),0);
    ASSERT_EQ(pa.GetUser(),"Rick");
    ASSERT_EQ(pa.GetAccountInfo(),AccountType::Personal);
}

TEST(AccountTest, PersonalAccountCanDepositMoney) {
    PersonalAccount pa("Rick",AccountType::Personal,MoneyType::OOTD);

    pa.Modify(Operation::Deposit,MoneyType::OOTD,48763);

    ASSERT_EQ(pa.GetTotal(),48763);
}
TEST(AccountTest, PersonalAccountDepositMoneywithExcept) {
    PersonalAccount pa("Rick",AccountType::Personal,MoneyType::OOTD);

    ASSERT_THROW(pa.Modify(Operation::Deposit,MoneyType::PUA,48763), std::invalid_argument);
}

TEST(AccountTest, PersonalAccountCanWithdrawMoney) {
    PersonalAccount pa("Rick",AccountType::Personal,MoneyType::OOTD);

    pa.Modify(Operation::Deposit,MoneyType::OOTD,48763);
    pa.Modify(Operation::Withdraw,MoneyType::OOTD,1000);

    ASSERT_EQ(pa.GetTotal(),47763);
}
TEST(AccountTest, PersonalAccountWithdrawMoneywithExcept) {
    PersonalAccount pa("Rick",AccountType::Personal,MoneyType::OOTD);

    ASSERT_THROW(pa.Modify(Operation::Withdraw,MoneyType::OOTD,48763), std::out_of_range);
}
TEST(AccountTest, PersonalAccountWithdrawMoneyWithExcept) {
    PersonalAccount pa("Rick",AccountType::Personal,MoneyType::OOTD);

    ASSERT_THROW(pa.Modify(Operation::Withdraw,MoneyType::PUA,48763), std::invalid_argument);
}