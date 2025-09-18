//
// Created by adven on 12/2/2024.
//

#ifndef OOP_LIST_INL
#define OOP_LIST_INL

#if TESTING_TARGET2
template <typename T>
int List<T>::GetLength() {
    return data.size();
}

template <typename T>
void List<T>::AddElement(T elem) {
    data.push_back(elem);
}

template <typename T>
T List<T>::PopElement() {
    T temp = data.back();
    data.pop_back();
    return temp;
}

template <typename T>
T List<T>::front() {
    return data.front();
}

template <typename T>
typename std::vector<T>::iterator List<T>::begin() {
    return data.begin();
}

template <typename T>
typename std::vector<T>::iterator List<T>::end() {
    return data.end();
}



template class List<int>;

#endif
#endif //OOP_LIST_INL
