#ifndef BUSINESS_ACCOUNT_HPP
#define BUSINESS_ACCOUNT_HPP

#include "Account.hpp"
#include <vector>
#include <stdexcept>

class BusinessAccount {
private:
public:
    BusinessAccount(std::string id,AccountType type);
    void Modify(Operation oper,MoneyType type,int amount);
};


#endif