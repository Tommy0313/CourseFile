
#include <gtest/gtest.h>
#include <memory>

#include "Object/Train.h"

TEST(TRAIN_SYSTEM_TEST, Train_Constructor) {
    auto v = std::make_shared<Train>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::TRAIN,
        6,
        12
    );

    auto t1 = v->GetFuelType();
    auto t2 = v->GetVehicleType();
    auto t3 = v->GetCountry();
    auto t4 = v->GetModel();
    auto t5 = v->GetCarriage();
    auto t6 = v->GetMaxCarriage();

    EXPECT_EQ(t1, FuelType::Electricity);
    EXPECT_EQ(t2, VehicleType::TRAIN);
    EXPECT_EQ(t3, "TEST_country");
    EXPECT_EQ(t4, "TEST_model");
    EXPECT_EQ(t5, 6);
    EXPECT_EQ(t6, 12);
}

TEST(TRAIN_SYSTEM_TEST, Train_Carriage) {
    auto v = std::make_shared<Train>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::TRAIN,
        6,
        12
    );
    EXPECT_EQ(v->GetCarriage(), 6);
    EXPECT_EQ(v->GetMaxCarriage(), 12);

    v->SetCarriage(10);
    EXPECT_EQ(v->GetCarriage(), 10);

    EXPECT_THROW(v->SetCarriage(13), std::invalid_argument);
    EXPECT_THROW(v->SetCarriage(-1), std::invalid_argument);
}

TEST(TRAIN_SYSTEM_TEST, Train_MaxCarriage) {
    auto v = std::make_shared<Train>(
        "TEST_country",
        "TEST_model",
        0,
        VehicleType::TRAIN,
        6,
        12
    );

    v->SetMaxCarriage(8);
    EXPECT_EQ(v->GetMaxCarriage(), 8);

    EXPECT_THROW(v->SetMaxCarriage(13), std::invalid_argument);
    EXPECT_THROW(v->SetMaxCarriage(-1), std::invalid_argument);
}

TEST(TRAIN_SYSTEM_TEST, Train_ConsumeDurability_Other) {
    auto v = std::make_shared<Train>(
        "TEST_country",
        "TEST_model",
        10,
        VehicleType::TRAIN,
        6,
        12
    );
    EXPECT_EQ(v->GetDurability(), 10);

    v->ConsumeDurability();
    EXPECT_EQ(v->GetDurability(), 0);
}

TEST(TRAIN_SYSTEM_TEST, Train_ConsumeDurability_Japan) {
    auto v = std::make_shared<Train>(
        "Japan",
        "TEST_model",
        10,
        VehicleType::TRAIN,
        6,
        12
    );

    v->ConsumeDurability();  // times one
    EXPECT_EQ(v->GetDurability(), 5);

    v->ConsumeDurability();                                    // times two
    EXPECT_THROW(v->ConsumeDurability(), std::runtime_error);  // times three
}

TEST(TRAIN_SYSTEM_TEST, Train_ConsumeDurability_USA) {
    auto v = std::make_shared<Train>(
        "USA",
        "TEST_model",
        10,
        VehicleType::TRAIN,
        6,
        12
    );

    v->ConsumeDurability();
    auto t1 = v->GetDurability();
    EXPECT_EQ(t1, 6);
}

TEST(TRAIN_SYSTEM_TEST, Constructor_exception) {
    EXPECT_THROW(
        Train("USA", "TEST_model", -1, VehicleType::TRAIN, 6, 12),
        std::invalid_argument
    );
    EXPECT_THROW(
        Train("USA", "TEST_model", 0, VehicleType::TRAIN, -1, 12),
        std::invalid_argument
    );
    EXPECT_THROW(
        Train("USA", "TEST_model", 0, VehicleType::TRAIN, 0, -1),
        std::invalid_argument
    );
    EXPECT_THROW(
        Train("USA", "TEST_model", 0, VehicleType::TRAIN, 12, 6),
        std::invalid_argument
    );
}
