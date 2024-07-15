#ifndef SHIP_H
#define SHIP_H

#include "AVLTree.h"
#include "Pair.h"
#include "Queue.h"
#include "Pirate.h"

class Ship {
private:
    int shipId;
    int cannons;
    int num_of_pirates;
    int reachest;
    int extra_coins;
    AVLTree<int, Pirate> pirates_by_id;
    AVLTree<Pair, Pirate> pirates_by_treasure;
    Queue pirates_by_order;

public:
    // Constructors
    Ship(int shipId, int cannons);
    Ship(const Ship& other);

    // Destructor
    ~Ship();

    // Getters
    int getShipId() const;
    int getCannons() const;
    int getNumOfPirates() const;
    int getReachest() const;
    int getExtraCoins() const;
    const AVLTree<int, Pirate>& getPiratesById() const;
    const AVLTree<Pair, Pirate>& getPiratesByTreasure() const;
    const Queue& getPiratesByOrder() const;

    // Setters
    void setShipId(int id);
    void setCannons(int cannons);
    void setNumOfPirates(int num);
    void setReachest(int reachest);
    void setExtraCoins(int coins);

    // Copy assignment operator
    Ship& operator=(const Ship& other);
};

#endif // SHIP_H

