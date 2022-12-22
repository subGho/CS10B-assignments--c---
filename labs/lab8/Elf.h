#include <string>

using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

#include "Character.h"

class Elf : public Character {  
 protected:
    string family;

 public:
 	Elf(const string &name, double health, double attackStrength, string family);
    void attack(Character &) override;
 };




#endif