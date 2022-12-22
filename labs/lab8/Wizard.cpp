#include <string>
#include <iostream>

using namespace std;

#include "Character.h"
#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength), rank(rank)
{} 

void Wizard::attack(Character &opponent)
{
    if (opponent.getType() == WIZARD)
    {
        // cout<<endl<<"BOOM ROASTED"<<endl<<endl;
        Wizard &opp = dynamic_cast<Wizard &>(opponent);

        double damageGiven = (((double)this->attackStrength)*((double)this->rank/(double)opp.rank));

        // cout<<endl<<"attack strength: "<<this->attackStrength<<" attacker rank: "<<this->rank<<" defender rank: "<<opp.rank<<endl<<endl;
        // cout<<endl<<"damage given: "<<damageGiven<<endl<<endl;
        opp.damage(damageGiven);
        cout << "Wizard " << this->name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << damageGiven << " damage." << endl;
    }
    else
    {
        // int tempHealth = opponent.getHealth();
        double damageGiven = (this->attackStrength);
        opponent.damage(damageGiven);
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damageGiven << " damage." << endl;
    }
}