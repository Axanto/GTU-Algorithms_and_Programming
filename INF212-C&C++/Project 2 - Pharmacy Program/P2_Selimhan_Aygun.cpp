#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;
class Eczane
{
    int eczn_id;
    string eczn_isim;
    string eczn_adres;

    public:
    Eczane()
    {
        eczn_id=0;
        eczn_isim = "NULL";
        eczn_adres = "NULL";
    }

    Eczane(int id, string isim, string adres, string sifre)
    {
        eczn_id = id;
        eczn_isim = isim;
        eczn_adres = adres;
    }
    Eczane(const Eczane &other)
    {
        eczn_id = other.eczn_id;
        eczn_isim=other.eczn_isim;
        eczn_adres=other.eczn_adres;
    }

    Eczane &operator=(const Eczane &other)
    {
        eczn_id = other.eczn_id;
        eczn_isim=other.eczn_isim;
        eczn_adres=other.eczn_adres;
    }

    int get_eczn_id()
    {
        return eczn_id;
    }
    string get_eczn_isim()
    {
        return eczn_isim;
    }
    string get_eczn_adres()
    {
        return eczn_adres;
    }
    void eczn_olustur();
    void eczn_goster();
    void eczn_ilac_sayfasi();
    void eczn_ara(string isim);
};

class Ilac
{
    int ilac_id;
    int ilac_sayisi;
    double ilac_fiyati;
    string ilac_isim;

public:

    Ilac()
    {
        ilac_id = 0;
        ilac_sayisi = 0;
        ilac_fiyati = 0.0;
        ilac_isim = "NULL";

    }

    Ilac(int id, int sayi, double fiyat, string isim)
    {
        ilac_id = id;
        ilac_sayisi = sayi;
        ilac_fiyati = fiyat;
        ilac_isim = isim;
    }

    Ilac(const Ilac &other)
    {
        ilac_id = other.ilac_id;
        ilac_sayisi = other.ilac_sayisi;
        ilac_fiyati = other.ilac_fiyati;
        ilac_isim = other.ilac_isim;

    }

    Ilac &operator=(const Ilac &other)
    {
        ilac_id = other.ilac_id;
        ilac_sayisi = other.ilac_sayisi;
        ilac_fiyati = other.ilac_fiyati;
        ilac_isim = other.ilac_isim;
    }


        void ilac_olustur(string ecz_ad);
        void ilac_goster();
        void ilac_duzenle(string eczn_isim);
        void ilac_ara(string ilac_adi);
        void ilac_listesi(string isim);


};

void eczn_ekle(int eczn_id, string eczn_isim, string eczn_adres);
void admin_menu();
void customer_menu();

void Eczane::eczn_olustur()
{
    cout.setf(ios::left);

    cout<<setw(18)<<"Eczane ID: ";
    cin>>eczn_id;

    cout<<setw(18)<<"Eczane Adi: ";
    cin>>eczn_isim;

    cout<<setw(18)<<"Eczane Adresi: ";
    cin>>eczn_adres;

    eczn_ekle(eczn_id, eczn_isim, eczn_adres);

    eczn_ilac_sayfasi();

}

void eczn_ekle(int eczn_id, string eczn_isim, string eczn_adres)
{
    fstream file;
    file.open("eczane_listesi.dat", ios::in | ios::out | ios::app);

    file<<setw(18)<<eczn_id
        <<setw(18)<<eczn_isim
        <<setw(18)<<eczn_adres
        <<endl;

}

void Eczane::eczn_goster()
{
    cout.setf(ios::left);
    cout<<setw(18)<<"Eczane ID: "<<eczn_id<<endl;
    cout<<setw(18)<<"Eczane Adi: "<<eczn_isim<<endl;
    cout<<setw(18)<<"Eczane Adresi: "<<eczn_adres<<endl;

}

void Eczane::eczn_ilac_sayfasi()
{
    fstream file2;
    file2.open((eczn_isim +"_ilac" + ".dat").c_str(), ios::out | ios::in | ios::app);
    file2.close();
}

void eczaneleri_goster()
{
    Eczane A;
    fstream file;
    int counter=0;
    int eczn_id=A.get_eczn_id();
    string eczn_isim=A.get_eczn_isim();
    string eczn_adres=A.get_eczn_adres();
    file.open("eczane_listesi.dat", ios::in);

    while(file>>eczn_id)
    {

        file>>eczn_isim;
        file>>eczn_adres;

    if(counter==0){
    cout.setf(ios::left);
    cout<<setw(15)<<"ID"<<setw(15)<<"ECZANE ADI"<<setw(15)<<"ADRES"<<endl;
    cout<<"---------------------------------------------"<<endl;
    counter++;
    }
    cout<<setw(15)<<eczn_id<<setw(15)<<eczn_isim<<setw(15)<<eczn_adres<<endl;
    }
    file.close();
}

