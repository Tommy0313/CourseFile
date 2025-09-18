#ifndef DEPOSIT_HPP
#define DEPOSIT_HPP

#include "Ticket.hpp"

namespace Ticket {

class Deposits {
private:
    std::string time = "";

public:
    Deposits(Info info, std::string time);
    Info GetTicketInfo() ;
    std::string GetTime() ;
};

}

#endif