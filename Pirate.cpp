#include "Pirate.h"

// Constructor
Pirate::Pirate(int pid, int sid, int treas)
    : pirateId(pid), shipId(sid), treasure(treas) {}

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

// Setters
void Pirate::setPirateId(int pid) {
    pirateId = pid;
}

void Pirate::setShipId(int sid) {
    shipId = sid;
}

void Pirate::setTreasure(int treas) {
    treasure = treas;
}
