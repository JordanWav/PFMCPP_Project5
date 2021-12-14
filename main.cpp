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
 copied UDT 1:
 */
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

House::House() : numRooms(4), numWindows(10), ownerName("Viktor"), numDoors(5), numBeds(2)
{
    std::cout << "House Constructed" << std::endl;
    std::cout << std::endl;
}

House::~House()
{
    std::cout << "House Demolished" << std::endl;
}

House::Kitchen::Kitchen() : numKnives(10), numPlates(10), toasterBrand("GE"), numFridgeDoors(2), numShelves(4)
{
    std::cout << "Kitchen Constructed" << std::endl;
    std::cout << std::endl;
}

House::Kitchen::~Kitchen()
{
    std::cout << "Kitchen Demolished" << std::endl;
}

void House::Kitchen::microwaveChicken( float microwaveTime)
{
    if( microwaveTime >= 45.f )
    {
        std::cout << "Cooked for " << microwaveTime << " seconds:" << " Chicken cooked!" << std::endl;

        if( numPlates > 0 )
        {
            std::cout << "Put chicken on plate" << std::endl;
        }
    }
    else
    {
        std::cout << "Cooked for " << microwaveTime << " seconds:" << " Chicken not finished cooking!" << std::endl;
    }
}

bool House::Kitchen::madeSalad(std::string lettuceBrand, bool includeTomatoes, std::string dressing)
{
    if( includeTomatoes == true && dressing == "Italian" && lettuceBrand == "Lettuce!" )
    {
        std::cout << "Made salad!" << std::endl;
        return true;
    }
    std::cout << "Didn't make salad" << std::endl;
    return false;
}

float House::Kitchen::preheatOven(float ovenTemperature)
{
    if (ovenTemperature > 0.f)
    {
        std::cout << "Oven preheated to: " << ovenTemperature << std::endl;
        return ovenTemperature;
    }
    return 0.f;
}

bool House::Kitchen::tableSet(int numPlacesToSet, int placesSet)
{
    if( numPlates < numPlacesToSet )
    {
        std::cout << "Not enough plates, need " << numPlacesToSet - numPlates << " more plates to set the table!" << std::endl; 
        return false;
    }     
    for( int i = 0; i < numPlacesToSet; ++i )
    {
        ++placesSet;
        if( placesSet == numPlacesToSet )
        {
            std::cout << "Table set!" << std::endl;
            return true;
        }
    }
    return false; 
}

void House::Kitchen::printNumKnives()
{
    std::cout << "THIS Number of knives: " << this->numKnives << std::endl;
}

bool House::furnishHouse(const House& myHouse)
{   
    if( myHouse.numBeds == 0 )
    {
        return true;
    }
    std::cout << "No need to buy more beds, I already have " << myHouse.numBeds << std::endl;
    return false;
}

struct KitchenWrapper
{
    KitchenWrapper( House::Kitchen* ptr ) : pointerToKitchen( ptr ) {}
    ~KitchenWrapper()
    {
        delete pointerToKitchen;
    }
    House::Kitchen* pointerToKitchen = nullptr;
};

void House::openFrontDoor(std::string door)
{
    if ( door == "front door" )
    {
        std::cout << "Need to open front door" << std::endl;
    }
    else
    {
        std::cout << "Not the front door" << std::endl;
    }
}

void House::openWindows(int openedWindows)
{
    std::cout << std::endl;
    std::cout << "Opening windows" << std::endl;
    std::cout << "Windows opened: ";
    for( int i = 1; i <= numWindows; ++i )
    {
        openedWindows = i;
        std::cout << openedWindows;
        if( openedWindows != numWindows)
        {
            std::cout << ", ";
        }
        if( openedWindows == numWindows )
        {
            std::cout << std::endl;
            std::cout << "All " << numWindows << " windows have been opened" << std::endl;
        }    
    }
}

bool House::closeWindow(const House::Kitchen& myKitchen)
{
    return myKitchen.numShelves > 1;
}

void House::printNumBeds()
{
    std::cout << "THIS Number of beds: " << this->numBeds << std::endl;
}

struct HouseWrapper
{
    HouseWrapper( House* ptr ) : pointerToHouse( ptr ) {}
    ~HouseWrapper()
    {
        delete pointerToHouse;
    }
    House* pointerToHouse = nullptr;
};


/*
 copied UDT 2:
 */
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

struct GameWrapper
{
    GameWrapper( Xbox::Game* ptr ) : pointerToGame( ptr ) {}
    ~GameWrapper()
    {
        delete pointerToGame;
    }
    Xbox::Game* pointerToGame = nullptr;
};

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

