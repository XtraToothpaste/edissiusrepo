#include <iostream>
#include <cassert>
#include "Character.h"

using namespace std;

Character::Character(const std::string& nameVal){
    name = nameVal;
    healthPoints = 100;
    anxLevel = 1;
    weapon = new Weapon("Bare Hands", 1, 0);
    //armor = new Armor("Skin", 0, 0);
}

void Character::print() const{
    cout << name << endl;
    cout << "Health: " << healthPoints << endl;
    //cout << "Armor: " << armor->toString() << endl;
    cout << "Weapon: " << weapon->toString() << endl;
    cout << "Inventory: " << endl;
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            cout << inventory[i]->getName() << " (value: " << inventory[i]->getValue() << ")" << endl;
        }
    }
    cout << endl;
}

void Character::showInventory(){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            cout << inventory[i]->getName() << " (value: " << inventory[i]->getValue() << ")" << endl;
        }
        else{
            cout << "empty slot\n";
        }
    }
    cout << endl;
}

int Character::getHealthPoints() const{
    return healthPoints;
}

bool Character::contains(Item *item){
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(inventory[i] == item){
            return true;
        }
    }
    return false;
}

void Character::takeDamage(int amount){
    //amount = amount - armor->getProtection();
    if(amount >= 0){
        healthPoints = healthPoints - amount;
    }
}

void Character::setHealth(int amount){
    healthPoints = amount;
}

void Character::setAnxiety(int amount){
    anxLevel = amount;
}

void Character::attack(Character& target, int range){
    weapon->useOn(target, range);
}

bool Character::aquire(Item* item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == nullptr) {
            inventory[i] = item;
            return true;
        }
    }
    return false;
}

bool Character::drop(Item* item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == item) {
            inventory[i] = nullptr;
            return true;
        }
    }
    return false;
}

void Character::equip(int itemNumber){
    Item* mysteryObject = inventory[itemNumber];
    //Armor* mysteryAsArmor = dynamic_cast<Armor*>(mysteryObject);
    Weapon* mysteryAsWeapon = dynamic_cast<Weapon*>(mysteryObject);
    /*if(mysteryAsArmor != nullptr){
        armor = dynamic_cast<Armor*>(mysteryObject);
    }
    else */if(mysteryAsWeapon != nullptr){
        weapon = dynamic_cast<Weapon*>(mysteryObject);
    }
    else{}
}

Weapon* Character::getWeapon(){
    return weapon;
}

double Character::getAnxLevel(){
    anxLevel += 5;
    return anxLevel;
}

string Character::getAnxDescription(){
    if(anxLevel >= 0 && anxLevel < 2){
        return "I feel Great.";
    }
    else if(anxLevel >= 2 && anxLevel < 10){
        return "I feel Good.";
    }
    else if(anxLevel >= 10 && anxLevel < 20){
        return "I feel Okay.";
    }
    else if(anxLevel >= 20 && anxLevel < 30){
        return "I feel mediocre.";
    }
    else if(anxLevel >= 30 && anxLevel < 40){
        return "I feel fine.";
    }
    else if(anxLevel >= 40 && anxLevel < 50){
        return "I feel bad.";
    }
    else if(anxLevel >= 50 && anxLevel < 60){
        return "I feel awful.";
    }
    else{
        healthPoints = 0;
    }
}

//Armor* Character::getArmor()
//{
//    return armor;
//}
