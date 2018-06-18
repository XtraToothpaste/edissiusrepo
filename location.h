#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <Item.h>
//#include <Armor.h>
#include <Weapon.h>

using namespace std;

enum Direction {
    NORTH, EAST, SOUTH, WEST
};

class Location
{
public:
    Location();
    Location(string locName, string details, bool isTheExit);
    string getName();
    string getDescription();
    string getDetails();
    bool hasNeighbor(Direction dir);
    Location* getNeighbor(Direction dir);
    void setNeighbor(Direction dir, Location* neighborLoc);
    bool isExit();
    void visit();
    bool isVisited();
    bool aquire(Item* item);
    bool drop(Item* item);
    void showInventory();
    bool contains(Item* item);
private:
    string name;
    string detailedDescription;
    bool visited;
    bool exit;
    Location* neighbors[4] = {nullptr};
    const static int INVENTORY_SIZE = 10;
    Item* inventory[INVENTORY_SIZE] = {0};
};

#endif // LOCATION_H
