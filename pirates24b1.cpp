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
	main_pirates_tree.insert(pirateId, newPirate);
    AVLNode<int, Ship>* shipNode = ships_tree.find(shipId);
    shipNode->getData()->getPirates().insert(pirateId, newPirate);
	return StatusType::SUCCESS;
}

StatusType Ocean::remove_pirate(int pirateId)
{
    return StatusType::FAILURE;
}

StatusType Ocean::treason(int sourceShipId, int destShipId)
{
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



