#include <gtest/gtest.h>
#include <vector>
#include "Package.hpp"

TEST(PACKAGE_TEST, check_package_should_have_correct_money){
    Package pack;
    MainDish maindish(Production::PorkBurger);
    SideDish sidedish(Production::Frenchfries);

    pack.SetMainDish(maindish);
    pack.SetSideDish(sidedish);
    pack.CountMoney();

    int price = pack.GetMoney();

    ASSERT_EQ(price,103);
}

TEST(PACKAGE_TEST, check_package_should_have_correct_money_for_pack){
    Package pack;
    MainDish maindish(Production::PorkBurger);
    SideDish sidedish(Production::Frenchfries);
    Drink drink(Production::Cola);
    drink.MakeLarger();

    pack.SetMainDish(maindish);
    pack.SetSideDish(sidedish);
    pack.SetDrink(drink);
    pack.CountMoney();

    int price = pack.GetMoney();

    ASSERT_EQ(maindish.GetMoney(),59);
    ASSERT_EQ(sidedish.GetMoney(),44);
    ASSERT_EQ(drink.GetMoney(),38);
    ASSERT_EQ(price,126);
}

TEST(PACKAGE_TEST, check_package_should_have_correct_money_for_only_a_thing){
    Package pack;
    MainDish maindish(Production::PorkBurger);


    pack.SetMainDish(maindish);
    pack.CountMoney();

    int price = pack.GetMoney();

    ASSERT_EQ(maindish.GetMoney(),59);
    ASSERT_EQ(price,59);
}