void Eczane::eczn_ara(string isim)
{
   fstream file;
   int counter=0;
   file.open("eczane_listesi.dat", ios::in);

   while(file>>eczn_id)
   {

       file>>eczn_isim;
       file>>eczn_adres;

       if(eczn_isim.compare(isim)==0)
       {
           eczn_goster();
           counter++;
       }

   }
   if(counter==0)
   cout<<"Boyle bir eczane bulunamamistir"<<endl;

   file.close();
}

void Ilac::ilac_listesi(string isim)
{

    int counter=0;

    ifstream file((isim +"_ilac" + ".dat").c_str());

    if(file)
    {
        while(file>>ilac_id)
        {

        file>>ilac_isim;
        file>>ilac_fiyati;
        file>>ilac_sayisi;

        if(counter==0){
        cout.setf(ios::left);
        cout<<setw(15)<<"ILAC ID"<<setw(15)<<"ILAC ADI"<<setw(15)<<"ILAC FIYATI"<<setw(15)<<"ILAC SAYISI"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
        counter++;
        }

        cout<<setw(15)<<ilac_id<<setw(15)<<ilac_isim<<setw(15)<<ilac_fiyati<<setw(15)<<ilac_sayisi<<endl;

        }
    }

    else{
        cout<<"Bu isimde bir eczane bulunamadý!"<<endl;
    }
}
void ilac_ekle(string ecz_ad, int id, string isim, int fiyat, int sayi)
{
    fstream file2;
    file2.open((ecz_ad + "_ilac" + ".dat").c_str() , ios::out | ios::in | ios::app);

    file2<<setw(15)<<id
        <<setw(15)<<isim
        <<setw(15)<<fiyat
        <<setw(15)<<sayi
        <<endl;


}

void Ilac::ilac_olustur(string ecz_ad)
{

    ifstream file((ecz_ad +"_ilac" + ".dat").c_str());

    if(file)
    {
    cout.setf(ios::left);

    cout<<setw(15)<<"\nIlac ID: ";
    cin>>ilac_id;

    cout<<setw(15)<<"\nIlac Adi: ";
    cin>>ilac_isim;

    cout<<setw(15)<<"\nIlac Fiyati: ";
    cin>>ilac_fiyati;

    cout<<setw(15)<<"\nIlac Sayisi: ";
    cin>>ilac_sayisi;

    ilac_ekle(ecz_ad, ilac_id, ilac_isim, ilac_fiyati, ilac_sayisi);
    }
    else{
        cout<<"\nGirdiginiz isimde eczane bulunmamaktadir"<<endl;
    }
    file.close();

}

void Ilac::ilac_goster()
{
    cout.setf(ios::left);

    cout<<setw(15)<<"Ilac ID: "<<ilac_id<<endl;
    cout<<setw(15)<<"Ilac Adi: "<<ilac_isim<<endl;
    cout<<setw(15)<<"Ilac Fiyati: "<<ilac_fiyati<<endl;
    cout<<setw(15)<<"Ilac Sayisi: "<<ilac_sayisi<<endl;
}

void Ilac::ilac_duzenle(string eczn_isim)
{
    Ilac a;
    int id;
    ifstream file((eczn_isim +"_ilac" + ".dat").c_str());

    if(file)
    {

        cout<<"Bilgilerimi degistirmek istediginiz ilacin ID'sini giriniz: ";
        cin>>id;

        fstream file2;
        file2.open("temp.dat",ios::out | ios::in | ios::app);



        while(file>>a.ilac_id)
        {

        file>>a.ilac_isim;
        file>>a.ilac_fiyati;
        file>>a.ilac_sayisi;



            if(a.ilac_id!=id)
            {
                file2<<setw(15)<<a.ilac_id
                     <<setw(15)<<a.ilac_isim
                     <<setw(15)<<a.ilac_fiyati
                     <<setw(15)<<a.ilac_sayisi
                     <<endl;
            }
            else if(a.ilac_id==id){
            cout.setf(ios::left);
            cout<<setw(15)<<"\n\nYeni ilac ID giriniz : ";
            cin>>a.ilac_id;
            cout<<setw(15)<<"\nYeni ilac ismi giriniz: ";
            cin>>a.ilac_isim;
            cout<<setw(15)<<"\nYeni fiyat bilgisi giriniz : ";
            cin>>a.ilac_fiyati;
            cout<<setw(15)<<"\nYeni sayi bilgisi giriniz : ";
            cin>>a.ilac_sayisi;
            file2<<setw(15)<<a.ilac_id<<setw(15)<<a.ilac_isim<<setw(15)<<a.ilac_fiyati<<setw(15)<<a.ilac_sayisi<<endl;
            }

        }

        file.close();
        file2.close();
        remove((eczn_isim +"_ilac" + ".dat").c_str());
        rename("temp.dat",(eczn_isim  + "_ilac" + ".dat").c_str());

    }
    else
    {
        cout<<"Bu isimde bir eczane bulunamadý!"<<endl;
    }

}

