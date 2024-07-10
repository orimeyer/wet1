#include "Ship.h"

// Constructor
Ship::Ship(int sid, int cans)
    : shipId(sid), cannons(cans){}

// Getters
int Ship::getShipId() const {
    return shipId;
}

int Ship::getCannons() const {
    return cannons;
}

AVLTree<int, Pirate>& Ship::getPirates() {
    return pirates;
}

// Setters
void Ship::setShipId(int sid) {
    shipId = sid;
}

void Ship::setCannons(int cans) {
    cannons = cans;
}

void Ship::setPirates(const AVLTree<int, Pirate>& tree) {
    pirates = tree;
}
