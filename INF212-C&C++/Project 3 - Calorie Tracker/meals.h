#ifndef MEALS_H_INCLUDED
#define MEALS_H_INCLUDED
#include <string.h>

using namespace std;

class Breakfast{
private:
    int size;
    double kcal=0;
    int number=0;

public:
    Breakfast();
    Breakfast(int size);
    Breakfast(const Breakfast& obj);
    Breakfast& operator =(const Breakfast& obj);
    Breakfast& operator +(const Breakfast &obj);
    friend ostream &operator << (ostream &output,Breakfast &obj);

    void set_size(int size);
    int get_size();
    double get_kcal();
    int get_number();
};

class Lunch{
private:
    int size;
    double kcal=0;
    int number=0;
public:
    Lunch();
    Lunch(int size);
    Lunch(const Lunch& obj);
    Lunch& operator =(const Lunch& obj);
    Lunch& operator +(const Lunch &obj);
    friend ostream &operator << (ostream &output,Lunch &obj);

    void set_size(int size);
    int get_size();
    double get_kcal();
    int get_number();
};

class Dinner{
private:
    int size;
    double kcal=0;
    int number=0;
public:
    Dinner();
    Dinner(int size);
    Dinner(const Dinner& obj);
    Dinner& operator=(const Dinner& obj);
    Dinner& operator +(const Dinner &obj);
    friend ostream &operator << (ostream &output,Dinner &obj);

    void set_size(int size);
    int get_size();
    double get_kcal();
    int get_number();
};

ostream &operator << (ostream &output,Breakfast &obj);
ostream &operator << (ostream &output,Lunch &obj);
ostream &operator << (ostream &output,Dinner &obj);

#endif // MEALS_H_INCLUDED
