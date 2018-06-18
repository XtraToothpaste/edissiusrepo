#include "Item.h"

Item::Item(string itemName, int itemCost){
    name = itemName;
    value = itemCost;
}

string Item::getName(){
    return name;
}

int Item::getValue(){
    return value;
}

void Item::setDescription(string thisDescription){
    description = thisDescription;
}

string Item::getDescription(){
    return description;
}

string Item::toString(){
    string temp = name;
    temp.append(" (value: ");
    temp += std::to_string(value);
    temp.append(")");
    return temp;
}
