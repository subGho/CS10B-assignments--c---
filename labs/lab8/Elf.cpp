#include <string>
#include <iostream>

using namespace std;

#include "Character.h"
#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, string family) : Character(ELF, name, health, attackStrength), family(family)
{}

void Elf::attack(Character &opponent) 
{
    if (opponent.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        
        if (opp.family == this-> family)
        {
            cout << "Elf " << this->name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        else
        {
            // int tempHealth = opponent.getHealth();
            double damageGiven = ((this->health/MAX_HEALTH)*(this->attackStrength));
            opponent.damage(damageGiven);
            cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << damageGiven << " damage." << endl;
        }
    }
    else
    {
        // int tempHealth = opponent.getHealth();
        double damageGiven = ((this->health/MAX_HEALTH)*(this->attackStrength));
        opponent.damage(damageGiven);
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damageGiven << " damage." << endl;
    }
}
