#include <string>

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

#include "Character.h"

class Wizard : public Character {  
 protected:
    int rank;

 public:
 	Wizard(const string &name, double health, double attackStrength, int rank);
    void attack(Character &) override;
 };

#endif