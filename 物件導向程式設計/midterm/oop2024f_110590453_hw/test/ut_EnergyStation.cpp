#include <gtest/gtest.h>

#include "System/EnergyStation.hpp"

class TEST_vehicle final : public Vehicle {
public:
    TEST_vehicle()
        : Vehicle("TEST_country", "TEST_model", 0, VehicleType::TRAIN) {}

    virtual FuelType GetFuelType() override { return FuelType::Electricity; }

    virtual void ConsumeDurability() override {
        if (this->country == "Japan") {
            durability -= 10;
        } else if (this->country == "USA") {
            durability -= 10;
        } else {
            durability -= 10;
        }
    }

    virtual VehicleType GetVehicleType() override { return VehicleType::TRAIN; }
};

class TEST_vehicle_Fuel final : public Vehicle {
public:
    TEST_vehicle_Fuel()
        : Vehicle("TEST_country", "TEST_model", 0, VehicleType::TRAIN) {}

    virtual FuelType GetFuelType() override { return FuelType::Gasoline; }

    virtual void ConsumeDurability() override {
        if (this->country == "Japan") {
            durability -= 10;
        } else if (this->country == "USA") {
            durability -= 10;
        } else {
            durability -= 10;
        }
    }

    virtual VehicleType GetVehicleType() override { return VehicleType::TRAIN; }
};

TEST(ENERGYSTATION_SYSTEM_HPP, INITIALIZER) {
    auto e = EnergyStation();

    EXPECT_EQ(e.GetFuel(), 0);
    EXPECT_EQ(e.GetEnergy(), 0);
}

TEST(ENERGYSTATION_SYSTEM_HPP, Adder_Fuel_exception) {
    auto e = EnergyStation();

    EXPECT_THROW(e.AddEnergy(10001), std::invalid_argument);
}

TEST(ENERGYSTATION_SYSTEM_HPP, Adder_Fuel) {
    auto e = EnergyStation();

    e.AddFuel(100);
    EXPECT_EQ(e.GetFuel(), 100);

    e.AddFuel(200);
    EXPECT_EQ(e.GetFuel(), 300);

    EXPECT_THROW(e.AddFuel(2701), std::invalid_argument);
}

TEST(ENERGYSTATION_SYSTEM_HPP, Adder_Power_exception) {
    auto e = EnergyStation();

    EXPECT_THROW(e.AddEnergy(10001), std::invalid_argument);
}

TEST(ENERGYSTATION_SYSTEM_HPP, Adder_Power) {
    auto e = EnergyStation();

    e.AddEnergy(100);
    EXPECT_EQ(e.GetEnergy(), 100);

    e.AddEnergy(200);
    EXPECT_EQ(e.GetEnergy(), 300);

    EXPECT_THROW(e.AddEnergy(9701), std::invalid_argument);
}

TEST(ENERGYSTATION_SYSTEM_HPP, ChargeVehicle_Energy) {
    auto e = EnergyStation();
    auto v = std::dynamic_pointer_cast<Vehicle>(std::make_shared<TEST_vehicle>());

    e.AddEnergy(10000);
    e.AddFuel(3000);

    v->AddEnergy(990);
    EXPECT_EQ(v->GetEnergy(), 990);

    v->ConsumeDurability();
    e.ChargeVehicle(v);

    EXPECT_EQ(v->GetEnergy(), 1000);
    EXPECT_EQ(e.GetEnergy(), 9990);
    EXPECT_EQ(e.GetFuel(), 3000);
}

TEST(ENERGYSTATION_SYSTEM_HPP, ChargeVehicle_Fuel) {
    auto e = EnergyStation();
    auto v = std::dynamic_pointer_cast<Vehicle>(std::make_shared<TEST_vehicle_Fuel>());

    e.AddEnergy(10000);
    e.AddFuel(3000);
    v->AddEnergy(990);
    v->GetEnergy();

    EXPECT_EQ(v->GetEnergy(), 990);

    v->ConsumeDurability();
    e.ChargeVehicle(v);

    EXPECT_EQ(v->GetEnergy(), 1000);
    EXPECT_EQ(e.GetEnergy(), 10000);
    EXPECT_EQ(e.GetFuel(), 2990);
}
