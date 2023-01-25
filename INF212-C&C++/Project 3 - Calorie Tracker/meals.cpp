#include <iostream>
#include <string.h>
#include "meals.h"
using namespace std;

Breakfast::Breakfast()
{
    size = 0.0;
    kcal = 0.0;
    number=0;

}
Breakfast::Breakfast(int size)
{
    this->size = size;
    if(size==1){kcal = 200;}
    else if(size==2){kcal = 400;}
    else{kcal = 600;}
}
//const

void Breakfast::set_size(int size)
{
     this->size = size;
    if(size==1){kcal = 200;}
    else if(size==2){kcal = 400;}
    else{kcal = 600;}
    number++;
}

Breakfast::Breakfast(const Breakfast& obj){
    this->size = obj.size;
    this->kcal = obj.kcal;

}

Breakfast &Breakfast::operator=(const Breakfast &obj){
    this->size = obj.size;
    this->kcal = obj.kcal;
    return *this;
}

Breakfast &Breakfast::operator+(const Breakfast &obj){
    this->size = this->size + obj.size;
    this->kcal = this->kcal + obj.kcal;
    return *this;
}

ostream &operator << (ostream &output,Breakfast &obj){
output<<"size: "<<obj.size<<"\nkcal: "<<obj.kcal<<endl;
return output;
}

int Breakfast::get_size(){return size;}
double Breakfast::get_kcal(){return kcal;}
int Breakfast::get_number(){return number;}
///////////////////////////
Lunch::Lunch()
{
    size = 0;
    kcal = 0.0;
    number=0;
}
Lunch::Lunch(int size)
{
    this->size = size;
    if(size==1){kcal = 400;}
    else if(size==2){kcal = 600;}
    else{kcal = 800;}
}

void Lunch::set_size(int size)
{
    this->size = size;
    if(size==1){kcal = 400;}
    else if(size==2){kcal = 600;}
    else{kcal = 800;}
    number++;
}

Lunch::Lunch(const Lunch& obj){
    this->size = obj.size;
    this->kcal = obj.kcal;

}

Lunch &Lunch::operator=(const Lunch &obj){
    this->size = obj.size;
    this->kcal = obj.kcal;
    return *this;
}

Lunch &Lunch::operator+(const Lunch &obj){
    this->size = this->size + obj.size;
    this->kcal = this->kcal + obj.kcal;
    return *this;
}

ostream &operator << (ostream &output,Lunch &obj){
output<<"size: "<<obj.size<<"\nkcal: "<<obj.kcal<<endl;
return output;
}

int Lunch::get_size(){return size;}
double Lunch::get_kcal(){return kcal;}
int Lunch::get_number(){return number;}
///////////////////////////
Dinner::Dinner(){
    size = 0;
    kcal = 0.0;
    number=0;
}
Dinner::Dinner(int size){

    this->size = size;
    if(size==1){kcal = 400;}
    else if(size==2){kcal = 600;}
    else{kcal = 800;}
}

void Dinner::set_size(int size)
{
    this->size = size;
    if(size=1){kcal = 400;}
    else if(size=2){kcal = 600;}
    else{kcal = 800;}
    number++;
}

Dinner::Dinner(const Dinner& obj){
    this->size = obj.size;
    this->kcal = obj.kcal;
}

Dinner &Dinner::operator=(const Dinner &obj){
    this->size = obj.size;
    this->kcal = obj.kcal;
    return *this;
}

Dinner &Dinner::operator+(const Dinner &obj){
    this->size = this->size + obj.size;
    this->kcal = this->kcal + obj.kcal;
    return *this;
}
ostream &operator <<(ostream &output,Dinner &obj){
output<<"size :" <<obj.size<<"\nkcal: "<<obj.kcal<<endl;
return output;
}

int Dinner::get_size(){return size;}
double Dinner::get_kcal(){return kcal;}
int Dinner::get_number(){return number;}
///////////////////
