#include <string>
#include <iostream>

using namespace std;

#include "Character.h"
#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
{} 

void Warrior::attack(Character &opponent) 
{
    if (opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        
        if (opp.allegiance == this-> allegiance)
        {
            cout << "Warrior " << this->name << " does not attack Warrior " << opp.name << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else
        {
            // int tempHealth = opponent.getHealth();
            double damageGiven = ((this->health/MAX_HEALTH)*(this->attackStrength));
            opponent.damage(damageGiven);
            cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << damageGiven << " damage." << endl;
        }
    }
    else
    {
        // int tempHealth = opponent.getHealth();
        double damageGiven = ((this->health/MAX_HEALTH)*(this->attackStrength));
        opponent.damage(damageGiven);
        cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damageGiven << " damage." << endl;
    }
}

// double Warrior::getHealthDecimal()
// {
//     return health;
// }