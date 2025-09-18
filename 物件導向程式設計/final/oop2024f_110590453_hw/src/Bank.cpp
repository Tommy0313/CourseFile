
#include "Bank.hpp"

#include <memory>
#include <stdexcept>

#include "Cheque.hpp"
#include "Deposits.hpp"
#include "Loan.hpp"
#include "PersonalAccount.hpp"
#include <cmath>

 Bank::Bank(std::string time) {
    this->time = time;
}


void Bank::ExchangeTicket(std::shared_ptr<Ticket::Ticket> ticket) {
    auto info = ticket->GetTicketInfo();
    switch (info.ticketType) {
    case Ticket::TicketType::Cheque: {
        //TODO: Finish Cheque Effect.
        int p_idx = QueryAccount(info.payee);
        std::vector<Money> moneys = Withdraw(Money(info.moneyType, info.amount), info.drawer);

        if (accounts[p_idx]->GetAccountInfo() == AccountType::Personal) {
            std::shared_ptr<PersonalAccount> payee = std::dynamic_pointer_cast<PersonalAccount>(accounts[p_idx]);
            if(payee->GetMoneyInfo() != moneys[0].GetType()) {
                Deposit(Calculator(Exchange(moneys,payee->GetMoneyInfo())[0].GetAmount() *0.98,payee->GetMoneyInfo()),payee->GetUser());
            }
            else {
                Deposit(Exchange(moneys,payee->GetMoneyInfo()),payee->GetUser());
            }
        } else {
            std::shared_ptr<BusinessAccount> payee = std::dynamic_pointer_cast<BusinessAccount>(accounts[p_idx]);
            if(payee->GetMoneyInfo() != moneys[0].GetType()) {
                Deposit(Calculator(Exchange(moneys,payee->GetMoneyInfo())[0].GetAmount() *0.98,payee->GetMoneyInfo()),payee->GetUser());
            }
            else {
                Deposit(Exchange(moneys,payee->GetMoneyInfo()),payee->GetUser());
            }
        }
        break;
    }
    case Ticket::TicketType::Loan: {
        //TODO: Finish Loan Effect.
        std::shared_ptr<Ticket::Loan> loan = std::dynamic_pointer_cast<Ticket::Loan>(ticket);
        if(time < loan->GetTime()) {
            std::invalid_argument("");
        }
        else {
            int p_idx = QueryAccount(info.drawer);
            std::vector<Money> moneys = Withdraw(Money(info.moneyType, info.amount*info.rate), info.drawer);

            if (accounts[p_idx]->GetAccountInfo() == AccountType::Personal) {
                std::shared_ptr<PersonalAccount> payee = std::dynamic_pointer_cast<PersonalAccount>(accounts[p_idx]);
                if(payee->GetMoneyInfo() != moneys[0].GetType()) {
                    Withdraw(Calculator(Exchange(moneys,payee->GetMoneyInfo())[0].GetAmount() *0.98,payee->GetMoneyInfo())[0],payee->GetUser());
                }
                else {
                    Withdraw(Exchange(moneys,payee->GetMoneyInfo())[0],payee->GetUser());
                }
            } else {
                std::shared_ptr<BusinessAccount> payee = std::dynamic_pointer_cast<BusinessAccount>(accounts[p_idx]);
                if(payee->GetMoneyInfo() != moneys[0].GetType()) {
                    Withdraw(Calculator(Exchange(moneys,payee->GetMoneyInfo())[0].GetAmount() *0.98,payee->GetMoneyInfo())[0],payee->GetUser());
                }
                else {
                    Withdraw(Exchange(moneys,payee->GetMoneyInfo())[0],payee->GetUser());
                }
            }
        }
        break;
    }
    case Ticket::TicketType::Deposits: {
        //TODO: Finish Deposits Effect.
        std::shared_ptr<Ticket::Deposits> deposits = std::dynamic_pointer_cast<Ticket::Deposits>(ticket);
        if(time > deposits->GetTime()) {
            std::invalid_argument("");
        }
        else {
            int p_idx = QueryAccount(info.payee);
            std::vector<Money> moneys = Withdraw(Money(info.moneyType, deposits->GetTicketInfo().amount*deposits->GetTicketInfo().rate), info.drawer);

            if (accounts[p_idx]->GetAccountInfo() == AccountType::Personal) {
                std::shared_ptr<PersonalAccount> payee = std::dynamic_pointer_cast<PersonalAccount>(accounts[p_idx]);
                if(payee->GetMoneyInfo() != moneys[0].GetType()) {
                    payee->Modify(Operation::Deposit,moneys[0].GetType(),moneys[0].GetAmount()*0.98);
                }
                else {
                    payee->Modify(Operation::Deposit,moneys[0].GetType(),moneys[0].GetAmount());
                }
            } else {
                std::shared_ptr<BusinessAccount> payee = std::dynamic_pointer_cast<BusinessAccount>(accounts[p_idx]);
                if(payee->GetMoneyInfo() != moneys[0].GetType()) {
                    payee->Modify(Operation::Deposit,moneys[0].GetType(),moneys[0].GetAmount()*0.98);
                }
                else {
                    payee->Modify(Operation::Deposit,moneys[0].GetType(),moneys[0].GetAmount());
                }
            }
        }
        break;
    }
    }
}

