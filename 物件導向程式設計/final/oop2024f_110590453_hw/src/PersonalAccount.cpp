//
// Created by User on 2024/12/27.
//

#include "PersonalAccount.hpp"

#include <stdexcept>

 PersonalAccount::PersonalAccount(std::string id, AccountType type,
                                 MoneyType AccountMoneyType):Account(id,type) {
    this->moneytype = AccountMoneyType;
}

MoneyType PersonalAccount::GetMoneyInfo() {
    return moneytype;
}

void PersonalAccount::Modify(Operation oper, MoneyType type, int amount) {
     if(type != moneytype) throw std::invalid_argument("");
     if(oper == Operation::Deposit) {
        SetMoney(GetTotal()+amount);
     }
     else {
         if(amount>GetTotal())throw std::out_of_range("");
         else {
            SetMoney(GetTotal()-amount);
         }
     }
}


