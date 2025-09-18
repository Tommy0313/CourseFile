//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_VECTOR_HPP
#define OOP_VECTOR_HPP

#include "Config.hpp"

#if TESTING_TARGET2
#include <vector>

template <typename T>
class List {
private:
    /* member */
public:
    int GetLength();

    void AddElement(T elem);

    T PopElement();
};

#include "List.inl"

#endif

#endif // OOP_VECTOR_HPP
