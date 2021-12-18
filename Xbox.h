#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct Xbox
{
    float amountOfSpace;
    int numGamesDownloaded;
    int numControllers;
    std::string profileName;
    int numFriendsOnline;
    
    Xbox();
    ~Xbox();

    struct Game
    {
        float sizeOfGame;
        std::string gameCategory;
        char gameRating;
        float timePlayed;
        int numCompletedAchievements;
        
        Game(float sizeOfGame, std::string gameCategory, char gameRating);
        Game();
        ~Game();

        bool isGame(std::string gameName);
        bool completeAchievement(std::string achievementName, int numPoints = 5);
        void changeMenu(char buttonPressed = 'b', std::string currentMenu = "Main menu");
        int totalAchievementPoints(int achievementsGained, int achievementPoints);
        void printSizeOfGame();

        JUCE_LEAK_DETECTOR(Game)
    };
    bool openGame(const Xbox::Game& skyrim);
    bool downloadGame(const Xbox::Game& haloInfinite);
    void turnOnXbox(Xbox& myXbox);
    int deleteAllGames(int gamesDeleted);
    void printAmountOfSpace();

    JUCE_LEAK_DETECTOR(Xbox)
};
