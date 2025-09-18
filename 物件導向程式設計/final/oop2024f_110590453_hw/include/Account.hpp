#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include "Money.hpp"

enum class AccountType{
    Personal,
    Business
};
enum class Operation{
    Withdraw,
    Deposit
};
class Account{
protected:
    int money = 0;
    std::string id;
    AccountType type;
public:
    Account(std::string id,AccountType type);
    virtual ~Account() = default;
    int GetTotal();
    std::string GetUser();
    AccountType GetAccountInfo();
    virtual MoneyType GetMoneyInfo() = 0;
    void SetMoney(int money);
    virtual void Modify(Operation oper,MoneyType type,int amount) = 0;
};
#endif