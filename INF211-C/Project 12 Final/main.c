#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "sektek.h"
int a;
int main_exit;
int main(){

	char str[256];
	int option;
	int ttl;

    welcome_menu();

    struct sb_data_som Som;
	Som.menu = menu;
	Som.pizza = pizza;
	Som.addon = addon;

	struct Cart cart[5];
	int choice, purstyle;//purchase style

	
    if(a==2)
    
	choice = restaurant_pref();
	system("cls");
	purstyle = cart_generator(Som,cart,choice);
	cart_addons(Som,cart,purstyle);
	ttl=cart_displayer(Som,cart,purstyle);
	payment_methods(ttl);
	
    }

	//cart_pricer(cart);

	return 0;

}
