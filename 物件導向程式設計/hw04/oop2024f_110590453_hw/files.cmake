
set(SRC_FILES
        Ore.cpp
        SmeltableOre.cpp

        CoalOre.cpp
        IronOre.cpp
        GoldOre.cpp
        DiamondOre.cpp

        Furnace.cpp
)

set(INCLUDE_FILES
        Config.hpp

        Ore.hpp
        SmeltableOre.hpp
        CoalOre.hpp
        IronOre.hpp
        GoldOre.hpp
        DiamondOre.hpp

        Product.hpp
        Pickaxe.hpp

        Furnace.hpp

        List.hpp
        List.inl
)


set(TEST_FILES

        Ore_test.cpp
        IronOre_test.cpp
        CoalOre_test.cpp
        GoldOre_test.cpp
        DiamondOre_test.cpp

        Furnace_test.cpp
        List_test.cpp
)
