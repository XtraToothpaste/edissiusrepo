#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(string weaponName, int weaponDamageValue, int weaponCost)
    : Item(weaponName, weaponCost){
    damage = weaponDamageValue;
}

string Weapon::toString(){
    string temp;
    temp.append(name);
    temp.append(" (value: ");
    temp += std::to_string(value);
    temp.append(") ");
    temp.append("Damage: ");
    temp += std::to_string(damage);
    return temp;
}

int Weapon::getDamage(){
    return damage;
}

int Weapon::getRange(){
    return 0;
}

void Weapon::useOn(Character& target, int rangeToTarget){
    if(rangeToTarget == 0){
        target.takeDamage(getDamage());
    }
}
