#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "Item.h"

//forward declare the class Character to prevent circular header dependency
class Character;

class Weapon : public Item {
public:
    Weapon(string name, int damageValue, int cost);
    string toString();
    int getDamage();
    virtual int getRange();
    virtual void useOn(Character& target, int rangeToTarget);
protected:
    int damage;
};



#endif // WEAPON_H
