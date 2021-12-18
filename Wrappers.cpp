#include "House.h"
#include "Xbox.h"
#include "LogicPro.h"
#include "HouseBuilder.h"
#include "GameStore.h"
#include "Wrappers.h"

HouseWrapper::HouseWrapper( House* ptr ) : pointerToHouse( ptr ) {}
HouseWrapper::~HouseWrapper()
{
    delete pointerToHouse;
}

KitchenWrapper::KitchenWrapper( House::Kitchen* ptr ) : pointerToKitchen( ptr ) {}
KitchenWrapper::~KitchenWrapper()
{
    delete pointerToKitchen;
}

XboxWrapper::XboxWrapper( Xbox* ptr ) : pointerToXbox( ptr ) {}
XboxWrapper::~XboxWrapper()
{
    delete pointerToXbox;
}

GameWrapper::GameWrapper( Xbox::Game* ptr ) : pointerToGame( ptr ) {}
GameWrapper::~GameWrapper()
{
    delete pointerToGame;
}

LogicProWrapper::LogicProWrapper( LogicPro* ptr ) : pointerToLogicPro( ptr ) {}
LogicProWrapper::~LogicProWrapper()
{
    delete pointerToLogicPro;
}

HouseBuilderWrapper::HouseBuilderWrapper( HouseBuilder* ptr ) : pointerToHouseBuilder( ptr ) {}
HouseBuilderWrapper::~HouseBuilderWrapper()
{
    delete pointerToHouseBuilder;
}

GameStoreWrapper::GameStoreWrapper( GameStore* ptr ) : pointerToGameStore( ptr ) {}
GameStoreWrapper::~GameStoreWrapper()
{
    delete pointerToGameStore;
}
