#include "Ship.h"

// Constructors
Ship::Ship(int shipId, int cannons)
    : shipId(shipId), cannons(cannons), num_of_pirates(0),
      reachest(-1), extra_coins(0) {}

Ship::Ship(const Ship& other)
    : shipId(other.shipId), cannons(other.cannons), num_of_pirates(other.num_of_pirates),
      reachest(other.reachest), extra_coins(other.extra_coins),
      pirates_by_id(other.pirates_by_id), pirates_by_treasure(other.pirates_by_treasure),
      pirates_by_order(other.pirates_by_order) {}

// Destructor
Ship::~Ship() {
    // AVLTree destructors will be called automatically
    // Queue destructor will be called automatically
}

// Getters
int Ship::getShipId() const {
    return shipId;
}

int Ship::getCannons() const {
    return cannons;
}

int Ship::getNumOfPirates() const {
    return num_of_pirates;
}

int Ship::getReachest() const {
    return reachest;
}

int Ship::getExtraCoins() const {
    return extra_coins;
}

AVLTree<int, Pirate>& Ship::getPiratesById(){
    return pirates_by_id;
}

AVLTree<Pair, Pirate>& Ship::getPiratesByTreasure(){
    return pirates_by_treasure;
}

Queue& Ship::getPiratesByOrder(){
    return pirates_by_order;
}

// Setters
void Ship::setShipId(int id) {
    shipId = id;
}

void Ship::setCannons(int cannons) {
    this->cannons = cannons;
}

void Ship::setNumOfPirates(int num) {
    num_of_pirates = num;
}

void Ship::setReachest(int reachest) {
    this->reachest = reachest;
}

void Ship::setExtraCoins(int coins) {
    extra_coins = coins;
}

// Copy assignment operator
Ship& Ship::operator=(const Ship& other) {
    if (this != &other) {
        shipId = other.shipId;
        cannons = other.cannons;
        num_of_pirates = other.num_of_pirates;
        reachest = other.reachest;
        extra_coins = other.extra_coins;
        pirates_by_id = other.pirates_by_id;
        pirates_by_treasure = other.pirates_by_treasure;
        pirates_by_order = other.pirates_by_order;
    }
    return *this;
}
