
#include <gtest/gtest.h>
#include <memory>

#include "Object/Boat.h"

TEST(BOAT_SYSTEM_TEST, Boat_Constructor) {
    auto v = std::make_shared<Boat>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::BOAT,
        30
    );

    auto t1 = v->GetFuelType();
    auto t2 = v->GetVehicleType();
    auto t3 = v->GetCountry();
    auto t4 = v->GetModel();
    auto t5 = v->GetSailing();
    auto t6 = v->GetMaxSpeed();

    EXPECT_EQ(t1, FuelType::Gasoline);
    EXPECT_EQ(t2, VehicleType::BOAT);
    EXPECT_EQ(t3, "TEST_country");
    EXPECT_EQ(t4, "TEST_model");
    EXPECT_EQ(t5, false);
    EXPECT_EQ(t6, 30);
}

TEST(BOAT_SYSTEM_TEST, BOAT_MAXSPEED) {
    auto v = std::make_shared<Boat>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::BOAT,
        30
    );

    v->SetMaxSpeed(20);
    auto t1 = v->GetMaxSpeed();
    EXPECT_EQ(t1, 20);

    EXPECT_THROW(v->SetMaxSpeed(31), std::invalid_argument);
}

TEST(BOAT_SYSTEM_TEST, BOAT_SAILING) {
    auto v = std::make_shared<Boat>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::BOAT,
        30
    );

    v->SetSailing(true);
    auto t1 = v->GetSailing();
    EXPECT_EQ(t1, true);
}

TEST(BOAT_SYSTEM_TEST, Boat_ConsumeDurability_Other) {
    auto v = std::make_shared<Boat>(
        "TEST_country",
        "TEST_model",
        10,
        VehicleType::BOAT,
        30
    );

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 0);
}

TEST(BOAT_SYSTEM_TEST, Boat_ConsumeDurability_USA) {
    auto v =
        std::make_shared<Boat>("USA", "TEST_model", 10, VehicleType::BOAT, 30);

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 6);
}

TEST(BOAT_SYSTEM_TEST, Boat_ConsumeDurability_Japan) {
    auto v = std::make_shared<Boat>(
        "Japan",
        "TEST_model",
        10,
        VehicleType::BOAT,
        30
    );

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 5);

    v->ConsumeDurability();
    EXPECT_THROW(v->ConsumeDurability(), std::runtime_error);
}

TEST(BOAT_SYSTEM_TEST, Constructor_exception) {
    EXPECT_THROW(
        Boat("Japan", "TEST_model", -1, VehicleType::BOAT, 0),
        std::invalid_argument
    );
    EXPECT_THROW(
        Boat("Japan", "TEST_model", 0, VehicleType::BOAT, -1),
        std::invalid_argument
    );
    EXPECT_THROW(
        Boat("Japan", "TEST_model", 101, VehicleType::BOAT, 0),
        std::invalid_argument
    );

    EXPECT_THROW(
        Boat("Japan", "TEST_model", 10, VehicleType::BOAT, 31),
        std::invalid_argument
    );
}
