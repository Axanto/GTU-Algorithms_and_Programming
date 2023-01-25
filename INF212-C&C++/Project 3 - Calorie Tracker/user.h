#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string.h>
#include "meals.h"
#include "sports.h"

class user{
private:
    int week;
    string name;
    string surname;
    int ID;
    int age;
    double weight;
    double gain=0;
    double lose=0;
    double gkcal;
    double lkcal;

    Breakfast bre[7];
    Lunch lun[7];
    Dinner din[7];
    Basketball bas[7];
    Football foo[7];
    Tennis ten[7];
    Swimming swim[7];



public:

    user();
    user(string name,string surname,int ID,int age,double weight,int week);
    user(const user& obj);
    user& operator=(const user& obj);
    user& operator +(const user &obj);
    friend ostream &operator << (ostream &output,user &u);
    friend istream &operator >> (istream &input, user &u);

    void set_week(int week);
    void set_name(string name);
    void set_surname(string soyisim);
    void set_ID(int ID);
    void set_age(int age);
    void set_weight(double weight);
    int get_week();
    string get_name();
    string get_surname();
    int get_ID();
    int get_age();
    double get_weight();
    double get_gkcal();
    double get_lkcal();

    void daily_calorie_taken(int kc);
    void daily_calorie_lost(int kc);


};

ostream &operator << (ostream &output,user &u);
istream &operator >> (istream &input, user &u);
void user_menu();
void user_login();
void developer_mode();

#endif // USER_H_INCLUDED
