#include <gtest/gtest.h>
#include <memory>
#include "Object/Vehicle.h"
#include "System/MaintenanceSystem.hpp"

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

TEST(MAINTENANCE_SYSTEM_TEST, RepairVehicle) {
    auto v = std::make_shared<TEST_vehicle>();
    std::shared_ptr<Vehicle> v1 = std::dynamic_pointer_cast<Vehicle>(v);
    v1->AddDurability(100);

    v1->ConsumeDurability();
    EXPECT_EQ(v1->GetDurability(), 90);

    RepairVehicle(v1);

    EXPECT_EQ(v1->GetDurability(), 100);
}