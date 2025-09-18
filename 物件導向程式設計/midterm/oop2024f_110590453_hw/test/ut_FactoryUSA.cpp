#include <gtest/gtest.h>
#include <memory>

#include "Factory/FactoryUSA.h"

TEST(FACTORYUSA_SYSTEM_TEST, FactoryUSA_Train) {
    auto v = Factory::USA::ProduceTrain();

    EXPECT_EQ(v->GetCountry(), "USA");
    EXPECT_EQ(v->GetModel(), "Amtrak");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::TRAIN);
    EXPECT_EQ(v->GetCarriage(), 6);
    EXPECT_EQ(v->GetMaxCarriage(), 12);
}

TEST(FACTORYUSA_SYSTEM_TEST, FactoryUSA_Plane) {
    auto v = Factory::USA::ProducePlane();

    EXPECT_EQ(v->GetCountry(), "USA");
    EXPECT_EQ(v->GetModel(), "Boeing");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::PLANE);
    EXPECT_EQ(v->GetCurrentAltitude(), 0);
    EXPECT_EQ(v->GetMaxAltitude(), 12000);
}

TEST(FACTORYUSA_SYSTEM_TEST, FactoryUSA_Bus) {
    auto v = Factory::USA::ProduceBus();

    EXPECT_EQ(v->GetCountry(), "USA");
    EXPECT_EQ(v->GetModel(), "Ford");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::BUS);
    EXPECT_EQ(v->GetWheel(), 12);
    EXPECT_EQ(v->GetMaxSpeed(), 80);
}

TEST(FACTORYUSA_SYSTEM_TEST, FactoryUSA_Boat) {
    auto v = Factory::USA::ProduceBoat();

    EXPECT_EQ(v->GetCountry(), "USA");
    EXPECT_EQ(v->GetModel(), "Bayliner");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::BOAT);
    EXPECT_EQ(v->GetSailing(), false);
    EXPECT_EQ(v->GetMaxSpeed(), 30);
}
