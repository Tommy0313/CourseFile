//
// Created by 陳世昂 on 2024/11/12.
//

#include "System/TicketSystem.hpp"

TicketSystem::TicketSystem(
    const std::shared_ptr<Boat>  boat,
    const std::shared_ptr<Bus>   car,
    const std::shared_ptr<Plane> plane,
    const std::shared_ptr<Train> train
){};

Ticket TicketSystem::buyTicket(
    std::string name,
    Station     start,
    Station     end,
    VehicleType type,
    Discount    discount,
    int         distance
) {
    return Ticket{
      "passengerName",
      0,
      0,
      Station::KAOHSIUNG,
      Station::TAIPEI,
      nullptr
    };
}

void TicketSystem::Depart(VehicleType type) {
}
