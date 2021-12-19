#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "Xbox.h"

struct GameStore
{
    Xbox xbox;
    Xbox::Game game;

    GameStore();
    ~GameStore();

    void sellControllersWithXbox(const Xbox&, int numControllersToSell);
    void displayGame(const Xbox::Game& gameA);
    void printGameRating();

    JUCE_LEAK_DETECTOR(GameStore)
};
