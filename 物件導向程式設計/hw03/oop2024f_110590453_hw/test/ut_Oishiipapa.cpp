#include "OishiiPapa.hpp"
#include "Order.hpp"
#include <gtest/gtest.h>
#include <Ingredients.hpp>

TEST(OISHIIPAPA_TEST, check_papa_should_throw_exception_for_chest){
    OishiiPapa ohpapa;

    ASSERT_THROW(ohpapa.Pickup(),std::out_of_range);
}
TEST(OISHIIPAPA_TEST, check_papa_should_throw_exception_for_pipeline){
    OishiiPapa ohpapa;

    ASSERT_THROW(ohpapa.MakeDish(),std::out_of_range);
}
TEST(OISHIIPAPA_TEST, check_papa_should_take_care_of_pickup){
    //Make Object Oishii Papa.
    OishiiPapa ohpapa;

    //Production.
    std::vector<Production> product1 = {Production::PorkBurger,Production::_NULL,Production::_NULL};
    std::vector<Production> product2 = {Production::FishBurger,Production::_NULL,Production::_NULL};
    std::vector<Production> product3 = {Production::BeefBurger,Production::_NULL,Production::_NULL};
    std::vector<Production> product4 = {Production::_NULL,Production::Frenchfries,Production::_NULL};
    std::vector<Production> product5 = {Production::_NULL,Production::Nugget,Production::_NULL};
    std::vector<Production> product6 = {Production::_NULL,Production::Salad,Production::_NULL};
    std::vector<Production> product7 = {Production::_NULL,Production::_NULL,Production::Spirit};
    std::vector<Production> product8 = {Production::_NULL,Production::_NULL,Production::Cola};
    std::vector<Production> product9 = {Production::_NULL,Production::_NULL,Production::CaramelMilktea};
    std::vector<Production> product10 = {Production::_NULL,Production::_NULL,Production::Latte};
    std::vector<Production> product11 = {Production::PorkBurger,Production::_NULL,Production::Cola};
    std::vector<Production> product12 = {Production::FishBurger,Production::Frenchfries,Production::CaramelMilktea};
    std::vector<Production> product13 = {Production::BeefBurger,Production::Nugget,Production::Cola};
    std::vector<Production> product14 = {Production::FishBurger,Production::Salad,Production::Spirit};
    std::vector<Production> product15 = {Production::BeefBurger,Production::Salad,Production::Latte};
    std::vector<Production> product16 = {Production::PorkBurger,Production::Nugget,Production::Cola};
    std::vector<Production> product17 = {Production::PorkBurger,Production::Frenchfries,Production::_NULL};
    //Addtional Ingredients.
    std::vector<Ingredients> additional1 = {Ingredients::Lattuce,Ingredients::Cheese};
    std::vector<Ingredients> additional2 = {Ingredients::PorkSteak,Ingredients::Cheese};
    std::vector<Ingredients> additional3 = {Ingredients::FishSteak,Ingredients::Lattuce};
    std::vector<Ingredients> additional4 = {Ingredients::BeefSteak,Ingredients::BeefSteak};
    std::vector<Ingredients> additional5 = {Ingredients::Lattuce,Ingredients::PorkSteak,Ingredients::Cheese};
    std::vector<Ingredients> additional6 = {Ingredients::Lattuce,Ingredients::PorkSteak,Ingredients::FishSteak};
    std::vector<Ingredients> additional7 = {Ingredients::Lattuce,Ingredients::BeefSteak};
    std::vector<Ingredients> additional8 = {};
    //If larger.
    std::vector<bool> condition1 = {true, true};
    std::vector<bool> condition2 = {true, false};
    std::vector<bool> condition3 = {false, true};
    std::vector<bool> condition4 = {false, false};
    //Make order object.
    Order OrderList1(product1,additional1,condition4);
    Order OrderList2(product2,additional2,condition4);
    Order OrderList3(product3,additional3,condition4);
    Order OrderList4(product4,additional8,condition2);
    Order OrderList5(product5,additional8,condition2);
    Order OrderList6(product6,additional8,condition4);
    Order OrderList7(product7,additional8,condition4);
    Order OrderList8(product8,additional8,condition3);
    Order OrderList9(product9,additional8,condition4);
    Order OrderList10(product10,additional8,condition3);
    Order OrderList11(product11,additional1,condition3);
    Order OrderList12(product12,additional2,condition2);
    Order OrderList13(product13,additional3,condition1);
    Order OrderList14(product14,additional4,condition3);
    Order OrderList15(product15,additional5,condition3);
    Order OrderList16(product16,additional6,condition4);
    Order OrderList17(product16,additional7,condition1);
    Order OrderList18(product16,additional8,condition1);
    Order OrderList19(product15,additional8,condition3);
    Order OrderList20(product17,additional1,condition2);

    //Test.
    ohpapa.SendOrder(OrderList1);
    ohpapa.SendOrder(OrderList2);
    ohpapa.SendOrder(OrderList3);
    ohpapa.SendOrder(OrderList4);
    ohpapa.SendOrder(OrderList5);
    ohpapa.SendOrder(OrderList6);
    ohpapa.SendOrder(OrderList7);
    ohpapa.SendOrder(OrderList8);
    ohpapa.SendOrder(OrderList9);
    ohpapa.SendOrder(OrderList10);
    ohpapa.SendOrder(OrderList11);
    ohpapa.SendOrder(OrderList12);
    ohpapa.SendOrder(OrderList13);
    ohpapa.SendOrder(OrderList14);
    ohpapa.SendOrder(OrderList15);
    ohpapa.SendOrder(OrderList16);
    ohpapa.SendOrder(OrderList17);
    ohpapa.SendOrder(OrderList18);
    ohpapa.SendOrder(OrderList19);
    ohpapa.SendOrder(OrderList20);
    //Result.

    Package pack;
    MainDish pb(Production::PorkBurger);
    pb.AddIngredients(additional1);
    pack.SetMainDish(pb);
    pack.CountMoney();

    auto tmp = ohpapa.Pickup();

    ASSERT_EQ(tmp.GetMoney(),pack.GetMoney());
    ASSERT_EQ(ohpapa.GetMoney(),pack.GetMoney());
}
TEST(OISHIIPAPA_TEST, check_papa_should_take_care_of_pickup_part2){
    //Make Object Oishii Papa.
    OishiiPapa ohpapa;

    //Production.
    std::vector<Production> product1 = {Production::PorkBurger,Production::_NULL,Production::_NULL};
    std::vector<Production> product2 = {Production::FishBurger,Production::_NULL,Production::_NULL};
    std::vector<Production> product3 = {Production::BeefBurger,Production::_NULL,Production::_NULL};
    std::vector<Production> product4 = {Production::_NULL,Production::Frenchfries,Production::_NULL};
    std::vector<Production> product5 = {Production::_NULL,Production::Nugget,Production::_NULL};
    std::vector<Production> product6 = {Production::_NULL,Production::Salad,Production::_NULL};
    std::vector<Production> product7 = {Production::_NULL,Production::_NULL,Production::Spirit};
    std::vector<Production> product8 = {Production::_NULL,Production::_NULL,Production::Cola};
    std::vector<Production> product9 = {Production::_NULL,Production::_NULL,Production::CaramelMilktea};
    std::vector<Production> product10 = {Production::_NULL,Production::_NULL,Production::Latte};
    std::vector<Production> product11 = {Production::PorkBurger,Production::_NULL,Production::Cola};
    std::vector<Production> product12 = {Production::FishBurger,Production::Frenchfries,Production::CaramelMilktea};
    std::vector<Production> product13 = {Production::BeefBurger,Production::Nugget,Production::Cola};
    std::vector<Production> product14 = {Production::FishBurger,Production::Salad,Production::Spirit};
    std::vector<Production> product15 = {Production::BeefBurger,Production::Salad,Production::Latte};
    std::vector<Production> product16 = {Production::PorkBurger,Production::Nugget,Production::Cola};
    std::vector<Production> product17 = {Production::PorkBurger,Production::Frenchfries,Production::_NULL};
    //Addtional Ingredients.
    std::vector<Ingredients> additional1 = {Ingredients::Lattuce,Ingredients::Cheese};
    std::vector<Ingredients> additional2 = {Ingredients::PorkSteak,Ingredients::Cheese};
    std::vector<Ingredients> additional3 = {Ingredients::FishSteak,Ingredients::Lattuce};
    std::vector<Ingredients> additional4 = {Ingredients::BeefSteak,Ingredients::BeefSteak};
    std::vector<Ingredients> additional5 = {Ingredients::Lattuce,Ingredients::PorkSteak,Ingredients::Cheese};
    std::vector<Ingredients> additional6 = {Ingredients::Lattuce,Ingredients::PorkSteak,Ingredients::FishSteak};
    std::vector<Ingredients> additional7 = {Ingredients::Lattuce,Ingredients::BeefSteak};
    std::vector<Ingredients> additional8 = {};
    //If larger.
    std::vector<bool> condition1 = {true, true};
    std::vector<bool> condition2 = {true, false};
    std::vector<bool> condition3 = {false, true};
    std::vector<bool> condition4 = {false, false};
    //Make order object.
    Order OrderList1(product1,additional1,condition4);
    Order OrderList2(product2,additional2,condition4);
    Order OrderList3(product3,additional3,condition4);
    Order OrderList4(product4,additional8,condition2);
    Order OrderList5(product5,additional8,condition2);
    Order OrderList6(product6,additional8,condition4);
    Order OrderList7(product7,additional8,condition4);
    Order OrderList8(product8,additional8,condition3);
    Order OrderList9(product9,additional8,condition4);
    Order OrderList10(product10,additional8,condition3);
    Order OrderList11(product11,additional1,condition3);
    Order OrderList12(product12,additional2,condition2);
    Order OrderList13(product13,additional3,condition1);
    Order OrderList14(product14,additional4,condition3);
    Order OrderList15(product15,additional5,condition3);
    Order OrderList16(product16,additional6,condition4);
    Order OrderList17(product16,additional7,condition1);
    Order OrderList18(product16,additional8,condition1);
    Order OrderList19(product15,additional8,condition3);
    Order OrderList20(product17,additional1,condition2);

    //Test.
    ohpapa.SendOrder(OrderList1);
    ohpapa.SendOrder(OrderList2);
    ohpapa.SendOrder(OrderList3);
    ohpapa.SendOrder(OrderList4);
    ohpapa.SendOrder(OrderList5);
    ohpapa.SendOrder(OrderList6);
    ohpapa.SendOrder(OrderList7);
    ohpapa.SendOrder(OrderList8);
    ohpapa.SendOrder(OrderList9);
    ohpapa.SendOrder(OrderList10);
    ohpapa.SendOrder(OrderList11);
    ohpapa.SendOrder(OrderList12);
    ohpapa.SendOrder(OrderList13);
    ohpapa.SendOrder(OrderList14);
    ohpapa.SendOrder(OrderList15);
    ohpapa.SendOrder(OrderList16);
    ohpapa.SendOrder(OrderList17);
    ohpapa.SendOrder(OrderList18);
    ohpapa.SendOrder(OrderList19);
    ohpapa.SendOrder(OrderList20);
    //Result.

    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();
    ohpapa.Pickup();

    ASSERT_EQ(ohpapa.GetMoney(),2317);
}