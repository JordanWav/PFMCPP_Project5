/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        // even though I chose the name 'memberFunc' for this function, you should NAME THINGS WHAT THEY ARE OR WHAT THEY DO.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


/*
 copied UDT 1:
 */
 #include <iostream>

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
    };
    bool furnishHouse(House myHouse);
    void openFrontDoor(std::string door = "front door");
    bool closeWindow(House::Kitchen myKitchen);
    void openWindows(int openedWindows);
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

bool House::furnishHouse(House myHouse)
{   
    if( myHouse.numBeds == 0 )
    {
        return true;
    }
    std::cout << "No need to buy more beds, I already have " << myHouse.numBeds << std::endl;
    return false;
}

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

bool House::closeWindow(House::Kitchen myKitchen)
{
    return myKitchen.numShelves > 1;
}


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
    };
    bool openGame(Xbox::Game skyrim);
    bool downloadGame(Xbox::Game haloInfinite);
    void turnOnXbox(Xbox myXbox);
    int deleteAllGames(int gamesDeleted);
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

bool Xbox::openGame(Xbox::Game skyrim)
{
    if( skyrim.gameCategory == "RPG" )
    {
        std::cout << "Game Opened!" << std::endl;
        return true;
    }
    return false;
}

bool Xbox::downloadGame(Xbox::Game haloInfinite)
{
    if( Xbox::amountOfSpace >= haloInfinite.sizeOfGame )
    {
        std::cout << "Game Downloaded!" << std::endl;
        return true;
    }
    return false;
}

void Xbox::turnOnXbox(Xbox myXbox)
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

    std::string createInstrumentTrack(LogicPro trackA);
    std::string insertPlugin(LogicPro trackA);
    int recordPerformance(LogicPro trackB);
    int addTracks(int numTracksNeeded);
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

std::string LogicPro::createInstrumentTrack(LogicPro trackA)
{
    if ( trackA.numTracks < 1000 )
    {
        std::cout << "New track created!" << std::endl;
        return "new track";
    }
    std::cout << "Could not make a new track" << std::endl;
    return "!";
}

std::string LogicPro::insertPlugin(LogicPro trackA)
{
    if ( trackA.nameOfProject == "my project" )
    {
        std::cout << "Plugin inserted!" << std::endl;
        return "FabFilter Pro-Q 3";
    }
    std::cout << "Plugin could not be inserted!" << std::endl;
    return "no plugin";
}

int LogicPro::recordPerformance(LogicPro trackB)
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

    void createAnotherFloor(House houseA);
    int addShelvesToKitchen(House::Kitchen kitchenA, int numShelvesToAdd);
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

void HouseBuilder::createAnotherFloor(House houseA)
{
    std::cout << "Adding floor to " << houseA.ownerName << "'s house" << std::endl;
}

int HouseBuilder::addShelvesToKitchen(House::Kitchen kitchenA, int numShelvesToAdd)
{
    std::cout << "Adding " << numShelvesToAdd << " shelves to kitchen" << std::endl;
    std::cout << "Total number of shelves is now: " << kitchenA.numShelves + numShelvesToAdd << std::endl;
    return kitchenA.numShelves + numShelvesToAdd;
}

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

    void sellControllersWithXbox(Xbox, int numControllersToSell);
    void displayGame(Xbox::Game gameA);
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

void sellControllersWithXbox(Xbox, int numControllersToSell)
{
    std::cout << "Xbox comes with 1 free controller" << std::endl;
    std::cout << numControllersToSell << " additional controllers sold" << std::endl;
}

void GameStore::displayGame(Xbox::Game gameA)
{
    std::cout << "Displaying game" << std::endl;
    std:: cout << "Game info: " << "Genre: " << gameA.gameCategory << ", Rating: " << gameA.gameRating << std::endl; 
}

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
    House home;
    House::Kitchen homeKitchen;

    std::cout << "How many rooms are in my home? " << home.numRooms << std::endl;

    home.furnishHouse(home);
    home.openFrontDoor("front door");
    home.closeWindow(homeKitchen);
    home.openWindows(0);

    std::cout << "----------------------------------" << std::endl;
    
    std::cout << "Kitchen A:" << std::endl;
    House::Kitchen kitchenA;
    
    std::cout << "How many knives are in Kitchen A? " << kitchenA.numKnives << std::endl;

    kitchenA.microwaveChicken(300.f);
    kitchenA.madeSalad("Great Lettuce", false, "French");
    kitchenA.preheatOven(450.f);

    kitchenA.tableSet(7, 0);

    std::cout << std::endl;

    std::cout << "Kitchen B:" << std::endl;
    House::Kitchen kitchenB;

    kitchenB.numKnives -= 5;
    std::cout << "How many knives are in Kitchen B? " << kitchenB.numKnives << std::endl;

    kitchenB.microwaveChicken(10.f);
    kitchenB.madeSalad("Lettuce!", true, "Italian");
    kitchenB.preheatOven(400.f);

    kitchenB.numPlates = 2;
    kitchenB.tableSet(5, 0);
    
    std::cout << "----------------------------------" << std::endl;

    Xbox myXbox;
    Xbox::Game oblivion;

    std::cout << "Does my Xbox have more than 550 gigabytes of space? " << (myXbox.amountOfSpace > 550.f ? "Yes" : "No") << std::endl;

    myXbox.openGame(oblivion);
    myXbox.downloadGame(oblivion);
    myXbox.turnOnXbox(myXbox);
    myXbox.deleteAllGames(0);

    std::cout << "----------------------------------" << std::endl;

    Xbox::Game morrowind;
    morrowind.isGame("morrowind");
    morrowind.completeAchievement("none", 0);
    morrowind.changeMenu('a', "Start menu");

    Xbox::Game skyrim;
    skyrim.numCompletedAchievements = 10;
    skyrim.totalAchievementPoints(5, 10);

    std::cout << "----------------------------------" << std::endl;

    LogicPro sessionA;

    std::cout << "Name of project: " << sessionA.nameOfProject << std::endl;

    sessionA.createInstrumentTrack(sessionA);
    sessionA.insertPlugin(sessionA);
    sessionA.recordPerformance(sessionA);
    sessionA.addTracks(15);

    std::cout << "----------------------------------" << std::endl;

    HouseBuilder builder;
    builder.createAnotherFloor(builder.house);
    builder.addShelvesToKitchen(builder.kitchen, 2);

    std::cout << "----------------------------------" << std::endl;
    
    GameStore gameStore;
    sellControllersWithXbox(gameStore.xbox, 3);
    gameStore.displayGame(gameStore.game);

    std::cout << "----------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl; 
}
