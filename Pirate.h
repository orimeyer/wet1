#ifndef PIRATE_H
#define PIRATE_H

#include "Node.h"

class Ship; // Forward declaration

class Pirate {
private:
    int pirateId;
    int shipId;
    int treasure;
    Ship* pointer_to_ship;
    Node* pointer_to_queue;

public:
    // Constructor
    Pirate(int pirateId, int shipId, int treasure);

    // Destructor
    ~Pirate();

    // Copy constructor
    Pirate(const Pirate& other);

    // Getters
    int getPirateId() const;
    int getShipId() const;
    int getTreasure() const;
    Ship* getPointerToShip() const;
    Node* getPointerToQueue() const;

    // Setters
    void setPirateId(int pirateId);
    void setShipId(int shipId);
    void setTreasure(int treasure);
    void setPointerToShip(Ship* pointer_to_ship);
    void setPointerToQueue(Node* pointer_to_queue);
};

#endif // PIRATE_H
