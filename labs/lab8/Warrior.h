#include <string>

using namespace std;

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Character.h"

class Warrior : public Character {  
 protected:
   string allegiance;
   

 public:
 	Warrior(const string &name, double health, double attackStrength, string allegiance);
   void attack(Character &) override;
   // double getHealthDecimal();
 };

#endif