void Bank::SetAccounts(std::vector<std::shared_ptr<Account>> accounts) {
    this->accounts = accounts;
}

int Bank::QueryAccount(std::string id) {
    int j = 0;
    for(auto &m:accounts) {
        m->GetTotal();
        j++;
    }
    for(int i=0;i < j;i++) {
        if(accounts[i]->GetUser() == id) {
            return i;
        }
    }
    throw std::invalid_argument("");
}

void Bank::Deposit(std::vector<Money> money, std::string id) {
    for(auto & i : money) {
        accounts[QueryAccount(id)]->Modify(Operation::Deposit,i.GetType(),i.GetAmount());
    }
}

std::vector<Money> Bank::Withdraw(Money money, std::string id) {
    accounts[QueryAccount(id)]->Modify(Operation::Withdraw,money.GetType(),money.GetAmount());
     return Calculator(money.GetAmount(),money.GetType());
}

std::vector<Money> Bank::Exchange(std::vector<Money> money,
                                  MoneyType exchangetype) {
    std::vector<Money> temp;
    for(auto &m:money) {
        int OOP;
        switch (m.GetType()) {
        case MoneyType::PUA:
            OOP = std::floor(+m.GetAmount()*6);
            break;
        case MoneyType::TWP:
            OOP = std::floor(+m.GetAmount()*8);
            break;
        case MoneyType::OOTD:
            OOP = std::floor(+m.GetAmount()*4);
            break;
        case MoneyType::FS:
            OOP = std::floor(+m.GetAmount()*2);
            break;
        case MoneyType::OOP:
            OOP = m.GetAmount();
            break;
        }
        int result = 0;
        switch (exchangetype) {
        case MoneyType::PUA:
            result = OOP/6;
            break;
        case MoneyType::TWP:
            result = OOP/8;
            break;
        case MoneyType::OOTD:
            result = OOP/4;
            break;
        case MoneyType::FS:
            result = OOP/2;
            break;
        case MoneyType::OOP:
            result = OOP;
            break;
        }
        temp.push_back(Money(exchangetype,result));
    }
    return temp;
}

std::shared_ptr<Ticket::Ticket>
Bank::MakeTicket(Ticket::TicketType type, std::string drawer, std::string payee,
                 MoneyType moneytype, int amount, std::string time) {
    Ticket::Info info;
    std::shared_ptr<Ticket::Ticket> ticker;
    info.amount = amount;
    info.ticketType = type;
    info.drawer = drawer;
    info.payee = payee;
    info.moneyType = moneytype;
    switch (type) {
    case Ticket::TicketType::Cheque:
        info.rate = 0;
        ticker = std::make_shared<Ticket::Cheque>(info);
        break;
    case Ticket::TicketType::Deposits:
        info.rate = 0.03;
        ticker = std::make_shared<Ticket::Deposits>(info,time);
        break;
        case Ticket::TicketType::Loan:
            info.rate = 0.03;
        ticker = std::make_shared<Ticket::Loan>(info,time);
    }
    return ticker;
}

void Bank::UpdateTime(std::string time) {
    if(this->time < time) {
        this->time = time;
    }
}

std::string Bank::GetTime() {
    return time;
}

std::vector<Money> Bank::Calculator(int amount, MoneyType type) {
    std::vector<Money> temp;
     temp.push_back(Money(type,amount));
    return temp;
}








