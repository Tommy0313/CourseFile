#include <gtest/gtest.h>
#include <memory>
#include "Object/Vehicle.h"
#include "System/TicketSystem.hpp"
#include "Factory/FactoryJapan.h"

constexpr float TEST_CHILD_DISCOUNT = 0.6;
constexpr float TEST_ADULT_DISCOUNT = 1.0;
constexpr float TEST_OLDER_DISCOUNT = 0.8;

constexpr int TEST_TRAIN_PRICE = 80;
constexpr int TEST_PLANE_PRICE = 120;
constexpr int TEST_BUS_PRICE = 100;
constexpr int TEST_BOAT_PRICE = 50;


TEST(TICKETSYSTEM_SYSTEM_TEST, BUYTICKET_ADULT_Train) {
    const int distance = 300;

    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    auto ticket = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::TRAIN, Discount::ADULT, distance);
    auto corrent = Ticket{"TESTER", static_cast<int>(TEST_TRAIN_PRICE * distance * TEST_ADULT_DISCOUNT), 0, Station::TAIPEI, Station::KAOHSIUNG, t};

    EXPECT_EQ(ticket.vehicle->GetCountry(), t->GetCountry());
    EXPECT_EQ(ticket.vehicle->GetModel(), t->GetModel());
    EXPECT_EQ(ticket.price, corrent.price);
    EXPECT_EQ(ticket.start, corrent.start);
    EXPECT_EQ(ticket.end, corrent.end);
    EXPECT_EQ(ticket.passengerName, corrent.passengerName);
    EXPECT_EQ(ticket.ticketNumber, 0);

    auto tick01 = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::TRAIN, Discount::ADULT, 300);
    auto corrent_01 = Ticket{"TESTER", static_cast<int>(TEST_TRAIN_PRICE * distance * TEST_ADULT_DISCOUNT), 1, Station::TAIPEI, Station::KAOHSIUNG, t};

    EXPECT_EQ(tick01.ticketNumber, 1);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, BUYTICKET_ADULT_Plane) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    auto ticket = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::PLANE, Discount::ADULT, 300);
    EXPECT_EQ(ticket.price, 36000);
    EXPECT_EQ(ticket.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(ticket.vehicle->GetModel(), "Mitsubishi");
    EXPECT_EQ(ticket.start, Station::TAIPEI);
    EXPECT_EQ(ticket.end, Station::KAOHSIUNG);
    EXPECT_EQ(ticket.passengerName, "TESTER");
    EXPECT_EQ(ticket.ticketNumber, 0);

    auto tick01 = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::PLANE, Discount::ADULT, 300);
    EXPECT_EQ(tick01.price, 36000);
    EXPECT_EQ(tick01.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(tick01.vehicle->GetModel(), "Mitsubishi");
    EXPECT_EQ(tick01.start, Station::TAIPEI);
    EXPECT_EQ(tick01.end, Station::KAOHSIUNG);
    EXPECT_EQ(tick01.passengerName, "TESTER");
    EXPECT_EQ(tick01.ticketNumber, 1);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, BUYTICKET_ADULT_Bus) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    auto ticket = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::BUS, Discount::ADULT, 300);
    EXPECT_EQ(ticket.price, 30000);
    EXPECT_EQ(ticket.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(ticket.vehicle->GetModel(), "Yamaha");
    EXPECT_EQ(ticket.start, Station::TAIPEI);
    EXPECT_EQ(ticket.end, Station::KAOHSIUNG);
    EXPECT_EQ(ticket.passengerName, "TESTER");
    EXPECT_EQ(ticket.ticketNumber, 0);

    auto tick01 = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::BUS, Discount::ADULT, 300);
    EXPECT_EQ(tick01.price, 30000);
    EXPECT_EQ(tick01.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(tick01.vehicle->GetModel(), "Yamaha");
    EXPECT_EQ(tick01.start, Station::TAIPEI);
    EXPECT_EQ(tick01.end, Station::KAOHSIUNG);
    EXPECT_EQ(tick01.passengerName, "TESTER");
    EXPECT_EQ(tick01.ticketNumber, 1);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, BUYTICKET_ADULT_Boat) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    auto ticket = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::BOAT, Discount::ADULT, 300);
    EXPECT_EQ(ticket.price, 15000);
    EXPECT_EQ(ticket.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(ticket.vehicle->GetModel(), "Shinkansen");
    EXPECT_EQ(ticket.start, Station::TAIPEI);
    EXPECT_EQ(ticket.end, Station::KAOHSIUNG);
    EXPECT_EQ(ticket.passengerName, "TESTER");
    EXPECT_EQ(ticket.ticketNumber, 0);

    auto tick01 = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::BOAT, Discount::ADULT, 300);
    EXPECT_EQ(tick01.price, 15000);
    EXPECT_EQ(tick01.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(tick01.vehicle->GetModel(), "Shinkansen");
    EXPECT_EQ(tick01.start, Station::TAIPEI);
    EXPECT_EQ(tick01.end, Station::KAOHSIUNG);
    EXPECT_EQ(tick01.passengerName, "TESTER");
    EXPECT_EQ(tick01.ticketNumber, 1);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, BUYTICKET_CHILD) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    auto ticket = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::TRAIN, Discount::CHILD, 300);
    EXPECT_EQ(ticket.price, 14400);
    EXPECT_EQ(ticket.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(ticket.vehicle->GetModel(), "Toyota");
    EXPECT_EQ(ticket.start, Station::TAIPEI);
    EXPECT_EQ(ticket.end, Station::KAOHSIUNG);
    EXPECT_EQ(ticket.passengerName, "TESTER");
    EXPECT_EQ(ticket.ticketNumber, 0);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, BUYTICKET_OLDER) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    auto ticket = ti.buyTicket("TESTER", Station::TAIPEI, Station::KAOHSIUNG, VehicleType::TRAIN, Discount::OLDER, 300);
    EXPECT_EQ(ticket.price, 19200);
    EXPECT_EQ(ticket.vehicle->GetCountry(), "Japan");
    EXPECT_EQ(ticket.vehicle->GetModel(), "Toyota");
    EXPECT_EQ(ticket.start, Station::TAIPEI);
    EXPECT_EQ(ticket.end, Station::KAOHSIUNG);
    EXPECT_EQ(ticket.passengerName, "TESTER");
    EXPECT_EQ(ticket.ticketNumber, 0);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, Depart) {

    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    bu->AddEnergy(1000);
    bu->AddDurability(100);

    auto ti = TicketSystem(bo, bu, p, t);

    const auto tic = [&ti](VehicleType type) {
        return ti.buyTicket("TESTER",
                            Station::TAIPEI,
                            Station::KAOHSIUNG,
                            type,
                            Discount::OLDER,
                            300);
    };

    for (int i = 0; i < 19 ; i++ ) {
        auto ti_loop = tic(VehicleType::BUS);
        EXPECT_EQ(ti_loop.ticketNumber, i);
    }

    auto tic_00 = tic(VehicleType::BUS);
    EXPECT_EQ(tic_00.ticketNumber, 19);

    ti.Depart(VehicleType::BUS);

    auto tic_03 = tic(VehicleType::BUS);
    EXPECT_EQ(tic_03.ticketNumber, 20);

    auto tic_04 = tic(VehicleType::BOAT);
    auto tic_05 = tic(VehicleType::TRAIN);
    auto tic_06 = tic(VehicleType::PLANE);

    EXPECT_THROW(ti.Depart(VehicleType::BOAT), std::runtime_error);
    EXPECT_THROW(ti.Depart(VehicleType::TRAIN), std::runtime_error);
    p->AddEnergy(100);
    EXPECT_THROW(ti.Depart(VehicleType::PLANE), std::runtime_error);

}

