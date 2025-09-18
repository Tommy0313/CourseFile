#include "Furnace.hpp"

#include <stdexcept>

void Furnace::Smelt() {
    if(input == nullptr) {
        throw std::runtime_error("Furnace::Smelt: input is null");
    }
    if(output != nullptr) {
        throw std::runtime_error("Furnace::Smelt: input is null");
    }
    output = input->Smelt();
    input = nullptr;
}

void Furnace::SetInput(std::shared_ptr<ISmeltable> input) {
    this->input = input;
}

std::shared_ptr<Ingot> Furnace::GetOutput() {
    if(output == nullptr) {
        throw std::runtime_error("");
    }
    return output;
}

