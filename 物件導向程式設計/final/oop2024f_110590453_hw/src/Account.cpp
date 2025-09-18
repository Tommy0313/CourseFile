
#include "Account.hpp"

 Account::Account(std::string id, AccountType type) {
    this->id = id;
     this->type = type;
}


AccountType Account::GetAccountInfo() {
    return type;
}

std::string Account::GetUser() {
    return id;
}

int Account::GetTotal() {
    return money;
}

void Account::SetMoney(int money) {
    this->money = money;
}




