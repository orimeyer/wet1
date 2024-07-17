#include "Pair.h"

// Constructor
Pair::Pair(int id, int treasure) : id(id), treasure(treasure) {}
Pair::Pair(const Pair& other) {
    id = other.id;
    treasure = other.treasure;
}

// Getters
int Pair::getId() const {
    return id;
}

int Pair::getTreasure() const {
    return treasure;
}

// Setters
void Pair::setId(int id) {
    this->id = id;
}

void Pair::setTreasure(int treasure) {
    this->treasure = treasure;
}

Pair& Pair::operator=(const Pair& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    id = other.id;
    treasure = other.treasure;
    return *this;
}    

// Overloading the '>' operator
bool Pair::operator>(const Pair& other) const {
    return (this->treasure > other.treasure) || 
           ((this->treasure == other.treasure) && (this->id > other.id));
}

// Overloading the '<' operator
bool Pair::operator<(const Pair& other) const {
    return (this->treasure < other.treasure) || 
           ((this->treasure == other.treasure) && (this->id < other.id));
}