void Ilac::ilac_ara(string ilac_adi)
{
    Eczane A;

    fstream file;
    fstream file2;
    int counter=0;
    int eczn_id=A.get_eczn_id();
    string eczn_isim=A.get_eczn_isim();
    string eczn_adres=A.get_eczn_adres();
    file.open("eczane_listesi.dat", ios::in);

    while(file>>eczn_id)
    {
       file>>eczn_isim;
       file>>eczn_adres;

       file2.open((eczn_isim +"_ilac" + ".dat").c_str(),  ios::in);

       while(file2>>ilac_id)
       {
        file2>>ilac_isim;
        file2>>ilac_fiyati;
        file2>>ilac_sayisi;

            if(ilac_isim.compare(ilac_adi)==0){
                cout<<"\nIlacin Bulundugu Eczane Bilgileri: "<<endl;
                cout<<"-------------------------------------"<<endl;
                cout<<setw(15)<<"\nEczane ID: " <<eczn_id
                    <<setw(15)<<"\nEczane Adi: "<<eczn_isim
                    <<setw(15)<<"\nEczane Adres: "<<eczn_adres<<endl;

                cout<<"\nAradiginiz Ilac Bilgileri: "<<endl;
                cout<<"---------------------------------"<<endl;
                ilac_goster();
                counter++;
            }

       }
       file2.close();
    }
    file.close();
    if(counter==0){
    cout<<"Girmis oldugunuz ilac hicbir eczanede bulunamamistir.\n"
    <<"Lutfen buyuk-kucuk harf uyumunu kontrol edip tekrar deneyiniz"<<endl;
    }
}

int main()
{
    system("CLS");
    int sifre = 123; // ****************ECZANE YONETICI GIRIS SIFRESI******************************
    int sifre2;
    int choice;
    int ecz_ID;


    cout<<"\nEczane Programina Hosgeldiniz"
        <<"\n-------------------------------------------"<<endl;
    flag:
    cout<<"\n1.Eczane Girisi"
        <<"\n2.Musteri Girisi"
        <<"\n3.Programi Sonlandir"
        <<"\n\nSecmek istediginizi giriniz: ";

    cin>>choice;


        if(choice==1)
        {
            system("CLS");
            flag2:
            cout<<"Yonetici menusune giris yapmak icin lutfen sifre giriniz: "<<endl;
            cin>>sifre2;

            if(sifre2==sifre)
            {
                cout<<"Giris islemi basarili. Yonetici menusune hosgeldiniz."<<endl;
                admin_menu();
            }
            else
            {
                cout<<"Yanlis sifre. Lutfen tekrar deneyiniz"<<endl;
                goto flag2;
            }


        }
        else if(choice==2)
        {
            customer_menu();
        }

        else if(choice==3)
        {
            exit(0);
        }
        else{
            cout<<"Boyle bir secenek bulunmamaktadir. Lutfen tekrar deneyiniz"<<endl;
            exit(1);
        }
}

