/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

 #include "House.h"
 #include "Xbox.h"
 #include "LogicPro.h"
 #include "HouseBuilder.h"
 #include "GameStore.h"
 #include "Wrappers.h"

int main()
{   
    HouseWrapper home( new House() );
    KitchenWrapper homeKitchen( new House::Kitchen() );

    std::cout << "How many rooms are in my home? " << home.pointerToHouse->numRooms << std::endl;
    home.pointerToHouse->furnishHouse(*home.pointerToHouse);
    home.pointerToHouse->openFrontDoor("front door");
    home.pointerToHouse->closeWindow(*homeKitchen.pointerToKitchen);
    home.pointerToHouse->openWindows(0);
    std::cout << "Number of beds: " << home.pointerToHouse->numBeds << std::endl;
    home.pointerToHouse->printNumBeds();

    std::cout << "----------------------------------" << std::endl;
    
    std::cout << "Kitchen A:" << std::endl;
    KitchenWrapper kitchenA( new House::Kitchen() );
    
    std::cout << "How many knives are in Kitchen A? " << kitchenA.pointerToKitchen->numKnives << std::endl;

    kitchenA.pointerToKitchen->microwaveChicken(300.f);
    kitchenA.pointerToKitchen->madeSalad("Great Lettuce", false, "French");
    kitchenA.pointerToKitchen->preheatOven(450.f);
    kitchenA.pointerToKitchen->tableSet(7, 0);
    std::cout << "Number of knives: " << kitchenA.pointerToKitchen->numKnives << std::endl;
    kitchenA.pointerToKitchen->printNumKnives();

    std::cout << std::endl;

    std::cout << "Kitchen B:" << std::endl;
    KitchenWrapper kitchenB( new House::Kitchen() );

    kitchenB.pointerToKitchen->numKnives -= 5;
    std::cout << "How many knives are in Kitchen B? " << kitchenB.pointerToKitchen->numKnives << std::endl;
    kitchenB.pointerToKitchen->microwaveChicken(10.f);
    kitchenB.pointerToKitchen->madeSalad("Lettuce!", true, "Italian");
    kitchenB.pointerToKitchen->preheatOven(400.f);
    kitchenB.pointerToKitchen->numPlates = 2;
    kitchenB.pointerToKitchen->tableSet(5, 0);
    
    std::cout << "----------------------------------" << std::endl;

    XboxWrapper myXbox( new Xbox() );
    GameWrapper oblivion( new Xbox::Game() );

    std::cout << "Does my Xbox have more than 550 gigabytes of space? " << (myXbox.pointerToXbox->amountOfSpace > 550.f ? "Yes" : "No") << std::endl;
    myXbox.pointerToXbox->openGame(*oblivion.pointerToGame);
    myXbox.pointerToXbox->downloadGame(*oblivion.pointerToGame);
    myXbox.pointerToXbox->turnOnXbox(*myXbox.pointerToXbox);
    myXbox.pointerToXbox->deleteAllGames(0);
    std::cout << "Amount of space: " << myXbox.pointerToXbox->amountOfSpace << std::endl;
    myXbox.pointerToXbox->printAmountOfSpace();

    std::cout << "----------------------------------" << std::endl;

    GameWrapper morrowind( new Xbox::Game() );
    morrowind.pointerToGame->isGame("morrowind");
    morrowind.pointerToGame->completeAchievement("none", 0);
    morrowind.pointerToGame->changeMenu('a', "Start menu");

    GameWrapper skyrim( new Xbox::Game() );
    skyrim.pointerToGame->numCompletedAchievements = 10;
    skyrim.pointerToGame->totalAchievementPoints(5, 10);
    std::cout << "Size of game: " << skyrim.pointerToGame->sizeOfGame << std::endl;
    morrowind.pointerToGame->printSizeOfGame();

    std::cout << "----------------------------------" << std::endl;

    LogicProWrapper sessionA( new LogicPro() );

    std::cout << "Name of project: " << sessionA.pointerToLogicPro->nameOfProject << std::endl;
    sessionA.pointerToLogicPro->createInstrumentTrack(*sessionA.pointerToLogicPro);
    sessionA.pointerToLogicPro->insertPlugin(*sessionA.pointerToLogicPro);
    sessionA.pointerToLogicPro->recordPerformance(*sessionA.pointerToLogicPro);
    sessionA.pointerToLogicPro->addTracks(15);
    std::cout << "Sample rate: " << sessionA.pointerToLogicPro->sampleRate << std::endl;
    sessionA.pointerToLogicPro->printSampleRate();

    std::cout << "----------------------------------" << std::endl;

    HouseBuilderWrapper builder( new HouseBuilder() );

    builder.pointerToHouseBuilder->createAnotherFloor(builder.pointerToHouseBuilder->house);
    builder.pointerToHouseBuilder->addShelvesToKitchen(builder.pointerToHouseBuilder->kitchen, 2);
    std::cout << "Number of rooms in 'house': " << builder.pointerToHouseBuilder->house.numRooms << std::endl;
    builder.pointerToHouseBuilder->printHouseNumRooms();

    std::cout << "----------------------------------" << std::endl;
    
    GameStoreWrapper gameStore( new GameStore() );
    gameStore.pointerToGameStore->sellControllersWithXbox(gameStore.pointerToGameStore->xbox, 3);
    gameStore.pointerToGameStore->displayGame(gameStore.pointerToGameStore->game);
    std::cout << "Game rating is: " << gameStore.pointerToGameStore->game.gameRating << std::endl;
    gameStore.pointerToGameStore->printGameRating();

    std::cout << "----------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl; 
}
