#ifndef LOAN_HPP
#define LOAN_HPP

#include "Ticket.hpp"

namespace Ticket {

class Loan {
private:
    std::string time = "";

public:
    Loan(Info info, std::string time);
    Info GetTicketInfo() ;
    std::string GetTime() ;
};

}

#endif