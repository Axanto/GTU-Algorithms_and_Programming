#include <iostream>
#include "sports.cpp"
#include "meals.cpp"
#include "user.cpp"
#include <string.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int choice;


    system("cls");
    flag:
    cout<<"1. Developer Mode\n"
        <<"2. User Mode"
        <<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice==1)
    {
        developer_mode();
    }
    else if(choice==2)
    {
        user_login();
    }

    return 0;

}

void developer_mode()
{
    cout<<"--Developer Menu--\n"<<endl;
    cout<<"*******<User Class Tests>*******"<<endl;
    user us;
    cout<<us;
    cout<<"-Default constructor has been tested-\n"<<endl;
    cout<<"istream/ostream operator is being tested"<<endl;
    cin>>us;
    cout<<us;
    cout<<"-istream/ostream has been tested-\n"<<endl;
    user us2("Ahmet","Yilmaz",123,20,70,1);
    cout<<us2;
    cout<<"-Constructor has been tested-\n"<<endl;
    user us3(us);
    cout<<us3;
    cout<<"-Copy Constructor has been tested-\n"<<endl;
    us2=us3;
    cout<<us;
    cout<<"-Assignment Constructor has been tested-\n"<<endl;
    us=us2+us3;
    cout<<us;
    cout<<"+Operator has been tested\n"<<endl;
    cout<<"Name: "<<us2.get_name()<<endl;
    cout<<"Surname: "<<us2.get_surname()<<endl;
    cout<<"ID: "<<us2.get_ID()<<endl;
    cout<<"Age: "<<us2.get_age()<<endl;
    cout<<"Weight: "<<us2.get_weight()<<endl;
    cout<<"Week: "<<us2.get_week()<<endl;
    cout<<"-Get functions has been tested-\n"<<endl;
    cout<<"-User Class Tests are over-"<<endl;

    cout<<"\nPress a button to continue..."<<endl;
    getch();

    system("cls");

    cout<<"*******<Meals Class Tests>*******"<<endl;
    Breakfast bb;
    cout<<bb;
    cout<<"-Default constructor has been tested-\n"<<endl;
    Breakfast bf(2);
    cout<<bf;
    cout<<"-Constructor has been tested-"<<endl;
    bf= bf+bb;
    cout<<bf;
    cout<<"+Operator has been tested\n"<<endl;
    bf.set_size(3);
    cout<<"Set size operator is testing"<<endl;
    cout<<"kcal: "<<bf.get_kcal()<<endl;;
    cout<<"number: "<<bf.get_number()<<endl;;
    Lunch ll(3);
    Lunch lu=ll;
    cout<<ll;
    cout<<"-Assignment Constructor has been tested-\n"<<endl;
    cout<<"kcal: "<<ll.get_kcal()<<endl;
    cout<<"Get function has been tested"<<endl;
    Dinner dd(1);
    cout<<dd;
    Dinner di(2);
    cout<<di;
    cout<<"---------------------"<<endl;
    dd=dd+di;
    cout<<dd;
    cout<<"+Operator has been tested\n"<<endl;

    cout<<"\nPress a button to continue..."<<endl;
    getch();
    system("cls");

    cout<<"*******<Sports Class Tests>*******"<<endl;

    Tennis te(30);
    cout<<te;
    cout<<"-Constructor has been tested-\n"<<endl;
    Tennis tt;
    cout<<tt;
    tt=te;
    cout<<tt;
    cout<<"-Assignment Constructor has been tested-\n"<<endl;
    Swimming ss;
    cout<<"-Default constructor has been tested-\n"<<endl;
    Swimming s(10);
    ss=ss+s;
    cout<<ss;
    cout<<"+Operator has been tested\n"<<endl;



}

