#include <iostream>
#include <string.h>
#include "meals.h"
#include "sports.h"
#include "user.h"

using namespace std;

user::user(){
    name = "NULL";
    surname = "NULL";
    ID = 0;
    age = 0;
    weight = 0.0;
    week = 0;
}
user::user(string name,string surname,int ID,int age,double weight,int week ){
    this->week = week;
    this->name = name;
    this->surname = surname;
    this->ID = ID;
    this->age = age;
    this->weight = weight;
}

user::user(const user &obj){
    this->week = obj.week;
    this->name = obj.name;
    this->surname = obj.surname;
    this->ID = obj.ID;
    this->age = obj.age;
    this->weight = obj.weight;
    this->gain = obj.gain;
    this->lose = obj.lose;
}
user &user::operator=(const user &obj){
    this->week = obj.week;
    this->name = obj.name;
    this->surname = obj.surname;
    this->ID = obj.ID;
    this->age = obj.age;
    this->weight = obj.weight;
    this->gain = obj.gain;
    this->lose = obj.lose;
    return *this;
}
user &user::operator+(const user &obj){
    this->week = this->week + obj.week;
    this->name = this->name + obj.name;
    this->surname = this->surname + obj.surname;
    this->ID = this->ID + obj.ID;
    this->age = this->age + obj.age;
    this->weight = this->weight + obj.weight;
    this->gain = this->gain + obj.gain;
    this->lose = this->lose + obj.lose;
    return *this;
}

ostream &operator << (ostream &output,user &u){
    output<<"--User Info--"<<endl;
    output<<"ID: "<<u.ID<<endl;
    output<<"Name: "<<u.name<<endl;
    output<<"Surname: "<<u.surname<<endl;
    output<<"Age: "<<u.age<<endl;
    output<<"Week: "<<u.week<<endl;
    output<<"Weight: "<<u.weight;
    if(u.gain!=0 && u.lose!=0){
        output<<" Taken kcal: "<<u.gain
        <<"\nGiven kcal: "<<u.lose<<endl;
    }
    cout<<endl;
    return output;
}
istream &operator >> (istream &input, user &u){
    cout<<"Name: ";
    input>>u.name;
    cout<<"Surname: ";
    input>>u.surname;
    cout<<"Age: ";
    input>>u.age;
    cout<<"ID: ";
    input>>u.ID;
    cout<<"Week: ";
    input>>u.week;
    cout<<"Weight: ";
    input>>u.weight;
    return input;
}



void user::set_week(int week){this->week = week;}
void user::set_name(string name){this->name = name;}
void user::set_surname(string surname){this->surname = surname;}
void user::set_ID(int ID){this->ID = ID;}
void user::set_age(int age){this->age = age;}
void user::set_weight(double weight){this->weight = weight;}

int    user::get_week(){return week;}
string user::get_name(){return name;}
string user::get_surname(){return surname;}
int    user::get_ID(){return ID;}
int    user::get_age(){return age;}
double user::get_weight(){return weight;}
double user::get_gkcal(){return gain;}
double user::get_lkcal(){return lose;}



void user::daily_calorie_lost(int kc)
{
    lose+=kc;

}

void user::daily_calorie_taken(int kc){
    gain+=kc;
}



