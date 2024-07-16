#include "pirates24b1.h"

Ocean::Ocean()  {}

Ocean::~Ocean() {}

StatusType Ocean::add_ship(int shipId, int cannons)
{
    if (shipId <=0 || cannons < 0){
		return StatusType::INVALID_INPUT;
	}
	if (ships_tree.contains(shipId)){
		return StatusType::FAILURE;
	}
	Ship* newShip = new Ship(shipId, cannons);
    if (newShip == nullptr) {
		delete newShip;
        return StatusType::ALLOCATION_ERROR;
    }
	ships_tree.insert(shipId, newShip);
	return StatusType::SUCCESS;
}

StatusType Ocean::remove_ship(int shipId)
{
    if (shipId <= 0){
		return StatusType::INVALID_INPUT;
	}
	if (!ships_tree.contains(shipId) || ships_tree.find(shipId)->getData()->getNumOfPirates() > 0){
		return StatusType::FAILURE;
	}
	ships_tree.remove(shipId);
	return StatusType::SUCCESS;
}

StatusType Ocean::add_pirate(int pirateId, int shipId, int treasure)
{
    if (pirateId <=0 || shipId <= 0){
		return StatusType::INVALID_INPUT;
	}
	if (main_pirates_tree.contains(pirateId) || (!ships_tree.contains(shipId))){
		return StatusType::FAILURE;
	}
	Pirate* newPirate = new Pirate(pirateId, shipId, treasure);
    if (newPirate == nullptr) {
		delete newPirate;
        return StatusType::ALLOCATION_ERROR;
    }
    Ship* its_ship = ships_tree.find(shipId)->getData();
    its_ship->getPiratesById().insert(pirateId, newPirate);
    int extra_to_sub = its_ship->getExtraCoins();
    AVLTree<Pair, Pirate> PiratesByTreasure = its_ship->getPiratesByTreasure();
    PiratesByTreasure.insert(Pair(pirateId, treasure - extra_to_sub), newPirate);
    its_ship->getPiratesByOrder().enqueue(pirateId);
    newPirate->setPointerToShip(its_ship);
    newPirate->setPointerToQueue(its_ship->getPiratesByOrder().getTail());
	main_pirates_tree.insert(pirateId, newPirate);
    int num_pirates = its_ship->getNumOfPirates();
    its_ship->setNumOfPirates(num_pirates + 1);
    its_ship->setReachest(PiratesByTreasure.getMaxKey().getId());
	return StatusType::SUCCESS;
}

StatusType Ocean::remove_pirate(int pirateId)
{
    if (pirateId <= 0){
		return StatusType::INVALID_INPUT;
	}
	if (main_pirates_tree.isEmpty() || !main_pirates_tree.contains(pirateId)){
		return StatusType::FAILURE;
	}
	Pirate* pirate_to_delete = main_pirates_tree.find(pirateId)->getData();
    Ship* its_ship = pirate_to_delete->getPointerToShip();
    its_ship->getPiratesByOrder().removeNode(pirate_to_delete->getPointerToQueue());
    its_ship->getPiratesById().remove(pirateId);
    AVLTree<Pair, Pirate> PiratesByTreasure = its_ship->getPiratesByTreasure();
    int its_treasure = pirate_to_delete->getTreasure();
    PiratesByTreasure.remove(Pair(pirateId, its_treasure));
    int num_pirates = its_ship->getNumOfPirates();
    its_ship->setNumOfPirates(num_pirates - 1);
    its_ship->setReachest(PiratesByTreasure.getMaxKey().getId());
    main_pirates_tree.remove(pirateId);
	return StatusType::SUCCESS;
}

StatusType Ocean::treason(int sourceShipId, int destShipId)
{
    if (sourceShipId <=0 || destShipId <= 0 || sourceShipId == destShipId){
		return StatusType::INVALID_INPUT;
	}
	if (!ships_tree.contains(sourceShipId) || (!ships_tree.contains(destShipId))){
		return StatusType::FAILURE;
	}
    Ship* source_ship = ships_tree.find(sourceShipId)->getData();
    if (source_ship->getNumOfPirates() == 0){
        return StatusType::FAILURE;
    }
    int traitor = source_ship->getPiratesByOrder().peek();
    output_t<int> treasure = get_treasure(traitor);
    remove_pirate(traitor);
    add_pirate(traitor, destShipId, treasure.ans());
    return StatusType::SUCCESS;
}