TEST(TICKETSYSTEM_SYSTEM_TEST, Boat_Full) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    const auto tif = [&ti](VehicleType type) {
        return ti.buyTicket("TESTER",
                            Station::TAIPEI,
                            Station::KAOHSIUNG,
                            type,
                            Discount::OLDER,
                            300);
    };

    for (int i = 0 ; i < 50 ; i++) {
        auto tic = tif(VehicleType::BOAT);
        EXPECT_EQ(tic.ticketNumber, i);
    }

    // 51
    EXPECT_THROW(tif(VehicleType::BOAT), std::invalid_argument);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, Plane_Full) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    const auto tif = [&ti](VehicleType type) {
        return ti.buyTicket("TESTER",
                            Station::TAIPEI,
                            Station::KAOHSIUNG,
                            type,
                            Discount::OLDER,
                            300);
    };

    for (int i = 0 ; i < 200 ; i++) {
        auto tic = tif(VehicleType::PLANE);
        EXPECT_EQ(tic.ticketNumber, i);
    }

    // 201
    EXPECT_THROW(tif(VehicleType::PLANE), std::invalid_argument);
}

TEST(TICKETSYSTEM_SYSTEM_TEST, Train_Full) {
    auto bo = Factory::Japan::ProduceBoat();
    auto bu = Factory::Japan::ProduceBus();
    auto p = Factory::Japan::ProducePlane();
    auto t = Factory::Japan::ProduceTrain();

    auto ti = TicketSystem(bo, bu, p, t);

    const auto tif = [&ti](VehicleType type) {
        return ti.buyTicket("TESTER",
                            Station::TAIPEI,
                            Station::KAOHSIUNG,
                            type,
                            Discount::OLDER,
                            300);
    };

    for (int i = 0 ; i < 1000 ; i++) {
        auto tic = tif(VehicleType::TRAIN);
        EXPECT_EQ(tic.ticketNumber, i);
    }

    // 1001
    EXPECT_THROW(tif(VehicleType::TRAIN), std::invalid_argument);
}