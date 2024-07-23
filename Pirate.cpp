#include "Pirate.h"
#include "Ship.h" // Include after forward declaration

// Constructor
Pirate::Pirate(int pirateId, int shipId, int treasure)
    : pirateId(pirateId), shipId(shipId), treasure(treasure), pointer_to_ship(nullptr), pointer_to_queue(nullptr) {}

// Destructor
Pirate::~Pirate() {
    pointer_to_ship = nullptr;
    pointer_to_queue = nullptr;
}

// Copy constructor
Pirate::Pirate(const Pirate& other)
    : pirateId(other.pirateId), shipId(other.shipId), treasure(other.treasure),
      pointer_to_ship(other.pointer_to_ship), pointer_to_queue(other.pointer_to_queue) {}

// Getters
int Pirate::getPirateId() const {
    return pirateId;
}

int Pirate::getShipId() const {
    return shipId;
}

int Pirate::getTreasure() const {
    return treasure;
}

Ship* Pirate::getPointerToShip() const {
    return pointer_to_ship;
}

Node* Pirate::getPointerToQueue() const {
    return pointer_to_queue;
}

// Setters
void Pirate::setPirateId(int pirateId) {
    this->pirateId = pirateId;
}

void Pirate::setShipId(int shipId) {
    this->shipId = shipId;
}

void Pirate::setTreasure(int treasure) {
    this->treasure = treasure;
}

void Pirate::setPointerToShip(Ship* pointer_to_ship) {
    this->pointer_to_ship = pointer_to_ship;
}

void Pirate::setPointerToQueue(Node* pointer_to_queue) {
    this->pointer_to_queue = pointer_to_queue;
}
