//
// Created by adven on 11/7/2024.
//

#include <gtest/gtest.h>
#include <memory>

#include "Object/Vehicle.h"

class TEST_vehicle final : public Vehicle {
public:
    TEST_vehicle()
        : Vehicle("TEST_country", "TEST_model", 0, VehicleType::TRAIN) {}

    TEST_vehicle(int value)
        : Vehicle("TEST_country", "TEST_model", value, VehicleType::TRAIN) {}

    virtual FuelType GetFuelType() override { return FuelType::Electricity; }

    virtual void ConsumeDurability() override {
        if (this->country == "Japan") {
            durability -= 5;
        } else if (this->country == "USA") {
            durability -= 4;
        } else {
            durability -= 10;
        }
    }

    virtual VehicleType GetVehicleType() override { return type; }
};

TEST(VEHICLE_SYSTEM_TEST, Vehicle_Constructor) {
    auto v = std::make_shared<TEST_vehicle>();

    auto t1 = v->GetFuelType();
    auto t2 = v->GetVehicleType();
    auto t3 = v->GetCountry();
    auto t4 = v->GetModel();

    EXPECT_EQ(t1, FuelType::Electricity);
    EXPECT_EQ(t2, VehicleType::TRAIN);
    EXPECT_EQ(t3, "TEST_country");
    EXPECT_EQ(t4, "TEST_model");
}

TEST(VEHICLE_SYSTEM_TEST, Vehicle_IsDurabilityZero) {
    auto v = std::make_shared<TEST_vehicle>();

    auto t1 = v->IsDurabilityZero();
    EXPECT_EQ(t1, true);
}

TEST(VEHICLE_SYSTEM_TEST, Vehicle_AddDurability) {
    auto v = std::make_shared<TEST_vehicle>();

    v->AddDurability(10);
    auto t2 = v->GetDurability();

    EXPECT_EQ(t2, 10);

    v->AddDurability(20);
    EXPECT_EQ(v->GetDurability(), 30);
}

TEST(VEHICLE_SYSTEM_TEST, Vehicle_AddDurability_Exception) {
    auto v = std::make_shared<TEST_vehicle>();

    EXPECT_THROW(v->AddDurability(-1), std::invalid_argument);
    EXPECT_THROW(v->AddDurability(101), std::invalid_argument);
}

TEST(VEHICLE_SYSTEM_TEST, Vehicle_AddEnergy) {
    auto v = std::make_shared<TEST_vehicle>();

    v->AddEnergy(100);
    EXPECT_EQ(v->GetEnergy(), 100);

    v->AddEnergy(200);
    EXPECT_EQ(v->GetEnergy(), 300);
}

TEST(VEHICLE_SYSTEM_TEST, Vehicle_AddEnergy_Exception) {
    auto v = std::make_shared<TEST_vehicle>();

    EXPECT_THROW(v->AddEnergy(-1), std::invalid_argument);
    EXPECT_THROW(v->AddEnergy(1001), std::invalid_argument);
}

TEST(VEHICLE_SYSTEM_TEST, Vehicle_ConsumeDurability_Other) {
    auto v = std::make_shared<TEST_vehicle>();

    v->AddDurability(10);
    v->ConsumeDurability();
    EXPECT_EQ(v->GetDurability(), 0);
}

TEST(VEHICLE_SYSTEM_TEST, Durability_exception_01) {
    EXPECT_THROW(TEST_vehicle(-1), std::invalid_argument);
}
