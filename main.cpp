#include <iostream>
#include "pirates24b1.h" // Assuming this is your main header file that includes all necessary classes

int main() {
    // Create an instance of Ocean
    Ocean ocean;

    // Test adding ships
    std::cout << "Adding ships...\n";
    ocean.add_ship(1, 10);
    ocean.add_ship(2, 15);
    ocean.add_ship(3, 20);

    // Test adding pirates
    std::cout << "Adding pirates...\n";
    ocean.add_pirate(101, 1, 50);
    ocean.add_pirate(102, 1, 20);
    ocean.add_pirate(103, 1, 30);
    ocean.add_pirate(201, 2, 40);
    ocean.add_pirate(202, 2, 60);

    // Test updating pirate's treasure
    std::cout << "Updating pirate's treasure...\n";
    ocean.update_pirate_treasure(101, -20);
    ocean.update_pirate_treasure(202, -20);

    // Test ships battle
    std::cout << "Ships battle...\n";
    ocean.ships_battle(1, 2);

    // Test get treasure of a pirate
    std::cout << "Getting treasure of a pirate...\n";
    output_t<int> treasure = ocean.get_treasure(101);
    if (treasure.status() == StatusType::SUCCESS) {
        std::cout << "Treasure of pirate 101: " << treasure.ans() << std::endl;
    } else {
        std::cout << "Failed to get treasure of pirate 101.\n";
    }

    // Test get cannons of a ship
    std::cout << "Getting cannons of a ship...\n";
    output_t<int> cannons = ocean.get_cannons(2);
    if (cannons.status() == StatusType::SUCCESS) {
        std::cout << "Cannons of ship 2: " << cannons.ans() << std::endl;
    } else {
        std::cout << "Failed to get cannons of ship 2.\n";
    }

    // Test get richest pirate of a ship
    std::cout << "Getting richest pirate of a ship...\n";
    output_t<int> richest_pirate = ocean.get_richest_pirate(1);
    if (richest_pirate.status() == StatusType::SUCCESS) {
        std::cout << "Richest pirate of ship 1: " << richest_pirate.ans() << std::endl;
    } else {
        std::cout << "Failed to get richest pirate of ship 1.\n";
    }

    // Test treason
    std::cout << "Treason...\n";
    ocean.treason(1, 2); 

    return 0;
}
