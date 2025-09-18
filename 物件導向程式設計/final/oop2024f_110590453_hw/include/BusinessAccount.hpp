#ifndef BUSINESS_ACCOUNT_HPP
#define BUSINESS_ACCOUNT_HPP

#include "Account.hpp"
#include <vector>
#include <stdexcept>

class BusinessAccount:public Account{
private:
    MoneyType moneytype = MoneyType::OOP;
public:
    BusinessAccount(std::string id,AccountType type);
    MoneyType GetMoneyInfo() override;
    void Modify(Operation oper,MoneyType type,int amount) override;
};


#endif