StatusType Ocean::update_pirate_treasure(int pirateId, int change)
{
    if (pirateId <= 0){
		return StatusType::INVALID_INPUT;
	}
	if (main_pirates_tree.isEmpty() || !main_pirates_tree.contains(pirateId)){
		return StatusType::FAILURE;
	}
    Pirate* pirate_to_update = main_pirates_tree.find(pirateId)->getData();
    int initial_treasure = pirate_to_update->getTreasure();
    pirate_to_update->setTreasure(initial_treasure + change);
    Ship* its_ship = pirate_to_update->getPointerToShip();
    its_ship->getPiratesById().find(pirateId)->getData()->setTreasure(initial_treasure + change);
    its_ship->getPiratesByTreasure().remove(Pair(pirateId, initial_treasure));
    its_ship->getPiratesByTreasure().insert(Pair(pirateId, initial_treasure + change), pirate_to_update);
    AVLTree<Pair, Pirate> PiratesByTreasure = its_ship->getPiratesByTreasure();
    its_ship->setReachest(PiratesByTreasure.getMaxKey().getId());
    return StatusType::SUCCESS;
}

output_t<int> Ocean::get_treasure(int pirateId)
{
    if (pirateId <= 0){
		return StatusType::INVALID_INPUT;
	}
	if (main_pirates_tree.isEmpty() || !main_pirates_tree.contains(pirateId)){
		return StatusType::FAILURE;
	}
    Pirate* selected_pirate = main_pirates_tree.find(pirateId)->getData();
    Ship* its_ship = selected_pirate->getPointerToShip();
    return output_t<int>(selected_pirate->getTreasure() + its_ship->getExtraCoins());
}

output_t<int> Ocean::get_cannons(int shipId)
{
    if (shipId <= 0){
		return StatusType::INVALID_INPUT;
	}
	if (ships_tree.isEmpty() || !ships_tree.contains(shipId)){
		return StatusType::FAILURE;
	}
    return output_t<int>(ships_tree.find(shipId)->getData()->getCannons());
}

output_t<int> Ocean::get_richest_pirate(int shipId)
{
    if (shipId <= 0){
		return StatusType::INVALID_INPUT;
	}
	if (ships_tree.isEmpty() || !ships_tree.contains(shipId)){
		return StatusType::FAILURE;
	}
    Ship* its_ship = ships_tree.find(shipId)->getData();
    if (its_ship->getNumOfPirates() == 0){
        return StatusType::FAILURE;
    }
    return output_t<int>(its_ship->getReachest());
}

int Ocean::min(int cannons, int pirates)
{
    if (cannons <= pirates)
        return cannons;
    return pirates;        
}

StatusType Ocean::ships_battle(int shipId1,int shipId2)
{
    if (shipId1 <=0 || shipId2 <= 0 || shipId1 == shipId2){
		return StatusType::INVALID_INPUT;
	}
	if (!ships_tree.contains(shipId1) || (!ships_tree.contains(shipId2))){
		return StatusType::FAILURE;
	}
    Ship* ship1 = ships_tree.find(shipId1)->getData();
    Ship* ship2 = ships_tree.find(shipId2)->getData();
    int min_ship1 = min(ship1->getCannons(), ship1->getNumOfPirates());
    int min_ship2 = min(ship2->getCannons(), ship2->getNumOfPirates());
    if (min_ship1 > min_ship2){
        ship1->setExtraCoins(ship1->getExtraCoins() + ship2->getNumOfPirates());
        ship2->setExtraCoins(ship2->getExtraCoins() - ship1->getNumOfPirates());
    }
    if (min_ship1 < min_ship2){
        ship1->setExtraCoins(ship1->getExtraCoins() - ship2->getNumOfPirates());
        ship2->setExtraCoins(ship2->getExtraCoins() + ship1->getNumOfPirates());
    }
    return StatusType::SUCCESS;
}
