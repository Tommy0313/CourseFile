#include <gtest/gtest.h>
#include <memory>

#include "Factory/FactoryJapan.h"
#include "Object/Plane.h"

TEST(FACTORYJAPAN_SYSTEM_TEST, FactoryJapn_Train) {
    auto v = Factory::Japan::ProduceTrain();

    EXPECT_EQ(v->GetCountry(), "Japan");
    EXPECT_EQ(v->GetModel(), "Toyota");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::TRAIN);
    EXPECT_EQ(v->GetCarriage(), 6);
    EXPECT_EQ(v->GetMaxCarriage(), 12);
}

TEST(FACTORYJAPAN_SYSTEM_TEST, FactoryJapn_Plane) {
    auto v = Factory::Japan::ProducePlane();

    EXPECT_EQ(v->GetCountry(), "Japan");
    EXPECT_EQ(v->GetModel(), "Mitsubishi");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::PLANE);
    EXPECT_EQ(v->GetCurrentAltitude(), 0);
    EXPECT_EQ(v->GetMaxAltitude(), 12000);
}

TEST(FACTORYJAPAN_SYSTEM_TEST, FactoryJapn_Bus) {
    auto v = Factory::Japan::ProduceBus();

    EXPECT_EQ(v->GetCountry(), "Japan");
    EXPECT_EQ(v->GetModel(), "Yamaha");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::BUS);
    EXPECT_EQ(v->GetWheel(), 12);
    EXPECT_EQ(v->GetMaxSpeed(), 80);
}

TEST(FACTORYJAPAN_SYSTEM_TEST, FactoryJapn_Boat) {
    auto v = Factory::Japan::ProduceBoat();

    EXPECT_EQ(v->GetCountry(), "Japan");
    EXPECT_EQ(v->GetModel(), "Shinkansen");
    EXPECT_EQ(v->GetDurability(), 0);
    EXPECT_EQ(v->GetVehicleType(), VehicleType::BOAT);
    EXPECT_EQ(v->GetSailing(), false);
    EXPECT_EQ(v->GetMaxSpeed(), 30);
}