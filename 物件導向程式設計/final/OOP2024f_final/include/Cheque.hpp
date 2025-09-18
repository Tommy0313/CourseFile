#ifndef CHEQUE_HPP
#define CHEQUE_HPP

#include "Ticket.hpp"

namespace Ticket {

class Cheque {
public:
    Cheque(Info info);
    Info GetTicketInfo();
};

}
#endif