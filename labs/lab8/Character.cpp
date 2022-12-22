#include <string>

using namespace std;

#include "Character.h"

Character::Character(HeroType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength)
{}

HeroType Character::getType() const
{
    return type;
}

const string& Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    return static_cast<int>(health);
}

void Character::damage(double d)
{
    this->health -= d;
}

bool Character::isAlive() const
{
    if (getHealth() > 0)
    {
        return true;
    }
    return false;
}



