#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct House 
 {   
    int numRooms;
    int numWindows;
    std::string ownerName;
    int numDoors;
    int numBeds;
    
    House();
    ~House();

    struct Kitchen 
    {
        int numKnives;
        int numPlates;
        std::string toasterBrand;
        int numFridgeDoors;
        int numShelves;
        
        Kitchen();
        ~Kitchen();

        void microwaveChicken(float microwaveTime = 60.f);  
        bool madeSalad(std::string lettuceBrand, bool includeTomatoes = true, std::string dressing = "Italian");
        float preheatOven(float ovenTemperature);
        bool tableSet(int numPlacesToSet, int placesSet);
        void printNumKnives();

        JUCE_LEAK_DETECTOR(Kitchen)
    };
    bool furnishHouse(const House& myHouse);
    void openFrontDoor(std::string door = "front door");
    bool closeWindow(const House::Kitchen& myKitchen);
    void openWindows(int openedWindows);
    void printNumBeds();

    JUCE_LEAK_DETECTOR(House)
};
