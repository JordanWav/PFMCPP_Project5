#include "Xbox.h"

Xbox::Xbox() : amountOfSpace(500.f), numGamesDownloaded(10), numControllers(2), profileName("Profile2"), numFriendsOnline(10)
{
    std::cout << "Xbox Created" << std::endl; 
    std::cout << std::endl; 
    std::cout << "Xbox info: " << std::endl;
    std::cout << std::endl; 
    std::cout << "Space: " << amountOfSpace << std::endl; 
    std::cout << "Number of games downloaded: " << numGamesDownloaded << std::endl;
    std::cout << "Number of controllers owned: " << numControllers << std::endl;       
    std::cout << "Current profile: " << profileName << std::endl;
    std::cout << std::endl;
}

Xbox::~Xbox()
{
    std::cout << "Xbox broken" << std::endl;
} 


Xbox::Game::Game() : sizeOfGame(50.f), gameCategory("FPS"), gameRating('T'), timePlayed(10.5f), numCompletedAchievements(7)
{
    std::cout << "Game Purchased" << std::endl;
    std::cout << std::endl;
}

Xbox::Game::~Game()
{
    std::cout << "Game Broken" << std::endl;
}

bool Xbox::openGame(const Xbox::Game& skyrim)
{
    if( skyrim.gameCategory == "RPG" )
    {
        std::cout << "Game Opened!" << std::endl;
        return true;
    }
    return false;
}

bool Xbox::downloadGame(const Xbox::Game& haloInfinite)
{
    if( Xbox::amountOfSpace >= haloInfinite.sizeOfGame )
    {
        std::cout << "Game Downloaded!" << std::endl;
        return true;
    }
    return false;
}

void Xbox::turnOnXbox(Xbox& myXbox)
{
    std::cout << "Xbox On!" << std::endl;
    myXbox.profileName = "My Profile";   
}

int Xbox::deleteAllGames(int gamesDeleted)
{
    gamesDeleted = 0;
    while( gamesDeleted < numGamesDownloaded )
    {
        ++gamesDeleted;
        --numGamesDownloaded;
        amountOfSpace += 30.f;
        std::cout << "Games deleted: " << gamesDeleted << " New total space = " << amountOfSpace << std::endl;
    }
    return numGamesDownloaded;
}

void Xbox::printAmountOfSpace()
{
    std::cout << "THIS Amount of space: " << this->amountOfSpace << std::endl;
}

bool Xbox::Game::isGame(std::string gameName)
{
    return gameName == "Valid";
}

bool Xbox::Game::completeAchievement(std::string achievementName, int numPoints)
{
    if ( achievementName == "Valid" )
    {
        numPoints += 5;
        return true;
    }
    std::cout << "No achievements!" << std::endl;
    return false;
}

void Xbox::Game::changeMenu(char buttonPressed, std::string currentMenu)
{
    if ( buttonPressed == 'b' )
    {
        currentMenu = "main menu";
        std::cout << "You are now at the main menu" << std::endl;
    }
    if ( buttonPressed == 'a' )
    {
        currentMenu = "start menu";
        std::cout << "You are now at the start menu" << std::endl;
    }

}

int Xbox::Game::totalAchievementPoints(int achievementsGained, int achievementPoints)
{    
    int currentTotal = numCompletedAchievements * achievementPoints;
    for( int i = 0; i < achievementsGained; ++i )
    {
        currentTotal += achievementPoints;
        std::cout << "New achievement points total: " << currentTotal << std::endl;
    }
    return currentTotal;
}

void Xbox::Game::printSizeOfGame()
{
    std::cout << "THIS Size of game: " << this->sizeOfGame << std::endl;
}
