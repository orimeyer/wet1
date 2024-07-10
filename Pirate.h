#ifndef PIRATE_H
#define PIRATE_H

class Pirate {
private:
    int pirateId;
    int shipId;
    int treasure;

public:
    // Constructor
    Pirate(int pid, int sid, int treas);

    // Getters
    int getPirateId() const;
    int getShipId() const;
    int getTreasure() const;

    // Setters
    void setPirateId(int pid);
    void setShipId(int sid);
    void setTreasure(int treas);
};

#endif // PIRATE_H
