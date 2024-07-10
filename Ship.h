#ifndef SHIP_H
#define SHIP_H

#include "AVLTree.h"
#include "Pirate.h"

class Ship {
private:
    int shipId;
    int cannons;
    AVLTree<int, Pirate> pirates; // AVLTree of pirates, with int as the key (assuming pirateId is the key)

public:
    // Constructor
    Ship(int sid, int cans);

    // Getters
    int getShipId() const;
    int getCannons() const;
    AVLTree<int, Pirate>& getPirates(); // Return reference to AVLTree of pirates

    // Setters
    void setShipId(int sid);
    void setCannons(int cans);
    void setPirates(const AVLTree<int, Pirate>& tree);
};

#endif // SHIP_H
