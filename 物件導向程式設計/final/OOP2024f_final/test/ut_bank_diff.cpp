//
// Created by User on 2024/12/27.
//


#include "Bank.hpp"
#include "Checker.cpp"
#include <gtest/gtest.h>
class BankDiffTest : public testing::Test{
protected:
    Bank bank;
    std::shared_ptr<Account> Fubon = std::make_shared<BusinessAccount>("Fubon",AccountType::Business);
    std::shared_ptr<Account> Cathy = std::make_shared<BusinessAccount>("Cathy",AccountType::Business);
    std::shared_ptr<Account> CTBC = std::make_shared<BusinessAccount>("CTBC",AccountType::Business);

    std::shared_ptr<Account> aba = std::make_shared<PersonalAccount>("Abaorz1zz",AccountType::Personal,MoneyType::PUA);
    std::shared_ptr<Account> cylinder = std::make_shared<PersonalAccount>("Cylinder",AccountType::Personal,MoneyType::FS);
    std::shared_ptr<Account> noobdy = std::make_shared<PersonalAccount>("Noobdy",AccountType::Personal,MoneyType::TWP);
    std::shared_ptr<Account> onon1101 = std::make_shared<PersonalAccount>("Onon1101",AccountType::Personal,MoneyType::OOTD);
    std::vector<std::shared_ptr<Account> > a = {Fubon,Cathy,CTBC,aba,cylinder,noobdy,onon1101};
};


Checker checkers;

TEST_F(BankDiffTest,TestBankCanFindAccount){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    auto ans = bank.QueryAccount("Abaorz1zz");
    ASSERT_EQ(ans,3);
}
TEST_F(BankDiffTest,TestBankFindAccountWithExcept){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    ASSERT_THROW(bank.QueryAccount("Kesshoabn3310"),std::invalid_argument);
}

TEST_F(BankDiffTest,TestBankDeposit){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    bank.Deposit(bank.Calculator(2500,MoneyType::PUA),"Abaorz1zz");

    ASSERT_EQ(aba->GetTotal(),2500);
}
TEST_F(BankDiffTest,TestBankDepositForBusiness){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    bank.Deposit(bank.Calculator(2500,MoneyType::PUA),"Fubon");
    bank.Deposit(bank.Calculator(2500,MoneyType::OOP),"Fubon");
    bank.Deposit(bank.Calculator(2500,MoneyType::OOTD),"Fubon");
    bank.Deposit(bank.Calculator(2500,MoneyType::TWP),"Fubon");
    bank.Deposit(bank.Calculator(2500,MoneyType::FS),"Fubon");
    ASSERT_EQ(Fubon->GetTotal(),52500);
}
TEST_F(BankDiffTest,TestBankShouldGetError){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_THROW(bank.Deposit(bank.Calculator(2500,MoneyType::OOTD),"Abaorz1zz"),std::invalid_argument);
}
TEST_F(BankDiffTest,TestBankShouldGetError2){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_THROW(bank.Deposit(bank.Calculator(2500,MoneyType::OOP),"Cylinder"),std::invalid_argument);
}
TEST_F(BankDiffTest,TestBankShouldGetError3){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_THROW(bank.Deposit(bank.Calculator(2500,MoneyType::TWP),"onon1101"),std::invalid_argument);
}
TEST_F(BankDiffTest,TestBankShouldWithDraw){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_THROW(bank.Deposit(bank.Calculator(2500,MoneyType::TWP),"onon1101"),std::invalid_argument);
}
TEST_F(BankDiffTest,BankWithdraw){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    bank.Deposit(bank.Calculator(2500,MoneyType::PUA),"Abaorz1zz");
    auto ans = bank.Withdraw(Money{MoneyType::PUA,1000},"Abaorz1zz");

    ASSERT_EQ(aba->GetTotal(),1500);
    ASSERT_EQ(checkers.check(ans),1000);
    ASSERT_EQ(ans[0].GetType(),MoneyType::PUA);
}
TEST_F(BankDiffTest,BankWithdrawForBusiness){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    bank.Deposit(bank.Calculator(2500,MoneyType::PUA),"Cathy");
    auto ans = bank.Withdraw(Money{MoneyType::OOTD,100},"Cathy");

    ASSERT_EQ(Cathy->GetTotal(),14600);
    ASSERT_EQ(checkers.check(ans),100);
    ASSERT_EQ(ans[0].GetType(),MoneyType::OOTD);
}
TEST_F(BankDiffTest,BankWithdrawHaveError){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_THROW(bank.Withdraw(Money{MoneyType::PUA,10000},"Abaorz1zz"),std::out_of_range);
}
TEST_F(BankDiffTest,BankWithdrawHaveError2){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_THROW(bank.Withdraw(Money{MoneyType::PUA,1000000000},"Fubon"),std::out_of_range);
}
TEST_F(BankDiffTest,BankWithdrawHaveError3){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_THROW(bank.Withdraw(Money{MoneyType::TWP,10},"Abaorz1zz"),std::invalid_argument);
}