void user_login()
{

    int week,id,age;
    string name, surname;
    int choice, us=0;
    double weight;
    user u[7];

    flag5:
        cout<<"\n1. Login\n"
            <<"2. Register\n"
            <<"Enter your choice: ";
            cin>>choice;

    if(choice==2){
            cout<<"\nEnter user's name: ";
            cin>>name;
            u[us].set_name(name);
            cout<<"\nEnter user's surname: ";
            cin>>surname;
            u[us].set_surname(surname);
            cout<<"\nEnter user's age: ";
            cin>>age;
            u[us].set_age(age);
            cout<<"\nEnter user's ID number: ";
            cin>>id;
            u[us].set_ID(id);
            cout<<"\nEnter the user's weight: ";
            cin>>weight;
            u[us].set_weight(weight);
            cout<<"\nEnter the week number: ";
            cin>>week;
            u[us].set_week(week);

            us++;

            cout<<"\nPress a button to continue..."<<endl;
            getch();

            goto flag5;
        }

        else if(choice==1)
        {
            cout<<"Please enter your id: ";
            cin>>id;
            for(int i=0; i<7; i++){
                if(id==u[i].get_ID())
                    user_menu();
                else
                {
                    cout<<"Wrong id:"<<endl;
                    goto flag5;

                }
            }
        }
}
void user_menu()
{

    int choice,choice2, sport, meal, size, gain=0, lost=0;
    string name, surname, day;
    int week,id,age,minute,i=0, kcal=0, kcal2=0, a=0, us=0;
    int number_bre=0, number_lun=0, number_din=0, number_bas=0, number_foo=0, number_ten=0, number_swim=0;
    double weight, kc=0;
    string days[7]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

    Breakfast bre[7];
    Lunch lun[7];
    Dinner din[7];
    Basketball bas[7];
    Football foo[7];
    Tennis ten[7];
    Swimming swim[7];
    user u[7];



                flag3:
                system("cls");
                cout<<"1. Calculate calories after sport\n"
                    <<"2. Calculate calories after meal\n"
                    <<"3. Show how many meals has eaten\n"
                    <<"4. Show how many sport has done\n"
                    <<"5. Show calories gained and lost weekly\n"
                    <<"6. Exit\n"
                    <<endl;
                cout<<"Enter your choice: ";
                cin>>choice;


                if(choice==1)
                {
                    system("cls");
                    cout<<"For which day do you want to enter value? (please enter only small letters)"<<endl;
                    cin>>day;
                    while(i<7)
                    {
                        if(strcmp(days[i].c_str(),day.c_str())==0){
                            a++;
                            break;
                        }
                        i++;
                    }
                    if(a==0)
                        {
                            cout<<"There is no such a day"<<endl;
                            exit(1);
                        }
                    sportsf:
                    cout<<"1. Basketball\n"
                        <<"2. Football\n"
                        <<"3. Tennis\n"
                        <<"4. Swimming\n"
                        <<"\nWhich sport is user doing? :";
                    cin>>sport;

                    cout<<"How many minute is user doing this sport?";
                    cin>>minute;

                    if(sport==1)
                    {
                        kcal+=bas[i].lost_kcal(minute);
                        cout<<"\n"<<bas[i].get_kcal()<<" kcal has been given"<<endl;
                    }
                    else if(sport==2)
                    {
                        kcal+=foo[i].lost_kcal(minute);
                        cout<<"\n"<<foo[i].get_kcal()<<" kcal has been given"<<endl;
                    }
                    else if(sport==3)
                    {
                        kcal+=ten[i].lost_kcal(minute);
                        cout<<"\n"<<ten[i].get_kcal()<<" kcal has been given"<<endl;
                    }
                    else if(sport==4)
                    {
                        kcal+=swim[i].lost_kcal(minute);
                        cout<<"\n"<<swim[i].get_kcal()<<" kcal has been given"<<endl;
                    }
                    else{
                        cout<<"There is no such an option"<<endl;
                        goto sportsf;
                    }

                    u[i].daily_calorie_lost(kcal);
                    kcal=0;
                    cout<<"\nPress a button to continue..."<<endl;
                    getch();
                    goto flag3;
                }
                else if(choice==2)
                {
                    system("cls");
                    flag1:
                    cout<<"For which day do you want to enter value? (please enter only small letters)"<<endl;
                    cin>>day;
                    while(i<7)
                    {
                        if(strcmp(days[i].c_str(),day.c_str())==0){
                            a++;
                            break;
                        }
                        i++;
                    }
                     if(a==0)
                        {
                            cout<<"There is no such a day"<<endl;
                            goto flag1;
                        }

                    cout<<"1. Breakfast\n"
                        <<"2. Lunch\n"
                        <<"3. Dinner\n"
                        <<"\nWhich meal is user eating? :";
                    cin>>meal;
                    flag2:
                    cout<<"1. Small\n"
                        <<"2. Medium\n"
                        <<"3. Large\n"
                        <<"\nWhich size of a meal does the user eat?: ";
                        cin>>size;
                    if(0<size&&size<4){
                    if(meal==1&&size==1) {bre[i].set_size(size); kcal2+=bre[i].get_kcal(); cout<<"\n "<<bre[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==1&&size==2) {bre[i].set_size(size); kcal2+=bre[i].get_kcal(); cout<<"\n "<<bre[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==1&&size==3) {bre[i].set_size(size); kcal2+=bre[i].get_kcal(); cout<<"\n "<<bre[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==2&&size==1) {lun[i].set_size(size); kcal2+=lun[i].get_kcal(); cout<<"\n "<<lun[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==2&&size==2) {lun[i].set_size(size); kcal2+=lun[i].get_kcal(); cout<<"\n "<<lun[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==2&&size==3) {lun[i].set_size(size); kcal2+=lun[i].get_kcal(); cout<<"\n "<<lun[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==3&&size==1) {din[i].set_size(size); kcal2+=din[i].get_kcal(); cout<<"\n "<<din[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==3&&size==2) {din[i].set_size(size); kcal2+=din[i].get_kcal(); cout<<"\n "<<din[i].get_kcal()<<" kcal has been taken"<<endl;}
                    if(meal==3&&size==3) {din[i].set_size(size); kcal2+=din[i].get_kcal(); cout<<"\n "<<din[i].get_kcal()<<" kcal has been taken"<<endl;}

                    u[i].daily_calorie_taken(kcal2);
                    kcal2=0;
                    }
                    else{
                    cout<<"You cannot enter a number bigger than 3";
                    goto flag2;
                    }
                    cout<<"\nPress a button to continue..."<<endl;
                    getch();

                    goto flag3;
                }
                else if(choice==3)
                {
                    system("cls");
                    for(int j=0; j<7; j++)
                    {
                        number_bre+=bre[j].get_number();
                        number_lun+=lun[j].get_number();
                        number_din+=din[j].get_number();
                    }
                    cout<<"Number of Breakfast Per Week: "<<number_bre<<endl;
                    cout<<"Number of Lunch Per Week: "<<number_lun<<endl;
                    cout<<"Number of Dinner Per Week: "<<number_din<<endl;

                        number_bre=0;
                        number_lun=0;
                        number_din=0;

                    cout<<"\nPress a button to continue..."<<endl;
                    getch();

                    goto flag3;
                }
                else if(choice==4)
                {
                    system("cls");
                    for(int k=0; k<7; k++)
                    {
                        number_bas+=bas[k].get_number();
                        number_foo+=foo[k].get_number();
                        number_ten+=ten[k].get_number();
                        number_swim+=swim[k].get_number();

                    }
                    cout<<"Number of Basketball Per Week: "<<number_bas<<endl;
                    cout<<"Number of Football Per Week: "<<number_foo<<endl;
                    cout<<"Number of Tennis Per Week: "<<number_ten<<endl;
                    cout<<"Number of Swimming Per Week: "<<number_swim<<endl;

                    number_bas=0;
                    number_foo=0;
                    number_ten=0;
                    number_swim=0;

                    cout<<"\nPress a button to continue..."<<endl;
                    getch();

                    goto flag3;
                }
                else if(choice==5)
                {
                    system("cls");
                    for(int z=0; z<7; z++)
                    {
                        gain+=u[z].get_gkcal();
                        lost+=u[z].get_lkcal();

                        cout<<"Net kcal of "<<days[z]<<" :"<<u[z].get_gkcal()-u[z].get_lkcal()<<endl;
                    }

                        cout<<"The amount of calories consumed by the user: "<<gain<<endl;
                        cout<<"The amount of calories given by the user: "<<lost<<endl;
                        gain=0;
                        lost=0;

                    cout<<"\nPress a button to continue..."<<endl;
                    getch();

                    goto flag3;
                }

                else if(choice==6)
                    exit(0);
                else
                {
                    cout<<"There is no such an option!"<<endl;
                    main();
                }
}