void admin_menu()
{
    Eczane ecz;
    Ilac ilac;
    Eczane e;

    int eczane_sayi=0;
    int ilac_sayi=0;
    char ch = 'n';
    int choice;
    string eczane_ad;
    system("CLS");
    flag:
    cout<<"\n Yonetici Menusune Hosgeldiniz"
        <<"\n-------------------------------------------"<<endl;
    cout<<"\n1.Eczane Listesi Olustur"
        <<"\n2.Eczane Ekle"
        <<"\n3.Ilac Ekle"
        <<"\n4.Ilac Duzenle"
        <<"\n5.Ana Menu"
        <<"\n\nSecmek istediginizi giriniz: ";
    cin>>choice;

    fstream file;
    file.open("eczane_listesi.dat", ios::in | ios::out);

    if(choice==1)
    {
       if(file)
            {
                cout<<"Eczane dosyasi mevcut"<<endl;
                file.close();
            }

        else{
                file.close();
                file.open("eczane_listesi.dat", ios::out | ios::in | ios::app);
                cout<<"Dosya basariyla olusturuldu"<<endl;
        }

        goto flag;
    }

    else if(choice==2)
    {
        system("CLS");
        flag2:

        ecz.eczn_olustur();
        cout<<"Eczane dosyaya eklendi"<<endl;
        ecz.eczn_goster();

            cout<<"\n\nBaska eczane eklemek ister misiniz? (y/n) : ";
            ch = getche();

            if(ch=='y' || ch=='Y')
                goto flag2;
            else
                goto flag;




    }

    else if(choice==3)
    {
        system("CLS");
        flag3:

        eczaneleri_goster();
        cout<<"Ilac eklemek istediginiz eczane adini giriniz"<<endl;
        cin>>eczane_ad;
        ilac.ilac_olustur(eczane_ad);
        cout<<"Ilac dosyaya eklendi"<<endl;
        ilac.ilac_goster();

        cout<<"\n\n Baska ilac eklemek ister misiniz? (y/n) : ";
        ch = getche();

            if(ch=='y' || ch=='Y')
                goto flag3;
            else
                goto flag;
        }



    else if(choice==4)
    {
        system("CLS");
        eczaneleri_goster();
        cout<<"\nIlac listesinde degisiklik yapmak istediginiz eczaneyi giriniz: "<<endl;
        cin>>eczane_ad;
        ilac.ilac_listesi(eczane_ad);
        ilac.ilac_duzenle(eczane_ad);
        cout<<"Duzenleme islemi basarili"<<endl;
        cout<<"---------------------------------------"<<endl;
        ilac.ilac_listesi(eczane_ad);
        goto flag;
    }

    else if(choice==5)
    {
        main();
    }
    else{
        cout<<"Boyle bir secenek bulunmamaktadir. Lutfen tekrar deneyiniz"<<endl;
        goto flag;
    }
    file.close();
}

void customer_menu()
{
    int choice;
    char ch = 'n';
    Eczane e;
    Ilac ilc;
    string eczn_adi;
    string ilac_adi;

    system("CLS");
    flag:
        cout<<"\n Musteri Menusune Hosgeldniz"<<endl;
        cout<<"**********************************************"<<endl;
        cout<<"\n1.Ilac Ara"
        <<"\n2.Eczane Listele"
        <<"\n3.Herhangi Bir Eczaneyi Goster"
        <<"\n4.Herhangi Bir Eczaneye Ait Ilac Listesi"
        <<"\n5.Ana Menu"
        <<"\n\nSecmek istediginizi giriniz: ";
        cin>>choice;

        fstream file;

        if(choice==1)
        {

            system("cls");
            flag2:
            cout<<"\n\n Aramak istediginiz ilacin ismini yaziniz: ";
            cin>>ilac_adi;
            ilc.ilac_ara(ilac_adi);

            cout<<"\n\nBir daha ilac aramak ister misiniz? (y/n) : ";
            ch = getche();

            if(ch=='y' || ch=='Y')
                goto flag2;
            else
                goto flag;

        }

        else if(choice==2)
        {
            system("cls");
            eczaneleri_goster();
            cout<<"--------------------------------------------"<<endl;
            goto flag;
        }

        else if(choice==3)
        {
            flag3:
            cout<<"Aramak Istediginiz Eczane Adini Giriniz: ";
            cin>>eczn_adi;
            e.eczn_ara(eczn_adi);

            cout<<"\n\nBir daha eczane aramak ister misiniz? (y/n) : ";
            ch = getche();

            if(ch=='y' || ch=='Y')
                goto flag3;
            else
                goto flag;
        }
        else if(choice==4)
        {
            flag4:
            cout<<"\nIlac Listesine Bakmak Istedginiz Eczane Adini Giriniz: "<<endl;
            cin>>eczn_adi;
            ilc.ilac_listesi(eczn_adi);

            cout<<"\n\nBaska liste aramak ister misiniz? (y/n) : ";
            ch = getche();

            if(ch=='y' || ch=='Y')
                goto flag4;
            else
                goto flag;
        }
        else if(choice==5)
        {
            main();
        }
        else
        {
            cout<<"Boyle bir secenek bulunmamaktadir. Lutfen tekrar deneyiniz"<<endl;
            goto flag;
        }
}

