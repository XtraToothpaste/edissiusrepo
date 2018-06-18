#include "Location.h"
#include <iostream>

Location::Location(){
    name = "?";
    visited = false;
    exit = false;
    neighbors[4] = {nullptr};
}

Location::Location(string locName, string details, bool isTheExit){
    name = locName;
    detailedDescription = details;
    exit = isTheExit;
    visited = false;
}

string Location::getName(){
    return name;
}

bool Location::aquire(Item* item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == nullptr) {
            inventory[i] = item;
            return true;
        }
    }
    return false;
}

bool Location::drop(Item* item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == item) {
            inventory[i] = nullptr;
            return true;
        }
    }
    return false;
}

void Location::showInventory(){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            cout << "There is a " << inventory[i]->getName() << " here.\n";
            //cout << inventory[i]->getName() << " (value: " << inventory[i]->getValue() << ")" << endl;
        }
    }
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(inventory[i] != nullptr){
            return;
        }
    }
    cout << "This place is empty.\n";
}

bool Location::contains(Item *item){
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(inventory[i] == item){
            return true;
        }
    }
    return false;
}

string Location::getDescription(){
    string description = "~";
    description.append(name);
    description.append("~");
    if(isVisited() == false){
        description.append("\n");
        description.append(getDetails());
    }
    return description;
}

string Location::getDetails(){
    return detailedDescription;
}

bool Location::hasNeighbor(Direction dir){
    if(neighbors[dir] == nullptr){
        return false;
    }
    return true;
}

Location* Location::getNeighbor(Direction dir){
    return neighbors[dir];
}

void Location::setNeighbor(Direction dir, Location* neighborLoc){
    neighbors[dir] = neighborLoc;
}

bool Location::isExit(){
    if (exit == true){
        return true;
    }
    else{
        return false;
    }
}

void Location::visit(){
    visited = true;
}

bool Location::isVisited(){
    if(visited == true){
        return true;
    }
    else{
        return false;
    }
}
