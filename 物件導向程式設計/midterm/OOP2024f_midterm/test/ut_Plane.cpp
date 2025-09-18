
#include <gtest/gtest.h>
#include <memory>

#include "Object/Plane.h"

TEST(PLANE_SYSTEM_TEST, Plane_Constructor) {
    auto v = std::make_shared<Plane>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::PLANE,
        0,
        40000
    );

    auto t1 = v->GetFuelType();
    auto t2 = v->GetVehicleType();
    auto t3 = v->GetCountry();
    auto t4 = v->GetModel();
    auto t5 = v->GetCurrentAltitude();
    auto t6 = v->GetMaxAltitude();

    EXPECT_EQ(t1, FuelType::Gasoline);
    EXPECT_EQ(t2, VehicleType::PLANE);
    EXPECT_EQ(t3, "TEST_country");
    EXPECT_EQ(t4, "TEST_model");
    EXPECT_EQ(t5, 0);
    EXPECT_EQ(t6, 40000);
}

TEST(PLANE_SYSTEM_TEST, PLANE_MAXALTITUDE) {
    auto v = std::make_shared<Plane>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::PLANE,
        0,
        40000
    );

    v->SetMaxAltitude(30000);
    auto t1 = v->GetMaxAltitude();
    EXPECT_EQ(t1, 30000);

    EXPECT_THROW(v->SetMaxAltitude(40001), std::invalid_argument);
}

TEST(PLANE_SYSTEM_TEST, PLANE_CURRENTALTITUDE) {
    auto v = std::make_shared<Plane>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::PLANE,
        0,
        25000
    );

    v->SetCurrentAltitude(3000);
    auto t1 = v->GetCurrentAltitude();
    EXPECT_EQ(t1, 3000);

    EXPECT_THROW(v->SetCurrentAltitude(25001), std::invalid_argument);
}

TEST(PLANE_SYSTEM_TEST, Plane_ConsumeDurability_Other) {
    auto v = std::make_shared<Plane>(
        "TEST_country",
        "TEST_model",
        10,
        VehicleType::PLANE,
        6,
        12
    );

    v->ConsumeDurability();
    EXPECT_EQ(v->GetDurability(), 0);

    EXPECT_THROW(v->ConsumeDurability(), std::runtime_error);
}

TEST(PLANE_SYSTEM_TEST, Plane_ConsumeDurability_Japan) {
    auto v = std::make_shared<Plane>(
        "Japan",
        "TEST_model",
        10,
        VehicleType::PLANE,
        6,
        12
    );

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 8);
}

TEST(PLANE_SYSTEM_TEST, Plane_ConsumeDurability_USA) {
    auto v = std::make_shared<Plane>(
        "USA",
        "TEST_model",
        30,
        VehicleType::PLANE,
        6,
        12
    );

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 0);
}

TEST(PLANE_SYSTEM_TEST, Constructor_exception) {
    EXPECT_THROW(
        Plane("USA", "TEST_model", -1, VehicleType::TRAIN, 0, 25000),
        std::invalid_argument
    );
    EXPECT_THROW(
        Plane("USA", "TEST_model", 0, VehicleType::TRAIN, -1, 25000),
        std::invalid_argument
    );
    EXPECT_THROW(
        Plane("USA", "TEST_model", 0, VehicleType::TRAIN, 0, -1),
        std::invalid_argument
    );
    EXPECT_THROW(
        Plane("USA", "TEST_model", 0, VehicleType::TRAIN, 25000, 0),
        std::invalid_argument
    );
    EXPECT_THROW(
        Plane("USA", "TEST_model", 0, VehicleType::TRAIN, 25000, 40001),
        std::invalid_argument
    );
}
