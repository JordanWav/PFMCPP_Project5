#include "GameStore.h"

GameStore::GameStore()
{
    std::cout << "Game store constructed" << std::endl;
    std::cout << std::endl;
}

GameStore::~GameStore()
{
    std::cout << "Game store demolished" << std::endl;
}

void GameStore::sellControllersWithXbox(const Xbox&, int numControllersToSell)
{
    std::cout << "Xbox comes with 1 free controller" << std::endl;
    std::cout << numControllersToSell << " additional controllers sold" << std::endl;
}

void GameStore::displayGame(const Xbox::Game& gameA)
{
    std::cout << "Displaying game" << std::endl;
    std:: cout << "Game info: " << "Genre: " << gameA.gameCategory << ", Rating: " << gameA.gameRating << std::endl; 
}

void GameStore::printGameRating()
{
    std::cout << "THIS Game rating is: " << this->game.gameRating << std::endl;
}
