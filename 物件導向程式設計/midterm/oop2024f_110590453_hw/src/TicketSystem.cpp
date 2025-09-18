//
// Created by 陳世昂 on 2024/11/12.
//

#include "System/TicketSystem.hpp"

TicketSystem::TicketSystem(
    const std::shared_ptr<Boat>  boat,
    const std::shared_ptr<Bus>   car,
    const std::shared_ptr<Plane> plane,
    const std::shared_ptr<Train> train
) {
    this->boat = boat;
    this->bus = car;
    this->train = train;
    this->plane = plane;
};

Ticket TicketSystem::buyTicket(
    std::string name,
    Station     start,
    Station     end,
    VehicleType type,
    Discount    discount,
    int         distance
) {
    float discounts;
    switch (discount) {
    case Discount::ADULT:
        discounts = ADULT_PRI;
        break;
    case Discount::CHILD:
        discounts = CHILD_PRI;
        break;
    case Discount::OLDER:
        discounts = OLDER_PRI;
        break;
    }
    int price;
    switch (type) {
        case VehicleType::TRAIN:
            if(train_seat >= 1000) {
                throw std::invalid_argument("");
            }
        train_seat++;
            price = 80*distance*discounts;
            return Ticket{
                name,
                price,
                train_seat_number++,
                start,
                end,
                train
              };
            break;
        case VehicleType::BUS:
            if(bus_seat >= 20) {
                throw std::invalid_argument("");
            }
        bus_seat++;
        price = 100*distance*discounts;
            return Ticket{
                name,
                price,
                bus_seat_number++,
                start,
                end,
                bus
              };
            break;
        case VehicleType::PLANE:
            if(plane_seat >= 200) {
                throw std::invalid_argument("");
            }
        plane_seat++;
        price = 120*distance*discounts;
            return Ticket{
                name,
                price,
                plane_seat_number++,
                start,
                end,
                plane
              };
            break;
        case VehicleType::BOAT:
            if(boat_seat >= 50) {
                throw std::invalid_argument("");
            }
        boat_seat++;
        price = 50*distance*discounts;
            return Ticket{
                name,
                price,
                boat_seat_number++,
                start,
                end,
                boat
              };
            break;
    }
}

void TicketSystem::Depart(VehicleType type) {
    std::shared_ptr<Vehicle> vehicle;
    switch (type) {
    case VehicleType::BOAT:
        vehicle = Transform::UpCasting<Boat>(boat);
        if(vehicle->GetDurability() == 0) {
            throw std::runtime_error("");
        }
        if(vehicle->GetEnergy() == 0) {
            throw std::runtime_error("");
        }
        boat_seat = 0;
        vehicle->ConsumeDurability();
        break;
    case VehicleType::BUS:  vehicle = Transform::UpCasting<Bus>(bus);
        if(vehicle->GetDurability() == 0) {
            throw std::runtime_error("");
        }
        if(vehicle->GetEnergy() == 0) {
            throw std::runtime_error("");
        }
        bus_seat = 0;
        vehicle->ConsumeDurability();
        break;
    case VehicleType::TRAIN: vehicle = Transform::UpCasting<Train>(train);
        if(vehicle->GetDurability() == 0) {
            throw std::runtime_error("");
        }
        if(vehicle->GetEnergy() == 0) {
            throw std::runtime_error("");
        }
        train_seat = 0;
        vehicle->ConsumeDurability();
        break;
    case VehicleType::PLANE: vehicle = Transform::UpCasting<Plane>(plane);
        if(vehicle->GetDurability() == 0) {
            throw std::runtime_error("");
        }
        if(vehicle->GetEnergy() == 0) {
            throw std::runtime_error("");
        }
        plane_seat = 0;
        vehicle->ConsumeDurability();
        break;
    }
}
