
#include <iostream>
#include<string.h>
#include<fstream>
#include<time.h>
#include<ctime>
#include<vector>
#include<bits/stdc++.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

class character
{
string Name;
string Role;
int Hit_points;
int Attack_bonus;
int Damage_bonus;
int Armor_class;
vector<int>v;

public:
character(string name1,string Role1,int hit, int Attack,int Damage,int Armor,vector<int> v1)
{
    Name=name1;
    Role=Role1;
    Hit_points=hit;
    Attack_bonus=Attack;
    Damage_bonus=Damage;
    Armor_class=Armor;
    v=v1;
}
string getRole() //Retrieves Role
{
    return Role;
}
string getName() //Retrieves Name
{
    return Name;
}
int getHealth()  //Retrieves Health of the user
{

    return Hit_points;
}
void setHealth(int amount)  // Sets the Health
{
    if(Hit_points<amount) Hit_points=0;
    Hit_points=Hit_points-amount;
    
}

int damage(int amount)    //If Wins it reduces the Hit Points
{   
    this->Hit_points=this->getHealth()-amount;
    if (this->Hit_points<amount) 
    {   this->Hit_points=0;
        return 0;
    }
    return (this->Hit_points);
}
int attack (character othercharacter )      // When character function
{

    int random;
    string result;
    // Generate random number limits from 1 to 20
    unsigned seed=time(0);
    srand(seed);
    random=(rand()%20)+1;
    random=14;
    if (random+othercharacter.Attack_bonus>=othercharacter.Armor_class) result="HIT!";
    else result="MISS!";
    
    cout<<Name<<" attacks!"<<endl;
    cout<<"Attack roll:"<<random<<"+"<<othercharacter.Attack_bonus<<"="<<random+othercharacter.Attack_bonus<<"-->"<<result<<endl;
    // Generates Random number between 1 to 10
     seed=time(0);
    srand(seed);
    random=(rand()%10)+1;
    int res=-999;
    if(result=="HIT!")
    {
        int sum=random+Damage_bonus;
        cout<<"Damage:"<<random<<"+"<<Damage_bonus<<"="<<sum<<endl;
        res=othercharacter.damage(sum);
        cout<<othercharacter.getName()<<" has "<<res<<" hit points remaining."<<endl;
        
    
    }
        return res;    
}
void print(iostream& f);
};

// Driver Code
int main()
{   
    string fname, frole;
    int fhpoints,fabonus,fdbonus, farmor_class;
    string sname, srole;
    int shpoints,sabonus,sdbonus, sarmor_class;

    cout<<"First Character name?"<<endl;
    cin>>fname;
    cout<<fname<<"'s role"<<endl;
    cin>>frole;
    cout<<endl;
    cout<<fname<<" the "<<frole<<"'s hit points?"<<endl;
    cin>>fhpoints;
    cout<<endl;
    cout<<fname<<" the "<<frole<<"'s attack bonus?"<<endl;
    cin>>fabonus;
    cout<<endl;
    cout<<fname<<" the "<<frole<<"'s damage bonus?"<<endl;
    cin>>fdbonus;
    cout<<endl;
    cout<<fname<<" the "<<frole<<"'s armor class?"<<endl;
    cin>>farmor_class;
    cout<<endl;
    vector<int>FirstV;
    character character1(fname, frole,fhpoints,fabonus,fdbonus, farmor_class,FirstV);
    cout<<"Second Character name?"<<endl;
    cin>>sname;
    cout<<sname<<"'s role"<<endl;
    cin>>srole;
    cout<<endl;
    cout<<sname<<" the "<<srole<<"'s hit points?"<<endl;
    cin>>shpoints;
    cout<<endl;
    cout<<sname<<" the "<<srole<<"'s attack bonus?"<<endl;
    cin>>sabonus;
    cout<<endl;
    cout<<sname<<" the "<<srole<<"'s damage bonus?"<<endl;
    cin>>sdbonus;
    cout<<endl;
    cout<<sname<<" the "<<srole<<"'s armor class?"<<endl;
    cin>>sarmor_class;
    cout<<endl;
    vector<int>SecondV;
    character character2(sname, srole,shpoints,sabonus,sdbonus, sarmor_class,SecondV);
    cout<<"Simulated Combats:"<<endl;
    int res1,res2;
    do
    {
    int temp;
    res1=character1.attack(character2);
    if(res1!=-999) character2.setHealth(res1);
    if(res1 ==0) break;
    sleep(5);
    cout<<endl;
    res2=character2.attack(character1);
    if(res2!=-999) character1.setHealth(res2);
    if(res2==0) break;
    sleep(5);
    //cout<<"Char 1: "<<character1.getHealth() <<endl;
    //cout<<"Char 2: "<<character2.getHealth() <<endl;
    cout<<endl;
    }while(res1 !=0 && res2!=0);

    
    if (res1==0) cout<<character1.getName()<<" wins!";
    else if(res2==0) cout<<character2.getName()<<" wins!";
    


	return 0;
}
