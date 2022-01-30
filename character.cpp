#include <iostream>
#include<string.h>
#include<fstream>
#include<time.h>
#include<ctime>
#include <cstdlib>
#include <unistd.h>
#include "character.hpp"
using namespace std;
character::character(){

       //cout<<"Enter Character Name:";
        // Assigning values to Variables
           setName();
           setRole();
           setHit_points();
           setAttack_bonus();
           setDamage_bonus();
           setArmor_class();
           getSummary();
        
    }



  void character::setName()
  {
     //  print()<<"Enter Name:"<<endl;
      cin>> Name;
  }
  void character::setRole()
  {
       print()<< Name<<"'s Role Name:"<<endl;
      cin>> Role;
  }
  void character::setHit_points()
  {
       print()<< Name << " the " <<  Role << "'s hit points?" << endl;
      cin>>  Hit_points;
  }
  void character::setAttack_bonus()
  {
       print()<< Name << " the " <<  Role << "'s Attack bonus?" << endl;
      cin>> Attack_bonus;
  }
  void character::setDamage_bonus()
  {
       print()<< Name << " the " <<  Role << "'s Damage bonus?" << endl;
      cin>>  Damage_bonus;
  }
  void character::setArmor_class()
  {
       print()<< Name << " the " <<  Role << "'s Armor class?" << endl;
      cin>>  Armor_class;
  }
  string character::getRole ()		//Retrieves Role
  {
    return Role;
  }
  string   character::getName ()		//Retrieves Name
  {
    return Name;
  }
 int character:: getHealth ()		//Retrieves Health of the user
  {

    return Hit_points;
  }
  void character::setHealth (int amount)	// Sets the Health
  {
 
    Hit_points = amount;

  }

  int character::damage (int amount)	//If Wins it reduces the Hit Points
  {
     Hit_points =  getHealth () - amount;
    if ( Hit_points < 0)
      {
	          Hit_points = 0;
	          return 0;
      }
    return ( Hit_points);
  }

  int character::attack (character othercharacter)	// When character function
{

    int random;
    string result;
    // Generate random number limits from 1 to 20
    unsigned seed = time (0);
    //srand(seed);
   // random = (rand () % 19) + 1;
    random=(arc4random()%19)+1;
    
    if ((random + othercharacter.Attack_bonus) > othercharacter.Armor_class ||(random + othercharacter.Attack_bonus)== othercharacter.Armor_class)
      result = "HIT!";
    else
      result = "MISS!";

     print() << Name << " attacks!" << endl;
    //cout<<"Armor Class:"<<othercharacter.Armor_class<<endl;
     print() << "Attack roll:" << random << "+" << othercharacter.Attack_bonus <<
      "=" << random + othercharacter.Attack_bonus << "-->" << result << endl;
    // Generates Random number between 1 to 10
    seed = time (0);
    //srand(seed);
    random = (arc4random() % 9) + 1;
    int res = -999;
    if (result == "HIT!")
      {
	int sum = random + Damage_bonus;
	 print() << "Damage:" << random << "+" << Damage_bonus << "=" << sum <<
	  endl;
	res = othercharacter.damage (sum);
	 print() << othercharacter.getName () << " has " << res <<" hit points remaining." << endl;
      }
                 
    return res;
  }
ostream& character::print(std::ostream& outs )
{
    static std::ostream& gbl_out = outs;
    return gbl_out;
}
void character ::getSummary()
{
  print()<<"Character Summary:"<<endl;
  print()<<"---------------------------------------------"<<endl;
  print()<<getName()<<" the "<<getRole()<<endl;
  print()<<"HP:"<<Hit_points<<endl;
  print()<<"AB:"<<Attack_bonus<<endl;
  print()<<"DB:"<<Damage_bonus<<endl;
  print()<<"AC:"<<Armor_class<<endl;
}









