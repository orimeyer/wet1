#include "Pair.h"

// Constructor
Pair::Pair(int id, int treasure) : id(id), treasure(treasure) {}

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
