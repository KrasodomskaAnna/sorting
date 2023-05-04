#ifndef SORTING_VECTOR_H
#define SORTING_VECTOR_H

#include <iostream>

class Vector {
public:
    Vector();

    Vector(const Vector& from);
    Vector& operator=(const Vector& other);
    bool operator<=(const Vector& other);
    bool operator>=(const Vector& other);

    void push_back(int elementToAdd);
    int& operator [] (int id);
    int size();
    void print();
    ~Vector();
protected:
    int* intArray;
    int intArraySize;
};

Vector::Vector() {
    this->intArray = new int[0]();
    this->intArraySize = 0;
}

Vector::Vector(const Vector& from) {
    this->intArray = new int[from.intArraySize];
    for (int i = 0; i < from.intArraySize; i++) {
        this->intArray[i] = from.intArray[i];
    }
    intArraySize = from.intArraySize;
}

void Vector::push_back(int elementToAdd) {
    int* newArray = new int[this->intArraySize + 1]();
    for (int i = 0; i < this->intArraySize; i++) {
        newArray[i] = this->intArray[i];
    }
    newArray[this->intArraySize] = elementToAdd;
    delete[] this->intArray;
    this->intArray = newArray;
    this->intArraySize++;
}

void Vector::print() {
    for (int i = 0; i < size(); i++) {
        std::cout << intArray[i];
    }
}

int& Vector::operator[](int id) {
    return this->intArray[id];
}

int Vector::size() {
    return this->intArraySize;
}

Vector::~Vector() {
    delete[] this->intArray;
}

Vector& Vector::operator=(const Vector& other) {
    this->intArray = new int[other.intArraySize];
    for (int i = 0; i < other.intArraySize; i++) {
        this->intArray[i] = other.intArray[i];
    }
    intArraySize = other.intArraySize;
    return *this;
}

bool Vector::operator<=(const Vector& other) {
    // if this > other return false
    if (intArraySize > other.intArraySize) return false;
    else if (intArraySize == other.intArraySize) {
        for (int i = 0; i < intArraySize; i++) {
            if (intArray[i] > other.intArray[i]) return false;
            if (intArray[i] < other.intArray[i]) return true;
        }
    }
    return true;
}

bool Vector::operator>=(const Vector& other) {
    // if this < other return false
    if (intArraySize < other.intArraySize) return false;
    else if (intArraySize == other.intArraySize) {
        for (int i = 0; i < intArraySize; i++) {
            if (intArray[i] < other.intArray[i]) return false;
            if (intArray[i] > other.intArray[i]) return true;
        }
    }
    return true;
}

#endif //SORTING_VECTOR_H