struct XboxWrapper
{
    XboxWrapper( Xbox* ptr ) : pointerToXbox( ptr ) {}
    ~XboxWrapper()
    {
        delete pointerToXbox;
    }
    Xbox* pointerToXbox = nullptr;
};

/*
 copied UDT 3:
 */
struct LogicPro
{
    float sampleRate;
    std::string nameOfInputDevice;
    std::string nameOfProject;
    int numTracks;
    double tempo;

    LogicPro();
    ~LogicPro();

    std::string createInstrumentTrack(const LogicPro& trackA);
    std::string insertPlugin(const LogicPro& trackA);
    int recordPerformance(const LogicPro& trackB);
    int addTracks(int numTracksNeeded);
    void printSampleRate();

    JUCE_LEAK_DETECTOR(LogicPro)
};

LogicPro::LogicPro() : sampleRate(44100.f), nameOfInputDevice("Scarlett 2i4"), nameOfProject("My Song"), numTracks(25), tempo(135)
{
    std::cout << "Logic Pro Opened" << std::endl;
    std::cout << std::endl;

    std::cout << "Number of tracks in session: " << numTracks << 
    std::endl;

    std::cout << "Session tempo: " << tempo << " BPM" <<
    std::endl;

}

LogicPro::~LogicPro()
{
    std::cout << "Logic Pro Closed" << std::endl;
}

std::string LogicPro::createInstrumentTrack(const LogicPro& trackA)
{
    if ( trackA.numTracks < 1000 )
    {
        std::cout << "New track created!" << std::endl;
        return "new track";
    }
    std::cout << "Could not make a new track" << std::endl;
    return "!";
}

std::string LogicPro::insertPlugin(const LogicPro& trackA)
{
    if ( trackA.nameOfProject == "my project" )
    {
        std::cout << "Plugin inserted!" << std::endl;
        return "FabFilter Pro-Q 3";
    }
    std::cout << "Plugin could not be inserted!" << std::endl;
    return "no plugin";
}

int LogicPro::recordPerformance(const LogicPro& trackB)
{
    if ( trackB.nameOfInputDevice == "SSL 2+")
    {
        std::cout << "Input device: " << trackB.nameOfInputDevice << std::endl;
        return 0;
    }
    if ( trackB.nameOfInputDevice == "Focusrite Scarlett 2i2")
    {
        std::cout << "Wrong Input Device Selected" << std::endl;
        return 1; 
    }
    if ( trackB.numTracks == 0 )
    {
        std::cout << "Please Create a New Track" << std::endl;
        return 2;
    }
    std::cout << "Something Went Wrong... Please Try Again" << std::endl;
    return 3;
}

int LogicPro::addTracks(int numTracksNeeded)
{
    for( int i = 1; i <= numTracksNeeded; ++i )
    {
        ++numTracks;
        std::cout << "Track " << numTracks << " created" << std::endl;
    }
    std::cout << "New total number of tracks: " << numTracks << std::endl;
    return numTracks;
}

void LogicPro::printSampleRate()
{
    std::cout << "THIS Sample rate: " << this->sampleRate << std::endl;
}

struct LogicProWrapper
{
    LogicProWrapper( LogicPro* ptr ) : pointerToLogicPro( ptr ) {}
    ~LogicProWrapper()
    {
        delete pointerToLogicPro;
    }
    LogicPro* pointerToLogicPro = nullptr;
};

/*
 new UDT 4:
 with 2 member functions
 */
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

struct HouseBuilderWrapper
{
    HouseBuilderWrapper( HouseBuilder* ptr ) : pointerToHouseBuilder( ptr ) {}
    ~HouseBuilderWrapper()
    {
        delete pointerToHouseBuilder;
    }
    HouseBuilder* pointerToHouseBuilder = nullptr;
};

/*
 new UDT 5:
 with 2 member functions
 */
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

GameStore::GameStore()
{
    std::cout << "Game store constructed" << std::endl;
    std::cout << std::endl;
}

GameStore::~GameStore()
{
    std::cout << "Game store demolished" << std::endl;
}

void sellControllersWithXbox(const Xbox&, int numControllersToSell)
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

struct GameStoreWrapper
{
    GameStoreWrapper( GameStore* ptr ) : pointerToGameStore( ptr ) {}
    ~GameStoreWrapper()
    {
        delete pointerToGameStore;
    }
    GameStore* pointerToGameStore = nullptr;
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
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
    sellControllersWithXbox(gameStore.pointerToGameStore->xbox, 3);
    gameStore.pointerToGameStore->displayGame(gameStore.pointerToGameStore->game);
    std::cout << "Game rating is: " << gameStore.pointerToGameStore->game.gameRating << std::endl;
    gameStore.pointerToGameStore->printGameRating();

    std::cout << "----------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl; 
}