TEST_F(BankDiffTest,BankCanMakeTicket){
    Bank bank("2025-01-10");
    auto ticket = bank.MakeTicket(Ticket::TicketType::Cheque,"Fubon","Cylinder",MoneyType::OOP,1000,"1970-01-01");
    Ticket::Info ticketinfo = ticket->GetTicketInfo();

    ASSERT_EQ(ticketinfo.ticketType,Ticket::TicketType::Cheque);
    ASSERT_NEAR(ticketinfo.rate,0.0,1e-5);
    ASSERT_EQ(ticketinfo.moneyType,MoneyType::OOP);
    ASSERT_EQ(ticketinfo.drawer,"Fubon");
    ASSERT_EQ(ticketinfo.payee,"Cylinder");
    ASSERT_EQ(ticketinfo.amount,1000);

}
TEST_F(BankDiffTest,BankCanMakeTicket2){
    Bank bank("2025-01-10");
    auto ticket = bank.MakeTicket(Ticket::TicketType::Deposits,"Bank","Cylinder",MoneyType::OOP,1000,"2025-12-31");
    Ticket::Info ticketinfo = ticket->GetTicketInfo();

    ASSERT_EQ(ticketinfo.ticketType,Ticket::TicketType::Deposits);
    ASSERT_NEAR(ticketinfo.rate,0.03,1e-5);
    ASSERT_EQ(ticketinfo.moneyType,MoneyType::OOP);
    ASSERT_EQ(ticketinfo.drawer,"Bank");
    ASSERT_EQ(ticketinfo.payee,"Cylinder");
    ASSERT_EQ(ticketinfo.amount,1000);
    ASSERT_EQ(std::dynamic_pointer_cast<Ticket::Deposits>(ticket)->GetTime(),"2025-12-31");
}
TEST_F(BankDiffTest,BankCanMakeTicket3){
    Bank bank("2025-01-10");
    auto ticket = bank.MakeTicket(Ticket::TicketType::Loan,"Fubon","Bank",MoneyType::OOP,1000,"2038-03-14");
    Ticket::Info ticketinfo = ticket->GetTicketInfo();

    ASSERT_EQ(ticketinfo.ticketType,Ticket::TicketType::Loan);
    ASSERT_NEAR(ticketinfo.rate,0.03,1e-5);
    ASSERT_EQ(ticketinfo.moneyType,MoneyType::OOP);
    ASSERT_EQ(ticketinfo.drawer,"Fubon");
    ASSERT_EQ(ticketinfo.payee,"Bank");
    ASSERT_EQ(ticketinfo.amount,1000);
    ASSERT_EQ(std::dynamic_pointer_cast<Ticket::Loan>(ticket)->GetTime(),"2038-03-14");
}

std::shared_ptr<Ticket::Ticket> loan = std::make_shared<Ticket::Loan>(Ticket::Info{"Fubon","Bank",5000,0.03,MoneyType::OOP,Ticket::TicketType::Loan},"2038-03-14");
std::shared_ptr<Ticket::Ticket> loan2 = std::make_shared<Ticket::Loan>(Ticket::Info{"Fubon","Bank",5000,0.03,MoneyType::OOP,Ticket::TicketType::Loan},"2004-02-12");

TEST_F(BankDiffTest,BankCanUseTicket){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    bank.Deposit(bank.Calculator(10000,MoneyType::PUA),"Fubon");



    ASSERT_EQ(Fubon->GetTotal(),60000);
    bank.ExchangeTicket(loan);
    ASSERT_EQ(Fubon->GetTotal(),54850);
}
TEST_F(BankDiffTest,BankCanUseTicketWithFine){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);

    ASSERT_EQ(Fubon->GetTotal(),0);

    bank.Deposit(bank.Calculator(100000,MoneyType::OOP),"Fubon");

    bank.ExchangeTicket(loan2);
    ASSERT_EQ(Fubon->GetTotal(),94600);
}

std::shared_ptr<Ticket::Ticket> deposits = std::make_shared<Ticket::Deposits>(Ticket::Info{"Bank","Cylinder",5000,0.03,MoneyType::FS,Ticket::TicketType::Deposits},"2038-03-14");
std::shared_ptr<Ticket::Ticket> deposits2 = std::make_shared<Ticket::Deposits>(Ticket::Info{"Bank","Cylinder",5000,0.03,MoneyType::FS,Ticket::TicketType::Deposits},"2004-02-12");

TEST_F(BankDiffTest,BankCanUseDeposit){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    ASSERT_EQ(cylinder->GetTotal(),0);
    bank.ExchangeTicket(deposits2);
    ASSERT_EQ(cylinder->GetTotal(),5150);
}
TEST_F(BankDiffTest,BankCanUseDepositWithExcept){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    ASSERT_EQ(cylinder->GetTotal(),0);
    ASSERT_THROW(bank.ExchangeTicket(deposits),std::invalid_argument);
}

std::shared_ptr<Ticket::Ticket> cheque = std::make_shared<Ticket::Cheque>(Ticket::Info{"Fubon","Cylinder",5000,0.0,MoneyType::OOP,Ticket::TicketType::Cheque});

TEST_F(BankDiffTest,BankCanUseCheque){
    Bank bank("2025-01-10");
    bank.SetAccounts(a);
    ASSERT_EQ(cylinder->GetTotal(),0);
    ASSERT_EQ(Fubon->GetTotal(),0);

    bank.Deposit(bank.Calculator(100000,MoneyType::OOP),"Fubon");

    bank.ExchangeTicket(cheque);

    ASSERT_EQ(cylinder->GetTotal(),2450);
    ASSERT_EQ(Fubon->GetTotal(),95000);
}