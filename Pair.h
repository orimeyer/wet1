#ifndef PAIR_H
#define PAIR_H

class Pair {
private:
    int id;
    int treasure;

public:
    // Constructor
    Pair(int id, int treasure);

    // Getters
    int getId() const;
    int getTreasure() const;

    // Setters
    void setId(int id);
    void setTreasure(int treasure);

    // Overloading the '>' operator
    bool operator>(const Pair& other) const;

    // Overloading the '<' operator
    bool operator<(const Pair& other) const;
};

#endif // PAIR_H
