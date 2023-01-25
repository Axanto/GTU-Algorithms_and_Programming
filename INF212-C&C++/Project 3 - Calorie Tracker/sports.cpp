#include <iostream>
#include <string.h>
#include "sports.h"

using namespace std;

Basketball::Basketball(){
    //default constructor
    minute=0;
    kcal=0;
    number=0;
}
Basketball::Basketball(int minute){
    //constructor
    this->minute = minute;
    kcal=minute*6;
}

Basketball::Basketball(const Basketball& obj)
{
    //copy ctor
    minute=obj.minute;
    kcal=obj.kcal;
}

Basketball& Basketball::operator=(const Basketball& obj)
{
    //assignment ctor
    minute=obj.minute;
    kcal=obj.kcal;
    return *this;
}

Basketball &Basketball::operator+(const Basketball &obj){
    this->minute = this->minute + obj.minute;
    this->kcal = this->kcal + obj.kcal;
    return *this;
}

ostream &operator << (ostream &output,Basketball &obj){
output<<"minute: "<<obj.minute<<"\nkcal: "<<obj.kcal<<endl;
return output;
}

int Basketball::lost_kcal(int minute){
    kcal=minute*6;
    number++;
    return kcal;
}
int Basketball::get_minute(){return minute;}
double Basketball::get_kcal(){return kcal;}
int Basketball::get_number(){return number;}

/*************************************************************/

Football::Football(){
    //default constructor
    minute=0;
    kcal=0;
    number=0;
}
Football::Football(int minute){
    //constructor
    this->minute = minute;
    kcal = minute * 5 ;
}

Football::Football(const Football& obj)
{
    //copy ctor
    minute=obj.minute;
    kcal=obj.kcal;
}

Football& Football::operator=(const Football& obj)
{
    //assignment ctor
    minute=obj.minute;
    kcal=obj.kcal;
    return *this;
}

Football &Football::operator+(const Football &obj){
    this->minute = this->minute + obj.minute;
    this->kcal = this->kcal + obj.kcal;
    return *this;
}

ostream &operator << (ostream &output,Football &obj){
output<<"minute: "<<obj.minute<<"kcal: "<<obj.kcal<<endl;
return output;
}

int Football::lost_kcal(int minute)
{
    kcal=minute*5;
    number++;
    return kcal;
}
int Football::get_minute(){return minute;}
double Football::get_kcal(){return kcal;}
int Football::get_number(){return number;}

/*************************************************************/

Tennis::Tennis()
{
    //Default Constructor
    minute=0;
    kcal=0;
    number=0;
}
Tennis::Tennis(int minute)
{
    //Constructor
    this->minute = minute;
    kcal = minute * 5 ;
}

Tennis::Tennis(const Tennis& obj)
{
    //copy ctor
    minute=obj.minute;
    kcal=obj.kcal;
}

Tennis& Tennis::operator=(const Tennis& obj)
{
    //assignment ctor
    minute=obj.minute;
    kcal=obj.kcal;
    return *this;
}

Tennis &Tennis::operator+(const Tennis &obj){
    this->minute = this->minute + obj.minute;
    this->kcal = this->kcal + obj.kcal;
    return *this;
}

ostream &operator << (ostream &output,Tennis &obj){
output<<"minute: "<<obj.minute<<"\nkcal: "<<obj.kcal<<endl;
return output;
}

int Tennis::lost_kcal(int minute)
{
    kcal=minute*5;
    number++;
    return kcal;
}
int Tennis::get_minute(){return minute;}
double Tennis::get_kcal(){return kcal;}
int Tennis::get_number(){return number;}

/*************************************************************/

Swimming::Swimming()
{
    //Default Constructor
    minute=0;
    kcal=0;
    number=0;
}
Swimming::Swimming(int minute)
{
    //Constructor
    this->minute = minute;
    kcal = minute * 7 ;
}
//ctors
Swimming::Swimming(const Swimming& obj)
{
    //copy ctor
    minute=obj.minute;
    kcal=obj.kcal;
}

Swimming&  Swimming::operator=(const Swimming& obj)
{
    //assignment ctor
    minute=obj.minute;
    kcal=obj.kcal;
    return *this;
}

Swimming &Swimming::operator+(const Swimming &obj){
    this->minute = this->minute + obj.minute;
    this->kcal = this->kcal + obj.kcal;
    return *this;
}

ostream &operator << (ostream &output,Swimming &obj){
output<<"minute: "<<obj.minute<<"\nkcal: "<<obj.kcal<<endl;
    return output;
}

int Swimming::lost_kcal(int minute)
{
    kcal=minute*7;
    number++;
    return kcal;
}
int Swimming::get_minute(){return minute;}
double Swimming::get_kcal(){return kcal;}
int Swimming::get_number(){return number;}


