#pragma once

struct House;
struct Xbox;
struct LogicPro;
struct HouseBuilder;
struct GameStore;

struct HouseWrapper
{
    HouseWrapper( House* ptr );
    ~HouseWrapper();
    House* pointerToHouse = nullptr;
};

struct KitchenWrapper
{
    KitchenWrapper( House::Kitchen* ptr );
    ~KitchenWrapper();
    House::Kitchen* pointerToKitchen = nullptr;
};

struct XboxWrapper
{
    XboxWrapper( Xbox* ptr );
    ~XboxWrapper();
    Xbox* pointerToXbox = nullptr;
};

struct GameWrapper
{
    GameWrapper( Xbox::Game* ptr );
    ~GameWrapper();
    Xbox::Game* pointerToGame = nullptr;
};

struct LogicProWrapper
{
    LogicProWrapper( LogicPro* ptr );
    ~LogicProWrapper();
    LogicPro* pointerToLogicPro = nullptr;
};

struct HouseBuilderWrapper
{
    HouseBuilderWrapper( HouseBuilder* ptr );
    ~HouseBuilderWrapper();
    HouseBuilder* pointerToHouseBuilder = nullptr;
};

struct GameStoreWrapper
{
    GameStoreWrapper( GameStore* ptr );
    ~GameStoreWrapper();
    GameStore* pointerToGameStore = nullptr;
};
