#ifndef BANK_HPP
#define BANK_HPP

#include "BusinessAccount.hpp"
#include "Cheque.hpp"
#include "Deposits.hpp"
#include "Loan.hpp"
#include "Money.hpp"
#include "PersonalAccount.hpp"
#include <memory>
#include <cmath>
class Bank{
private:
    std::vector<std::shared_ptr<Account> > accounts;
    std::string time = "1970-01-01";
public:
    Bank() = default;
    Bank(std::string time);
    void SetAccounts(std::vector<std::shared_ptr<Account>> accounts);
    int QueryAccount(std::string id);
    void Deposit(std::vector<Money> money, std::string id);
    std::vector<Money> Withdraw(Money money, std::string id);
    std::vector<Money> Exchange(std::vector<Money> money,
                                MoneyType exchangetype);
    std::vector<Money> Calculator(int amount,MoneyType type);
    std::shared_ptr<Ticket::Ticket>
    MakeTicket(Ticket::TicketType type, std::string drawer, std::string payee,
               MoneyType moneytype, int amount, std::string time);
    void UpdateTime(std::string time);
    std::string GetTime();
    void ExchangeTicket(std::shared_ptr<Ticket::Ticket> ticket);
};

#endif