//
// Created by adven on 10/29/2024.
//

#ifndef OOP_MIDTERM_TICKETSYSTEM_HPP
#define OOP_MIDTERM_TICKETSYSTEM_HPP

#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "Object/Boat.h"
#include "Object/Bus.h"
#include "Object/Plane.h"
#include "Object/Train.h"
#include "Object/Vehicle.h"
#include "TransferLayer.hpp"

const float CHILD_PRI = 0.6f;
const float ADULT_PRI = 1.0f;
const float OLDER_PRI = 0.8f;

enum class Station {
    TAIPEI = 1,
    KAOHSIUNG,
};

enum class Discount {
    CHILD,
    ADULT,
    OLDER,
};

struct Ticket {
    std::string const passengerName;

    int price = 0;
    int ticketNumber = 0;

    Station start;
    Station end;

    const std::shared_ptr<Vehicle> vehicle;
};

class TicketSystem final {
private:
    std::shared_ptr<Boat> boat = nullptr;
    std::shared_ptr<Bus> bus = nullptr;
    std::shared_ptr<Plane> plane = nullptr;
    std::shared_ptr<Train> train = nullptr;
    int train_seat = 0;
    int boat_seat = 0;
    int plane_seat = 0;
    int bus_seat = 0;
    int train_seat_number = 0;
    int boat_seat_number = 0;
    int plane_seat_number = 0;
    int bus_seat_number = 0;
public:
    explicit TicketSystem(
        const std::shared_ptr<Boat>  boat,
        const std::shared_ptr<Bus>   car,
        const std::shared_ptr<Plane> plane,
        const std::shared_ptr<Train> train
    );

    Ticket buyTicket(
        std::string name,
        Station     start,
        Station     end,
        VehicleType type,
        Discount    discount,
        int distance
    );

    void Depart(VehicleType type);

};

#endif  // OOP_MIDTERM_TICKETSYSTEM_HPP
