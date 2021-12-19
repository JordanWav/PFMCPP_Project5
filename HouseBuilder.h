#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "House.h"

struct HouseBuilder
{
    House house; 
    House::Kitchen kitchen;

    HouseBuilder();
    ~HouseBuilder();

    void createAnotherFloor(const House& houseA);
    int addShelvesToKitchen(const House::Kitchen& kitchenA, int numShelvesToAdd);
    void printHouseNumRooms();
    
    JUCE_LEAK_DETECTOR(HouseBuilder)
};
