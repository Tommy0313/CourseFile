#ifndef CHEQUE_HPP
#define CHEQUE_HPP

#include "Ticket.hpp"

namespace Ticket {

class Cheque:public Ticket{
public:
    Cheque(Info info);
    Info GetTicketInfo() override;
    std::string GetTime() override;
};

}
#endif