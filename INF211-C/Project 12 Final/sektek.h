#ifndef SEKTEK_H_
#define SEKTEK_H_
//extern int a;
//extern int main_exit;
//menu structs
struct
{
    char name[20];
    char surname[20];
    char username[20];
    char password[20];
    char mail[50];
    unsigned long long int pnumber;
    float deposit;
    float load;
}l,check,upd,lgn;
//cart structs
struct Cart{
	char product[30];
	float product_price;
	int product_count;
	char drink_choice[30];
	char drink_type[30];
	int drink_count;
	float drink_price;
	char pizza_choice[30];
	int pizza_choice_count;
};
	struct Cart cart[5] ={
		{"empty",0.0,0,"empty","empty",0,0.0,"empty",0},
		{"empty",0.0,0,"empty","empty",0,0.0,"empty",0},
		{"empty",0.0,0,"empty","empty",0,0.0,"empty",0},
		{"empty",0.0,0,"empty","empty",0,0.0,"empty",0},
		{"empty",0.0,0,"empty","empty",0,0.0,"empty",0}
	};

//data structs
struct menu{
	char menu[30];
	float menu_price;
	char extra1[30];
	char extra2[30];
	char extra3[30];
	char extra4[30];
};
struct pizza{
	char small[30];
	float small_price;
	char middle[30];
	float middle_price;
	char big[30];
	float big_price;
};
struct addon{
	char drink[30]; //cola
	float drink_price; //fiyat
	char addons[30];  //patates
	char addon_char[30]; //litre 2.5litre buyuk orta kucuk
	float addon_price_gap;
};

	struct sb_data_som{ //single or menu
		struct menu *menu;
		struct pizza *pizza;
		struct addon *addon;
	};
		struct menu menu[3]= {
		{"taraftar menu", 29.95, "kucuk boy pizza","tereyagli firin patates","kutu icecek", "bir kisilik menu" },
		{"algida menusu", 34.99, "orta boy pizza","iki adet nogger dondurma","bir litre icecek" },
		{"muhtesem uclu menu",34.99,"orta boy pizza","tereyagli firin patates","bir litre icecek"}
		};
		struct pizza pizza[5]= {
			{"sucuklu kucuk pizza", 21.5, "sucuklu orta boy pizza", 34.5, "sucuklu buyuk boy pizza",41.5},
			{"kucuk boy surpreme pizza", 27.5,"orta boy surpreme pizza", 34.5,"buyuk boy surpreme pizza",41.5},
			{"kucuk boy milano pizza", 27.5,"orta boy milano pizza",34.5,"buyuk boy milano pizza,",41.5},
			{"kucuk boy gennaro pizza", 27.5,"orta boy gennaro pizza",34.5,"buyuk boy gennaro pizza,",41.5},
			{"kucuk boy venedikli pizza", 24.5,"orta boy venedikli pizza",31.5,"buyuk boy gennaro pizza,",38.5}
		};
		struct addon addon[5]= {
			{"coco cola ",4.0,"baharat","kucuk boy",0.0},
			{"fanta",3.5,"firin patates","orta boy",5.50},
			{"sprite", 8.0,"zeytin","buyuk boy",0.0},
			{"nuko cola", 12.0,"kasar peyniri kenarlikli","2.5 litre", 5.50},
			{"fuse tea",2.5,"kekik","1 litre",0.0}
		};
//Menu functions
void welcome_menu(void);
void registration(void);
void login(void);
void user_menu(void);
int deposit_balance(void);
void account_remover(void);
void pastorders(void);
void edit_account(void);
void payment_methods(int ttl);
void fordelay(int j);
void loading();

//cart functions
int restaurant_pref(void);
int cart_generator(struct sb_data_som Som, struct Cart cart[5], int choice);
int cart_addons(struct sb_data_som Som, struct Cart cart[5], int purstyle);
int cart_displayer(struct sb_data_som Som, struct Cart cart[5], int purstyle);
		
		  

 #endif //SEKTEK_H_
