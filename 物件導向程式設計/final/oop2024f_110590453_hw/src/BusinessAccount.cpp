#include "BusinessAccount.hpp"
#include <cmath>
 BusinessAccount::BusinessAccount(std::string id, AccountType type):Account(id,type) {

}

void BusinessAccount::Modify(Operation oper, MoneyType type, int amount) {
     if(oper == Operation::Deposit) {
         switch (type) {
         case MoneyType::PUA:
             SetMoney(GetTotal()+amount*6);
             break;
        case MoneyType::TWP:
            SetMoney(GetTotal()+amount*8);
            break;
         case MoneyType::OOTD:
             SetMoney(GetTotal()+amount*4);
             break;
         case MoneyType::FS:
             SetMoney(GetTotal()+amount*2);
             break;
         case MoneyType::OOP:
             SetMoney(GetTotal()+amount);
             break;
         }
     }
     else if(oper == Operation::Withdraw) {
         switch (type) {
             case MoneyType::PUA:
                 if(GetTotal() < std::floor(+amount*6))throw std::out_of_range("");
                 SetMoney(GetTotal() - std::floor(+(amount*6)));
                 break;
             case MoneyType::TWP:
                 if(GetTotal() < std::floor(+amount*8))throw std::out_of_range("");
                 SetMoney(GetTotal()-std::floor(+(amount*8)));
                 break;
             case MoneyType::OOTD:
                 if(GetTotal() < std::floor(+amount*4))throw std::out_of_range("");
                 SetMoney(GetTotal()-std::floor(+(amount*4)));
                 break;
             case MoneyType::FS:
                 if(GetTotal() < std::floor(+amount*2))throw std::out_of_range("");
                 SetMoney(GetTotal()-std::floor(+(amount*2)));
                 break;
             case MoneyType::OOP:
                 if(amount>GetTotal())throw std::out_of_range("");
                 SetMoney(GetTotal()-amount);
                 break;
         }
     }
 }

MoneyType BusinessAccount::GetMoneyInfo() {
     return moneytype;
 }