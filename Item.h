#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item{
public:
    Item(string name, int cost);
    string getName();
    int getValue();
    virtual string toString();
    void setDescription(string description);
    string getDescription();
protected:
    string name;
    int value;
    string description;
};

#endif // ITEM_H
