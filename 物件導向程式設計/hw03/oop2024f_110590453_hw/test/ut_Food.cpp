#include <gtest/gtest.h>
#include <vector>
#include "MainDish.hpp"
#include "SideDish.hpp"
#include "Drink.hpp"

TEST(MAINDISH_TEST, check_maindish_should_have_correct_id){
    MainDish mainDish(Production::BeefBurger);

    Production product = mainDish.getId();

    ASSERT_EQ(product,Production::BeefBurger);
}
TEST(MAINDISH_TEST, check_maindish_should_have_correct_money){
    MainDish mainDish(Production::FishBurger);

    int price = mainDish.GetMoney();

    ASSERT_EQ(price,79);
}
TEST(MAINDISH_TEST, check_maindish_should_have_correct_ingredients){
    MainDish mainDish(Production::FishBurger);

    auto ingredients = mainDish.GetIngredient();

    ASSERT_EQ(ingredients[0],Ingredients::FishSteak);
    ASSERT_EQ(ingredients[1],Ingredients::Lattuce);
    ASSERT_EQ(ingredients[2],Ingredients::BurgerBread);
    ASSERT_EQ(ingredients[3],Ingredients::Cheese);
}
TEST(MAINDISH_TEST, check_maindish_should_throw_invalid_argument_for_additional_food){
    MainDish mainDish(Production::FishBurger);
    std::vector<Ingredients> addition = {Ingredients::Lattuce,Ingredients::Caramel};

    ASSERT_THROW(mainDish.AddIngredients(addition),std::invalid_argument);
}

TEST(MAINDISH_TEST, check_maindish_should_throw_invalid_argument_for_additional_food_two){
    MainDish mainDish(Production::FishBurger);
    std::vector<Ingredients> addition = {
        Ingredients::Cola,
        Ingredients::Caramel,
        Ingredients::ChickenNugget,
        Ingredients::Lattuce,
        Ingredients::Milk,
        Ingredients::Milktea,
        Ingredients::Spirit,
    };

    ASSERT_THROW(mainDish.AddIngredients(addition),std::invalid_argument);
}
TEST(MAINDISH_TEST, check_maindish_should_have_correct_money_after_get_addtional_food){
    MainDish mainDish(Production::FishBurger);
    std::vector<Ingredients> addition = {Ingredients::Lattuce,Ingredients::FishSteak};

    mainDish.AddIngredients(addition);
    int price = mainDish.GetMoney();

    ASSERT_EQ(price,109);
}
TEST(MAINDISH_TEST, check_maindish_should_have_correct_money_after_get_addtional_food_two){
    MainDish mainDish(Production::FishBurger);
    std::vector<Ingredients> addition = {
        Ingredients::Lattuce,
        Ingredients::FishSteak,
        Ingredients::BeefSteak,
        Ingredients::Cheese,
    };

    mainDish.AddIngredients(addition);
    int price = mainDish.GetMoney();

    ASSERT_EQ(price,139);
}
TEST(SIDEDISH_TEST, check_sidedish_should_have_correct_id){
    SideDish sidedish(Production::Frenchfries);

    Production product = sidedish.getId();

    ASSERT_EQ(product,Production::Frenchfries);
}
TEST(SIDEDISH_TEST, check_sidedish_is_small){
    SideDish sidedish(Production::Nugget);

    SideDishType product = sidedish.GetType();

    ASSERT_EQ(product,SideDishType::SMALL);
}

TEST(SIDEDISH_TEST, check_sidedish_can_make_larger){
    SideDish sidedish(Production::Frenchfries);
    sidedish.MakeLarger();

    SideDishType product = sidedish.GetType();

    ASSERT_EQ(product,SideDishType::BIG);
}

TEST(SIDEDISH_TEST, check_sidedish_make_larger_maintain_same){
    SideDish sidedish(Production::Salad);

    sidedish.MakeLarger();
    SideDishType product = sidedish.GetType();

    ASSERT_EQ(product,SideDishType::SMALL);
}
TEST(DRINK_TEST,check_drink_have_correct_id){
    Drink drink(Production::Latte);

    Production product = drink.getId();

    ASSERT_EQ(product,Production::Latte);
}
TEST(DRINK_TEST,check_drink_have_correct_price){
    Drink drink(Production::CaramelMilktea);

    int price = drink.GetMoney();

    ASSERT_EQ(price,44);
}
TEST(DRINK_TEST,check_drink_make_larger){
    Drink drink(Production::Cola);
    drink.MakeLarger();

    int cc = drink.GetMl();

    ASSERT_EQ(cc,750);
}