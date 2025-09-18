
#include <gtest/gtest.h>
#include <memory>

#include "Object/Bus.h"

TEST(BUS_SYSTEM_TEST, Bus_Constructor) {
    auto v = std::make_shared<Bus>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::BUS,
        6,
        80
    );

    auto t1 = v->GetFuelType();
    auto t2 = v->GetVehicleType();
    auto t3 = v->GetCountry();
    auto t4 = v->GetModel();
    auto t5 = v->GetWheel();
    auto t6 = v->GetMaxSpeed();

    EXPECT_EQ(t1, FuelType::Gasoline);
    EXPECT_EQ(t2, VehicleType::BUS);
    EXPECT_EQ(t3, "TEST_country");
    EXPECT_EQ(t4, "TEST_model");
    EXPECT_EQ(t5, 6);
    EXPECT_EQ(t6, 80);
}

TEST(BUS_SYSTEM_TEST, Bus_Wheel) {
    auto v = std::make_shared<Bus>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::BUS,
        6,
        80
    );

    v->SetWheel(10);
    auto t1 = v->GetWheel();
    EXPECT_EQ(t1, 10);

    EXPECT_THROW(v->SetWheel(13), std::invalid_argument);
}

TEST(BUS_SYSTEM_TEST, Bus_Speed) {
    auto v = std::make_shared<Bus>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::BUS,
        6,
        80
    );

    v->SetMaxSpeed(60);
    auto t1 = v->GetMaxSpeed();
    EXPECT_EQ(t1, 60);

    EXPECT_THROW(v->SetMaxSpeed(81), std::invalid_argument);
}

TEST(BUS_SYSTEM_TEST, Bus_ConsumeDurability_Other) {
    auto v = std::make_shared<Bus>(
        "TEST_country",
        "TEST_model",
        10,
        VehicleType::BUS,
        6,
        80
    );

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 0);
}

TEST(BUS_SYSTEM_TEST, Bus_ConsumeDurability_USA) {
    auto v =
        std::make_shared<Bus>("USA", "TEST_model", 10, VehicleType::BUS, 6, 80);

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 5);
}

TEST(BUS_SYSTEM_TEST, Bus_ConsumeDurability_Japan) {
    auto v = std::make_shared<Bus>(
        "Japan",
        "TEST_model",
        1,
        VehicleType::BUS,
        6,
        80
    );

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 0);

    EXPECT_THROW(v->ConsumeDurability(), std::runtime_error);
}
TEST(BUS_SYSTEM_TEST, Constructor_exception) {
    EXPECT_THROW(
        Bus("USA", "TEST_model", -1, VehicleType::TRAIN, 0, 0),
        std::invalid_argument
    );
    EXPECT_THROW(
        Bus("USA", "TEST_model", 0, VehicleType::TRAIN, -1, 0),
        std::invalid_argument
    );
    EXPECT_THROW(
        Bus("USA", "TEST_model", 0, VehicleType::TRAIN, 0, -1),
        std::invalid_argument
    );
    EXPECT_THROW(
        Bus("USA", "TEST_model", 0, VehicleType::TRAIN, 13, 0),
        std::invalid_argument
    );
    EXPECT_THROW(
        Bus("USA", "TEST_model", 0, VehicleType::TRAIN, 1, 81),
        std::invalid_argument
    );
}
