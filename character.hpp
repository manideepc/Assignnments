#pragma once
#ifndef Character
#define Character
#include<string.h>

using namespace std;

class character
{
  string Name;
  string Role;
  int Hit_points;
  int Attack_bonus;
  int Damage_bonus;
  int Armor_class;
  

public:
character();


   static int count;
  
  void setName(); //Assigns Name
  void setRole(); // Assigns Role

  void setHit_points();

  void setAttack_bonus();

  void setDamage_bonus();

  void setArmor_class();
  void getSummary();

  string getRole ()	;	//Retrieves Role

  
  string getName ()	;	//Retrieves Name

  int getHealth ();		//Retrieves Health of the user

  void setHealth (int amount);	// Sets the Health


  int damage (int amount);	//If Wins it reduces the Hit Points


  int attack (character othercharacter);
  
  ostream& print(std::ostream& outs = std::cout);
};

#endif //Character





