#include "CraftingTable.hpp"

#include <stdexcept>

void CraftingTable::CraftArmor() {
    if(input == nullptr) {
        throw std::runtime_error("Furnace::Smelt: input is null");
    }
    if(output != nullptr) {
        throw std::runtime_error("Furnace::Smelt: input is null");
    }
    output = std::make_shared<Armor>(input->CraftArmor());
    input = nullptr;
}

void CraftingTable::SetInput(std::shared_ptr<ICraftable> input) {
    this->input = input;
}

std::shared_ptr<Armor> CraftingTable::GetOutput() {
    if(output == nullptr) {
        throw std::runtime_error("");
    }
    return output;
}


