#include "pirates24b1.h"



Ocean::Ocean()
{
    
}

Ocean::~Ocean()
{
    
}

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
    int extra_to_sub = its_ship->getExtraCoins();
    its_ship->getPiratesById().insert(pirateId, newPirate);
    AVLTree<Pair, Pirate> PiratesByTreasure = its_ship->getPiratesByTreasure();
    PiratesByTreasure.insert(Pair(pirateId, treasure - extra_to_sub), newPirate);
    newPirate->setPointerToShip(its_ship);
    its_ship->getPiratesByOrder().enqueue(pirateId);
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
    pirate_to_delete->getPointerToQueue()->setData(-1);
    Ship* its_ship = pirate_to_delete->getPointerToShip();
    AVLTree<Pair, Pirate> PiratesByTreasure = its_ship->getPiratesByTreasure();
    its_ship->getPiratesById().remove(pirateId);
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
    Ship* source_ship = ships_tree.find(sourceShipId)->getData();
    while
    return StatusType::FAILURE;
}

StatusType Ocean::update_pirate_treasure(int pirateId, int change)
{
    return StatusType::FAILURE;
}

output_t<int> Ocean::get_treasure(int pirateId)
{
    return 0;
}

output_t<int> Ocean::get_cannons(int shipId)
{
    return 0;
}

output_t<int> Ocean::get_richest_pirate(int shipId)
{
    return 0;
}

StatusType Ocean::ships_battle(int shipId1,int shipId2)
{
    return StatusType::FAILURE;
}



