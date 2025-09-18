//
// Created by User on 2024/12/27.
//


#include "Cheque.hpp"
#include "Deposits.hpp"
#include "Loan.hpp"

#include <gtest/gtest.h>


TEST(TESTICKET, TestCheque) {
    Ticket::Cheque cheque(Ticket::Info{"Cylinder","abaorz1zz",1000,0,MoneyType::PUA,Ticket::TicketType::Cheque});

    auto info = cheque.GetTicketInfo();

    ASSERT_NEAR(info.rate,0,1e-5);
    ASSERT_EQ(info.moneyType,MoneyType::PUA);
    ASSERT_EQ(info.drawer,"Cylinder");
    ASSERT_EQ(info.payee,"abaorz1zz");
    ASSERT_EQ(info.ticketType,Ticket::TicketType::Cheque);
    ASSERT_EQ(info.amount,1000);
}
TEST(TESTICKET, TestDeposit) {
    Ticket::Deposits deposit(Ticket::Info{"Bank","onon1101",10000,0.03,MoneyType::TWP,Ticket::TicketType::Deposits},"2025-01-10");

    auto info = deposit.GetTicketInfo();

    ASSERT_NEAR(info.rate,0.03,1e-5);
    ASSERT_EQ(info.moneyType,MoneyType::TWP);
    ASSERT_EQ(info.drawer,"Bank");
    ASSERT_EQ(info.payee,"onon1101");
    ASSERT_EQ(info.ticketType,Ticket::TicketType::Deposits);
    ASSERT_EQ(deposit.GetTime(),"2025-01-10");
    ASSERT_EQ(info.amount,10000);
}
TEST(TESTICKET, TestLoan) {
    Ticket::Loan loan(Ticket::Info{"Bank","kesshoban3310",81000,0.03,MoneyType::OOTD,Ticket::TicketType::Loan},"2025-01-10");

    auto info = loan.GetTicketInfo();

    ASSERT_NEAR(info.rate,0.03,1e-5);
    ASSERT_EQ(info.moneyType,MoneyType::OOTD);
    ASSERT_EQ(info.drawer,"Bank");
    ASSERT_EQ(info.payee,"kesshoban3310");
    ASSERT_EQ(info.ticketType,Ticket::TicketType::Loan);
    ASSERT_EQ(loan.GetTime(),"2025-01-10");
    ASSERT_EQ(info.amount,81000);
}