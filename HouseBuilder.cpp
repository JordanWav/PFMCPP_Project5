#include "HouseBuilder.h"

HouseBuilder::HouseBuilder()
{
    std::cout << "House builder started" << std::endl;
    std::cout << std::endl;
}

HouseBuilder::~HouseBuilder()
{
    std::cout << "House builder stopped" << std::endl;
}

void HouseBuilder::createAnotherFloor(const House& houseA)
{
    std::cout << "Adding floor to " << houseA.ownerName << "'s house" << std::endl;
}

int HouseBuilder::addShelvesToKitchen(const House::Kitchen& kitchenA, int numShelvesToAdd)
{
    std::cout << "Adding " << numShelvesToAdd << " shelves to kitchen" << std::endl;
    std::cout << "Total number of shelves is now: " << kitchenA.numShelves + numShelvesToAdd << std::endl;
    return kitchenA.numShelves + numShelvesToAdd;
}

void HouseBuilder::printHouseNumRooms()
{
    std::cout << "THIS Number of rooms in 'house': " << this->house.numRooms << std::endl; 
}
