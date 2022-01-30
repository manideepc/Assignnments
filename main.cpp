
#include <iostream>
#include<string.h>
#include<fstream>
#include<time.h>
#include<ctime>
#include <cstdlib>
#include <unistd.h>
#include "character.hpp"
using namespace std;

int main ()
{
  cout<<"Enter First Character Name:"<<endl;
  character char1;
  char1.print()<<"----------------------------------------"<<endl;
  char1.print()<<"Enter Second Character Name:"<<endl;
  character char2;
  char1.print()<<"----------------------------------------"<<endl;

  
  char1.print() << endl<<"Simulated Combats:" << endl;
  char1.print() <<endl;
  int res1, res2;
  do
    {
      int temp;
      res1 = char1.attack (char2);
      if (res1 != -999) 	char2.setHealth (res1);
      if (res1 == 0)
      {   char1.print() << char1.getName () << " wins!";
          break;
      }
      res2 = char2.attack (char1);
      if (res2 != -999) char1.setHealth (res2);
      if (res2 == 0)
      {
          char2.print() << char2.getName () << " wins!";
	      break;
      }
      char2.print() << endl;
      char2.print()<<"----------------------------------------------"<<endl;
    }
  while (res1 != 0 && res2 != 0);




  return 0;
}