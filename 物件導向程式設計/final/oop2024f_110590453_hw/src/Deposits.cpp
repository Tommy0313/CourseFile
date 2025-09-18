
#include "Deposits.hpp"

namespace Ticket {
 Deposits::Deposits(Info info, std::string time):Ticket(info) {
    this->time = time;
}

std::string Deposits::GetTime() {
    return time;
}

Info Deposits::GetTicketInfo() {
    return ticketinfo;
}


}