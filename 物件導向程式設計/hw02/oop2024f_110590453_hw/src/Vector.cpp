
#include "Vector.hpp"

#include <algorithm>
#include <stdexcept>

Vector::Vector(const Vector &other)
    : m_Size(other.m_Size),
      m_Capacity(other.m_Capacity),
      m_Data(m_Capacity ? new int[other.m_Capacity] : nullptr) {
    std::copy(&other.m_Data[0], &other.m_Data[other.GetSize()], m_Data);
}

Vector::Vector(Vector &&other) noexcept //
    : Vector() {                        //
    swap(*this, other);
}

void swap(Vector &v1, Vector &v2) {
    std::swap(v1.m_Size, v2.m_Size);
    std::swap(v1.m_Capacity, v2.m_Capacity);
    std::swap(v1.m_Data, v2.m_Data);
}

Vector &Vector::operator=(const Vector &other) {
    Vector tmp(other);
    swap(*this, tmp);
    return *this;
}

Vector &Vector::operator=(Vector &&other) noexcept {
    swap(*this, other);
    return *this;
}

Vector::~Vector() {
    delete[] m_Data;
}

int Vector::GetSize() const {
    return m_Size;
}

int Vector::GetCapacity() const {
    return m_Capacity;
}

void Vector::Append(int value) {
    if (m_Capacity <= m_Size) {
        Resize();
    }

    m_Data[m_Size] = value;

    m_Size += 1;
}

void Vector::InsertAt(int index, int value) {
    if (index >= m_Size) {
        throw std::out_of_range(
            "[Class: Vector][Method: Join] message: out of range");
    }

    if (m_Capacity <= m_Size) {
        Resize();
    }

    for (int i = m_Size; i > index; i--) {
        m_Data[i] = m_Data[i - 1];
    }
    m_Data[index] = value;

    m_Size += 1;
    

}

void Vector::UpdateAt(int index, int value) {
    if (index >= m_Size) {
        throw std::out_of_range(
            "[Class: Vector][Method: Join] message: out of range");
    }

    m_Data[index] = value;
}

void Vector::RemoveAt(int index) {
    if (index >= m_Size) {
        throw std::out_of_range(
            "[Class: Vector][Method: Join] message: out of range");
    }

    for (int i = index; i < m_Size-1; i++) {
        m_Data[i] = m_Data[i+1];
    }

    m_Size -= 1;
}

int Vector::At(int index) const {
    if (index >= m_Size) {
        throw std::out_of_range(
            "[Class: Vector][Method: Join] message: out of range");
    } else {
        return m_Data[index];
    }
}

void Vector::Join(const Vector &other) {
    for (int i = 0; i < other.m_Size; i++) {
        Append(other.At(i));
    }
}

void Vector::Resize() {
    // 定義 m_Capacity 的賦值
    if (m_Capacity == 0) {
        m_Capacity = 4;
    } else {
        m_Capacity *= 2;
    }

    // 新增動態記憶體
    int *tmp = new int[m_Capacity]; // 或者使用: int *tmp =
                                    // (int*)malloc(sizeof(int) * m_Capacity);

    // 將資料搬移進入新增的動態記憶體
    for (int i = 0; i < m_Size; i++) {
        tmp[i] = m_Data[i];
    }

    // 刪除舊有的記憶體
    delete[] m_Data; // 或者使用: free(tmp);

    // 重新指向 tmp
    m_Data = tmp;
}