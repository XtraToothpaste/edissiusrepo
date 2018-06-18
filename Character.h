#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "Item.h"
//#include "Armor.h"
#include "Weapon.h"

class Character{
public:
    Character(const std::string& nameVal);
    void print() const;
    int getHealthPoints() const;
    double getAnxLevel();
    string getAnxDescription();
    void takeDamage(int amount);
    void setHealth(int amount);
    void setAnxiety(int amount);
    void attack(Character& target, int range);
    bool aquire(Item* item);
    bool drop(Item* item);
    void equip(int itemNumber);
    Weapon* getWeapon();
    void showInventory();
    bool contains(Item* item);

    //Armor* getArmor();

private:
    std::string name;
    int healthPoints;
    double anxLevel;
    string anxDescription;

    Weapon* weapon;
    //Armor* armor;
    const static int INVENTORY_SIZE = 5;
    Item* inventory[INVENTORY_SIZE] = {0};

    //Default armor/weapon
    //Armor skin = Armor("Skin", 0, 0);
    Weapon hands = Weapon("Bare Hands", 1, 0);
};

#endif // CHARACTER_H
