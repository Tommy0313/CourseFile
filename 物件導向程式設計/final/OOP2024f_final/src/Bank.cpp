
#include "Bank.hpp"

#include <memory>
#include <stdexcept>

#include "Cheque.hpp"
#include "Deposits.hpp"
#include "Loan.hpp"
#include "PersonalAccount.hpp"

void Bank::ExchangeTicket(std::shared_ptr<Ticket::Ticket> ticket) {
    auto info = ticket->GetTicketInfo();
    switch (info.ticketType) {
    case Ticket::TicketType::Cheque: {
        //TODO: Finish Cheque Effect.
        int p_idx = QueryAccount(info.payee);
        Withdraw(Money(info.moneyType, info.amount), info.drawer);

        if (accounts[p_idx]->GetAccountInfo() == AccountType::Personal) {
            std::shared_ptr<PersonalAccount> payee = std::dynamic_pointer_cast<PersonalAccount>(accounts[p_idx]);

        } else {

        }
        break;
    }
    case Ticket::TicketType::Loan: {
        //TODO: Finish Loan Effect.
        std::shared_ptr<Ticket::Loan> loan = std::dynamic_pointer_cast<Ticket::Loan>(ticket);

        break;
    }
    case Ticket::TicketType::Deposits: {
        //TODO: Finish Deposits Effect.
        std::shared_ptr<Ticket::Deposits> deposits = std::dynamic_pointer_cast<Ticket::Deposits>(ticket);

    }
    }
}
