#ifndef SPORTS_H_INCLUDED
#define SPORTS_H_INCLUDED
#include <string.h>

using namespace std;

class Basketball{

private:
    int minute;
    double kcal=0;
    int number=0;
public:
    Basketball();
    Basketball(int minute);
    Basketball(const Basketball& obj);
    Basketball& operator=(const Basketball& obj);
    Basketball& operator +(const Basketball &obj);
    friend ostream& operator <<(ostream &output,Basketball &obj);

    int lost_kcal(int minute);
    int get_minute();
    double get_kcal();
    int get_number();
};

class Football{

private:
    int minute;
    double kcal=0;
    int number=0;
public:
    Football();
    Football(int minute);
    Football(const Football& obj);
    Football& operator=(const Football& obj);
    Football& operator +(const Football &obj);
    friend ostream &operator << (ostream &output,Football &obj);

    int lost_kcal(int minute);
    int get_minute();
    double get_kcal();
    int get_number();
};

class Tennis{
private:
    int minute;
    double kcal=0;
    int number=0;
public:
    Tennis();
    Tennis(int minute);
    Tennis(const Tennis& obj);
    Tennis& operator=(const Tennis& obj);
    Tennis& operator +(const Tennis &obj);
    friend ostream &operator << (ostream &output,Tennis &obj);

    int lost_kcal(int minute);
    int get_minute();
    double get_kcal();
    int get_number();
};
class Swimming{
private:
    int minute;
    double kcal=0;
    int number=0;
public:
    Swimming();
    Swimming(int minute);
    Swimming(const Swimming& obj);
    Swimming& operator=(const Swimming& obj);
    Swimming& operator +(const Swimming &obj);
    friend ostream &operator << (ostream &output,Swimming &obj);

    int lost_kcal(int minute);
    int get_minute();
    double get_kcal();
    int get_number();
};
ostream& operator<<(ostream &output,Basketball &obj);
ostream& operator<<(ostream &output,Football &obj);
ostream& operator<<(ostream &output,Tennis &obj);
ostream& operator<<(ostream &output,Swimming &obj);


#endif // SPORTS_H_INCLUDED
