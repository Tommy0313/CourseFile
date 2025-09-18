#include "TicketSystem.hpp"

int CheckTicketPrice(Order ticket){
    if (ticket.quantity <= 0) {
        throw std::invalid_argument("");
    } else {
        int total = 0;
        switch (ticket.type) {
        case TicketType::Adult:
            total = ticket.quantity * 350;
            break;
        case TicketType::Child:
            total = ticket.quantity * 280;
            break;
        case TicketType::Elder:
            total = ticket.quantity * 240;
            break;
        }
        if (ticket.quantity >= 10) {
            total = total / 10 * 8;
            return total;
        }
        return total;
    }
}
int CheckTodaySales(std::vector<Order> tickets){
    int total = 0;
    for (auto ticket : tickets) {
        total += CheckTicketPrice(ticket);
    }
    return total;
}
int CheckTodayTicketSales(std::vector<Order> tickets){
    int total = 0;
    for (auto ticket : tickets) {
        if (ticket.quantity <= 0) {
            throw std::invalid_argument("");

        } else {
            total += ticket.quantity;
        }
    }
    return total;
}
int CheckSpecificTicketSales(TicketType type,std::vector<Order> tickets){
    int total = 0;
    for (auto ticket : tickets) {
        if (ticket.type == type) total += CheckTicketPrice(ticket);
    }
    return total;
}
int CheckSpecificOrdersTicketPrice(int idx,std::vector<Order> tickets){
    if (tickets.size() <= idx || idx < 0) {
        throw std::invalid_argument("abc");
    } else {
        return CheckTicketPrice(tickets[idx]);
    }
}
