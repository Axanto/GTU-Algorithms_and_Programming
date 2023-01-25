#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "sektek.h"

//menu functions
void welcome_menu(void)
{
    system("cls");
    int option;
    nvn:
    system("color 9");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t 1.Login");
    printf("\n\t 2.Register");
    printf("\n\t 3.Exit");
    printf("\n\n\n\t Enter your choice: ");
    scanf("%d", &option);

    getchar();           // catching newline.

    if(option==1)
    {
        system("CLS");
        login();
    }
    else if(option == 2)
        {
            system("CLS");
            registration();
        }
    else if(option==3)
    {
        system("cls");
        close();
    }

    else{
        system("cls");
        system("color 4");
        printf("\n\tPlease enter a valid number!\n");
        loading();
        system("cls");
        goto nvn;
    }
}//function end

void registration(void)
{
    char ch;
    char filename[20];
    char userfile[20];
    FILE *log;
    FILE *record;
	
    record = fopen("accounts.dat", "a+");

    if(record==NULL)
    {
        printf("Error!\n Failed to open file.");
        exit(EXIT_FAILURE);
    }

    system("cls");

    printf("\n***Now please choose a username and password for system login.***");
    printf("\n***Ensure the username is no more than 20 characters long***");
    printf("\n****Ensure your password is at least 8 characters long.***\n");
    printf("\n***Your e-mail address must not have been used before.***\n");


    printf("\nEnter your mail adress: ");
    scanf("%s", check.mail);


    user_name:
    printf("\nEnter Username: ");
    scanf("%s", check.username);
    sprintf(userfile, "%s.txt", check.username);
    log = fopen(userfile, "r");

    if(log!=NULL)
    {
        fclose(log);
        printf("Username already in use!");
        goto user_name;
    }

    password_again:
    printf("\nEnter Password: ");
    scanf("%s", check.password);

    if (strlen(check.password)<8){
        printf("Your password must be at least 8 characters long!");
            goto password_again;
        }

    strcpy(l.mail, check.mail);
    strcpy(l.username, check.username);
    strcpy(l.password, check.password);

    printf("\nEnter First Name: ");
    scanf("%s", l.name);
    printf("\nEnter Surname: ");
    scanf("%s", l.surname);
    printf("\nEnter your phone number: ");
    scanf("%llu", &l.pnumber);

    l.deposit=0;

    fprintf(record,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, l.surname, l.pnumber, l.deposit);

    fclose(record);
    record = fopen("accounts.dat","r+");
    log = fopen(userfile, "w+");
    while((ch =fgetc(record)) != EOF){

 		fputc(ch, log);
 	}

    rewind(log);
    fclose(record);
    remove("accounts.dat");
    fclose(log);

    printf("\nAccount Created Successfully!");

    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the login screen and 0 to exit: ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        welcome_menu();
    else if(main_exit==0)
        close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}//function end

void login(void)
{
    char userfile[20];
    int test;
    int size;
    try_again:
    system("color 9");
    printf("\n\tEnter Username: ");
    scanf("%s", check.username);
    printf("\n\tEnter Password: ");
    scanf("%s", check.password);

    FILE *log;
    sprintf(userfile, "%s.txt", check.username);
    log = fopen(userfile, "r+");

    if(log==NULL)
    {
        system("cls");
        system("color 4");
        printf("\n\tUser file does not exist\n ");
        goto add_invalid;
    }
       int c = fgetc(log);
       if (c==EOF){
            system("cls");
            system("color 4");
            printf("\n\tUser not found\n");
            loading();
            goto add_invalid;
        }
        else {
        ungetc(c, log);
        system("cls");
        goto password;
    }

    password:
    rewind(log);
    strcpy(lgn.username, check.username);
    while(fscanf(log,"%s %s %s %s %s %llu %f", l.mail, l.username, l.password, l.name, l.surname, &l.pnumber, &l.deposit)!=EOF){
    if(strcmp(l.password, check.password)==0)
    {
        system("cls");
        system("color 2");
        printf("\n\tSuccessful Login!\n\tWelcome\n"); //********** USER_MENU() FUNTION GELECEK***********
        test=1;
        a=1;
        user_menu();
    }
    else{
        system("cls");
        system("color 4");
        printf("\n\tWrong Password!");
        goto add_invalid;
    }
    }
	
    if(test==0){
    add_invalid:
    printf("\n\n\n\tEnter 1 to create account\n\tEnter 2 to try again\n\tEnter 0 to exit\n\n\t");
    scanf("%d", &main_exit);
    system("cls");

    if(main_exit==2){
        goto try_again;
    }
    else if(main_exit==1)
        registration();

    else if(main_exit==0)
            close();
    else{
        printf("\nInvalid!\a");
        goto add_invalid;
    }
    fclose(log);
}
}//function end

void user_menu()
{

    system("cls");
    system("color 1");
    int procedure;

    puts("\n\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE USER MENU!!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    menu:
    printf("\n\t\t Chose The Procedure Which You Want To Do \t\t\n");
    printf("\n\t\t 1:Display Deposit Balance \n\t\t 2:Display Past Orders \n\t\t 3:Edit User Information \n\t\t 4:Order menu\n\t\t 5:Remove Account\n\t\t 6:Logout\n\t");
    printf("\n\t\t Enter your choice: ");
    scanf("%d",&procedure);



    if(procedure<=1 && procedure>=5)
    {
        system("cls");
        system("color 4");
        puts("**************WRONG ENTRENCE*************");
        puts("****************TRY AGAIN****************");
        goto menu;
    }




    else if(procedure==1)
    {
        system("cls");
        system("color 2");

        puts("\n\n\n\n\t\t\t\t Redirecting ");
        loading();
        deposit_balance();

    }
    else if(procedure==2)
    {
        system("cls");
        system("color 2");
        puts("\n\n\n\n\t\t\t\t Redirecting ");
        loading();
        pastorders();

    }
    else if(procedure==3)
    {
        system("cls");
        system("color 2");
        puts("\n\n\n\n\t\t\t\t Redirecting ");
        loading();
        edit_account();
    }
    else if(procedure==6)
    {
      system("cls");
      system("color 9");
      puts("\n\n\n\n\t\t\t\t Logging Out ");
      loading();
      welcome_menu();
    }
    else if(procedure==4){
        a=2;
        system("cls");
    }
    else if(procedure==5)
    {
        system("cls");
        account_remover();
    }
}//function end

int deposit_balance()
{
    system("cls");
    system("color 1");
    char userfile[20];
    FILE *dpst, *zac;
    sprintf(userfile,"%s.txt",lgn.username);
    dpst=fopen(userfile,"a+");


    if(dpst==NULL)
    {
        system("color 4");
        printf("could not reach the deposit data\n");
        printf("returning to user menu ");
        loading();
        user_menu();

    }
    float pr;
    int c;
    int quantity;
    puts("\n\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO DEPOSIT MENU!!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    menu:
    system("color 1");
    printf("\n\t\t Please Chose Process \n");
    printf("\n\t\t 1:View Deposit\n\t\t 2:Load Deposit\n\t\t 3:Exit\n");
    scanf("%f",&pr);


    if(pr==1)
    {
        while(fscanf(dpst,"%s %s %s %s %s %llu %f", l.mail, l.username, l.password, l.mail, l.name, l.surname, &l.pnumber, &l.deposit)!=EOF)
    {

        if(l.deposit<0.0001)
        {
            system("cls");
            system("color 4");
            printf("\n\n\n\t\t\t You Have Not Loaded Deposit Yet!!!!!!\n");
            printf("\n\t\t\t Go Back To Menu Or Exit\n");
            puts("\n\t\t\t 1:Send me back\n");
            puts("\n\t\t\t 2:Exit\n");
            scanf("%d",&c);

            if(c==1)
            {
                system("cls");
                printf("redirecting ");
                loading();
                goto menu;
            }
            else if(c==2)
            {
                system("cls");
                loading();
                close();
            }
        }
        else
        {
            system("cls");
            system("color 2");
            printf("\n\n\t\t\tYou Have %.2f ST deposit\n",l.deposit);
            printf("\n\t\t Go Back To Menu Or Exit\n");
            puts("\n\t\t 1:Send me back\n");
            puts("\n\t\t 2:Exit\n");
            scanf("%d",&c);

            if(c==1)
            {
                system("cls");
                printf("redirecting ");
                loading();
                goto menu;
            }
            else if(c==2)
            {
                system("cls");
                loading();
                close();
            }
        }
    }
    }
    else if(pr==2)
    {
    while(fscanf(dpst,"%s %s %s %s %s %llu %f", l.mail, l.username, l.password, l.name, l.surname, &l.pnumber, &l.deposit)!=EOF){
        system("cls");
        system("color 1");

        try_again:
        printf("\n\n\n\t\t\t Enter the Value You Want To Deposit On Your Account\n");
        puts("\n\t\t\t You are able to deposit max 500 unit and min 10 unit...\n");
        scanf("%f", &upd.load);

        if(upd.load>500.0 || upd.load<10.0)
        {
            system("cls");
            system("color 4");
            printf("\n\n\n\n\t YOU CAN NOT DEPOSIT THIS QUANTITY!!!!\n");
            printf("\n\n\n\n\t TRY AGAIN\n");
            puts("redirecting...");
            loading();
            goto try_again;
        }

        else
        {
            system("color 2");
            l.deposit+=upd.load;
            zac =fopen(userfile,"w+");
            fprintf(zac,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, l.surname, l.pnumber, l.deposit);
            loading();
            printf("\n\n\t %f amount has been loaded successfully!", upd.load);


            //struct degisecek dosya update-dosya kapatma

            }
        }

    }
    fclose(dpst);
    fclose(zac);
    printf("\n\n\tReturning user menu\n\n");
    loading();
    user_menu();
} //function ends


void account_remover(void){
	
    char userfile[20];
    FILE *rmv;
    sprintf(userfile, "%s.txt", lgn.username);
    rmv = fopen(userfile, "w");

    if(rmv==NULL)
        printf("\n\t Error while deleting account");
    else
        printf("Acount has been deleted successfully");

    fclose(rmv);

    add_invalid:
    printf("\n\n\n\tEnter 1 to return user menu\n");
    scanf("%d", &main_exit);
    system("cls");

    if(main_exit==1){
        user_menu();
    }
    else{
        printf("\nInvalid!\a");
        goto add_invalid;
        }
    }//function end
    
void pastorders(void)
{
    system("cls");
    system("color 1");
    char userfile[20];
    FILE* pstord;
    sprintf(userfile,"%s.txt",lgn.username);
    pstord=fopen(userfile,"r+");

    if(pstord==NULL)
    {
     system("cls");
     system("color 4");
     printf("Could Not Reached The Past Orders!!!\n");
     printf("redirecting to the user menu");
     loading();
     user_menu();
    }

    printf("\n\n\n\t :::Your Past Orders::: \n");

    //dosyaadan yazdirma-dosya kapatma

}//function end

void edit_account(){

    char userfile[20];
    int choice;

    FILE *edit;
    sprintf(userfile, "%s.txt", lgn.username);
    edit = fopen(userfile, "r");


    if(edit==NULL){
        printf("\n\t Error while deleting account");
    }

    edit_again:

    printf("\n\t1.Mail Adress\n\t2.Password\n\t3.Name\n\t4.Surname\n\t5.Number");
    printf("\n\n\tChoose the information you want to edit: ");
    scanf("%d", &choice);

    while(fscanf(edit,"%s %s %s %s %s %llu %f", l.mail, l.username, l.password, l.name, l.surname, &l.pnumber, &l.deposit)!=EOF){
    if(choice==1){
        system("cls");
        printf("\n\t Enter the new mail adress: ");
        scanf("%s", upd.mail);
        freopen(userfile, "w", edit);
        fprintf(edit,"%s %s %s %s %s %llu %f\n", upd.mail, l.username, l.password, l.name, l.surname, l.pnumber, l.deposit);
        loading();
        printf("\n\n\tChanges saved!");
    }
    else if(choice==2){
        system("cls");
        printf("\n\t Enter the new password: ");
        scanf("%s", upd.password);
        freopen(userfile, "w", edit);
        fprintf(edit,"%s %s %s %s %s %llu %f\n", l.mail, l.username, upd.password, l.name, l.surname, l.pnumber, l.deposit);
        loading();
        printf("\n\n\tChanges saved!");
    }
    else if(choice==3){
        system("cls");
        printf("\n\t Enter the new name: ");
        scanf("%s", upd.name);
        freopen(userfile, "w+", edit);
        fprintf(edit,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, upd.name, l.surname, l.pnumber, l.deposit);
        loading();
        printf("\n\n\tChanges saved!");
    }
    else if(choice==4){
        system("cls");
        printf("\n\t Enter the new surname: ");
        scanf("%s", upd.surname);
        freopen(userfile, "w+", edit);
        fprintf(edit,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, upd.surname, l.pnumber, l.deposit);
        loading();
        printf("\n\n\tChanges saved!");
    }
    else if(choice==5){
        system("cls");
        printf("\n\t Enter the new number: ");
        scanf("%d", &upd.pnumber);
        freopen(userfile, "w+", edit);
        fprintf(edit,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, l.surname, upd.pnumber, l.deposit);
        loading();
        printf("\n\n\tChanges saved!");
    }
    else {
        fprintf(edit,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, l.surname, l.pnumber, l.deposit);
        goto edit_again;
    }

    fclose(edit);

    }

} //function end

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}//function end

void loading()
{
    int i;
    for(i=0;i<5;++i)
    {
        printf("* ");
        fordelay(100000000);
    }
}//function end

//Cart functions
int restaurant_pref(void){
	int sbq, macq; //sbarro mac donalds ve burger kingde teslim bekleyen kullanici sayisi
						// mac saatlik max uretim 90 sbarro saatlik max uretim 60
	sbq=55;
	macq=95; //normalde bu verileri terminal gönderecek ancak projemizde sadece bulut fonksiyonlarini yazýyoruz.
	int temp;

	prefer_menu:
	printf("\n\t---Resturant Preferation Menu---\n");
	printf("\n\t1. Mac Donals people in queue: %d\n", macq); //restoran secimi menusu
	printf("\n\t2. Sbarro people in queue: %d\n", sbq);
	printf("\n\t3. Back to main menu");
	printf("\n\n\tPlease choose resturant\n");
	scanf("%d", &temp);
	if(temp == 1 && macq < 90){
		printf("MacDonalds has chosen succesfully\n");
		return 1;
	}
	else if (temp == 2 && sbq < 60){
		printf("Sbarro has chosen succesfully \n");
		return 2;
	}
	else if(temp ==3){
	user_menu();
	}
	else{
    printf("Cannot be selected due to excessive density, please choose another restaurant");
	goto prefer_menu;}
}//function end

int cart_generator(struct sb_data_som Som, struct Cart cart[5], int choice){
	int temp;
	char r_name[30];
	if(choice == 1){
		char r_name[30] = "Macdonalds";
		printf("\n\n\tHello welcome to %s restaurant interface!\n",r_name);
	}
	else if(choice == 2){
		char r_name[30] = "Sbarro";
		printf("\n\n\tHello welcome to %s restaurant interface!\n",r_name);
	}
	//else{
	//	main menu
	//}
	printf("\n\n\tEnjoy the time, try our best offers\nall of your personal data keep guarded by turkey cybersecurity law\n ");

	cart_generation_menu:
		printf("\n\n\t=====Cart Generation Menu=====\n");
		printf("\n\n\tChoose the purchase format\n");
		printf("\n\n\t1.Menu and Special Offers\n");
		printf("\n\n\t2.Pizza(one by one)\n ");
		scanf("%d", &temp);
		switch(temp){
//------------------------------------------------------------------------//
			case 1://menusel purchase
			printf("\t===Menu Purchase===\n");
			printf("\tPizza     Price\n");
			int i,p,ch,k,count,p_choice, menu_counter;

			for(i=0;i<3;i++){//sistemde 3 menu var //burasi display yapacak
				printf("\t%d.=%s= =%2.1f=\n\t%s+%s+%s+%s\n",i+1, Som.menu[i].menu, Som.menu[i].menu_price,Som.menu[i].extra1,Som.menu[i].extra2,Som.menu[i].extra3,Som.menu[i].extra4);
			} //for i
			for(p=0;p<5;p++){//max 5 kere alim yapabilir // burasi sepet dolduracak
				printf("\tenter menu you want to purchase:");
				scanf("%d",&ch);
				ch =ch-1;
				if(ch>3){
					printf("\nplease enter logical menu number\n");}
				else{
					printf("you have chosen %s menu\n", Som.menu[ch].menu);
					strcpy(cart[p].product,Som.menu[ch].menu);
					cart[p].product_price = Som.menu[ch].menu_price;
					printf("how many menus you want is %s?\n",Som.menu[ch].menu);
					scanf("%d", &count);
					cart[p].product_count = count;
					menu_counter += count;
					//printf("%d",menu_counter);
				}//else end
				int brak;
				printf("would you like to have another purchase?\n1.No\n2.Yes\n");
				scanf("%d",&brak);
				if(brak == 1){ //for breaker
					printf("you have succesfully purchased %d menus!", menu_counter);
					break;}
				if(p==4){
					printf("you have 1 purchase remain\n");}
				}//for p
			break; //case 1 breaker
//------------------------------------------------------------------//Menusel Purchase sonu
			case 2://pizzasal purchase
			printf("\t===Pizza Purchase===\n");
			printf("\tPizza     Price\n");
			int r;
			printf("\twhat size pizza do you want?:");
			printf("\t1.Big Sizes\n\t2.Middle Sizes\n\t3.Small Sizes\n");
			scanf("%d", &r);
			for(i=0;i<3;i++){//sistemde 5 pizza listesi var bunlari display edecek
				switch(r){
					case 1:
						if(i==0){
						printf("\t==Big Sizes==\n");}
						printf("\t%d. =%s= _%1.f_\n",i+1, Som.pizza[i].big, Som.pizza[i].big_price);
						break;
					case 2:
						if(i==0){
						printf("\t==Midde Sizes==\n");}
						printf("\t%d. =%s= _%1.f_\n",i+1, Som.pizza[i].middle, Som.pizza[i].middle_price);
						break;
					case 3:
						if(i==0){
						printf("\t==Small Sizes==\n");}
						printf("\t%d. =%s= _%1.f_\n",i+1, Som.pizza[i].small, Som.pizza[i].small_price);
						break;
				}//switch case end
			} //for i
			int counter=0,p_count;
			for(p=0;p<5;p++){//5 alisveris hakki max //burasi sepeti dolduracak
			printf("which pizza do you want to purchase?:");
			scanf("%d",&ch);
			ch= ch-1;
			if(ch>3){
				printf("please enter logical number!\n");}
			else{
				switch(r){
					case 1:
						printf("you have chosen %s pizza\n", Som.pizza[ch].big);
						strcpy(cart[p].product,Som.pizza[ch].big);
						cart[p].product_price = Som.pizza[ch].big_price;
						printf("how many pizzas will be same with %s:", Som.pizza[ch].big);
						scanf("%d",&p_count);
						cart[p].product_count = p_count;
					break;
					case 2:
						printf("you have chosen %s pizza\n", Som.pizza[ch].middle);
						strcpy(cart[p].product,Som.pizza[ch].middle);
						cart[p].product_price = Som.pizza[ch].middle_price;
						printf("how many pizzas will be same with %s:", Som.pizza[ch].middle);
						scanf("%d", &p_count);
						cart[p].product_count = p_count;
					break;
					case 3:
						printf("you have chosen %s pizza\n", Som.pizza[ch].small);
						strcpy(cart[p].product,Som.pizza[ch].small);
						cart[p].product_price = Som.pizza[ch].small_price;
						printf("how many pizzas will be same with %s:", Som.pizza[ch].small);
						scanf("%d", &p_count);
						cart[p].product_count = p_count;
					break;
				}//switch case end
				counter += p_count;
			}//else end
				int brak;
				printf("would you like to have another purchase?\n1.No\n2.Yes\n");
				scanf("%d",&brak);
				if(brak == 1){ //for breaker
					printf("you have succesfully purchased %d pizzas!", counter);
					break;}
				if(p==4){
					printf("you have 1 purchase remain\n");}
			}//p for end
			break;//case 2 break
	}//switch case end
	//printf("\ndelibary");
	return temp;
	
}//function end

int cart_addons(struct sb_data_som Som, struct Cart cart[5], int purstyle){
	int i,r,k;
	int counter = 0, remain = 0, remain2=0;
	int j,dtc,dc,quantity; //drink_type choice,

	for(i=0;i<5;i++){//to initilaz counter in function
		if(cart[i].product_count>10){ //eger sayi girilmemisse 13141434 yaziyor bunu engellemek icin yaptim structla gelen seyi de bir daha
			break;}                                                             //counter parametresi ile göndermek istemedim
	counter += cart[i].product_count;}
	printf("%d",counter);
	printf("\nkey%dkey", purstyle);

	printf("\t==Addons Menu==\n");
	if(purstyle==1){ //menusel alim devami
	remain = counter;
	printf("\tYou have purchased %d menus you should choose %d middle sized pizzas",counter,counter);

	printf("\t==Midde Sizes==\n");
	for(k=0;k<5;k++){//displayer
		printf("\t%d. =%s=\n",k+1, Som.pizza[k].middle);}
	int pc,pq;
	for(i=0;i<counter;i++){//filler
			printf("you have %d pizza remains\n", remain);
			printf("enter what pizza you choose\n");
			scanf("%d", &pc);
			pc = pc-1;
			printf("you have chosen %s pizza how many pizza will be same",Som.pizza[pc].middle);
			scanf("%d", &pq);
			if(pq>remain){
				printf("please enter max %d",remain);
				scanf("%d", &pq);
					if(pq>remain){
						printf("!!!!are you joking!!!!\n Program will destroy itself eat nothing from now");
						return 0;}
			}//if end
			else{
				remain -= pq;
				strcpy(cart[i].pizza_choice,Som.pizza[pc].middle);
				cart[i].pizza_choice_count = pq;
				//no price equalizition we took that money already
				if(remain == 0){
					printf("all %d pizzas have chosen succesfully\n", counter);
					break;} //for breaker
			}//else end
		}//for i end

	}//purstyle if end
	//tekli alim devami  //hepsinin devami?  //drinkler ve opsiyonlar


	if(purstyle==1){//fazla sayi yaziyor
		remain2 = counter;
		printf("==Drinks==");
		for(j=0;j<5;j++){//displays
		printf("\t%d. %s\n",j+1,Som.addon[j].drink);}
		printf("your purchased %d menu you have 1liter free drink per menu",counter);
		for(r=0;r<counter;r++){//fills
			printf("please choose your drink\n");
			scanf("%d",&dc);
			dc = dc-1;
			printf("how many drinks will be same\n");
			scanf("%d", &quantity);
			strcpy(cart[r].drink_choice,Som.addon[dc].drink);
			strcpy(cart[r].drink_type,Som.addon[4].addon_char); //litre yazmasi icin
			cart[r].drink_count = quantity;

			if(quantity>remain2){
				printf("please enter max %d",remain2);
				scanf("%d", &quantity);}
			remain2 -= quantity;
			printf("you have %d drinks remain", remain2);
			if(remain2 == 0){
				break;
			}
		}//for end
	}//if end
	if(purstyle ==2){//tekli alim devami

	for(i=0;i<5;i++){
	printf("\t%d. %s\n",i+1, Som.addon[i].addon_char);}
	scanf("%d", &dtc);
	dtc = dtc-1;
	printf("\t==Drinks==\n");
	for(i=0;i<5;i++){
		printf("\t%d. %s %s %1.f\n",i+1, Som.addon[i].drink, Som.addon[dtc].addon_char,Som.addon[i].drink_price);
	}
	printf("What type drink do you want\n");
	for(i=0;i<5;i++){ //5 farkli secenek var max
		printf("please choose your drink\n");
		scanf("%d", &dc);
		dc = dc-1;
		printf("how many drinks will be the same\n");
		scanf("%d", &quantity);
		strcpy(cart[i].drink_choice,Som.addon[dc].drink);
		strcpy(cart[i].drink_type,Som.addon[dtc].addon_char);
		cart[i].drink_count = quantity;
		cart[i].drink_price = Som.addon[i].drink_price;   //check
		counter += quantity;
			int brak;
				printf("would you like to have another purchase?\n1.No\n2.Yes\n");
				scanf("%d",&brak);
				if(brak == 1){ //for breaker
					printf("you have succesfully purchased %d drinks!", counter);
					break;}
		}
	} //else end

	//printf("\ndelibary\n");
 }//function end
 
 int cart_displayer(struct sb_data_som Som, struct Cart cart[5], int purstyle){
 	char str_empty[30] = "----";
	int i;
 	float total;
	printf("\n\tList of Purchased\n");
 	if(purstyle ==1){

	for(i=0;i<5;i++){
	if(strcmp(cart[i].product,"empty")==0){
		break;}
	if(strcmp(cart[i].drink_choice,"")==0){
		strcpy(cart[i].drink_choice,str_empty);
	}
	printf("%s x %d = %f  -%s x %d\n", cart[i].product,cart[i].product_count , (cart[i].product_price * cart[i].product_count),cart[i].drink_choice,cart[i].drink_count);
	printf("\t%s x %d\n ", cart[i].pizza_choice,cart[i].pizza_choice_count);
	total += (cart[i].product_price * cart[i].product_count);
	}//for end
	printf("\tTotal:%1.f", total);
	return total;
}//if end
else{
	for(i=0;i<5;i++){
	if(strcmp(cart[i].product,"")==0){
		break;}
	printf("=%s x %d = %f= -%s %s x %d = %f\n", cart[i].product,cart[i].product_count , (cart[i].product_price * cart[i].product_count),cart[i].drink_choice,cart[i].drink_type,cart[i].drink_count,(cart[i].drink_count * cart[i].drink_price));
	//total += (cart[i].product_price * cart[i].pizza_choice_count + cart[i].drink_count * cart[i].drink_price);
	total += (cart[i].product_price * cart[i].product_count);
	total += (cart[i].drink_count * cart[i].drink_price);
}//for end
	printf("\tTotal:%1.f", total);
	return total;
}//else end
 }//function end

void payment_methods(int ttl)
{

    printf("\n\n\n\n");
    int chc, cash, change;
    char userfile[20];
    FILE *pymnt, *pymnt2;
    sprintf(userfile, "%s.txt", lgn.username);
    pymnt= fopen(userfile, "r");
    printf("\n\n\t Which way do you want to pay\n");
    printf("\n\n\t 1: Cash");
    printf("\n\n\t 2: Wallet");
    printf("\n\n\tEnter your choice: ");
    scanf("%d",&chc);

    switch(chc){
    case 1:
        again:
        while(fscanf(pymnt,"%s %s %s %s %s %llu %f", l.mail, l.username, l.password, l.name, l.surname, &l.pnumber, &l.deposit)!=EOF){
        system("cls");
        printf("\n\n\tMoney must be greater than the total amount!");
        printf("\n\n\tPlease enter the cash: ");
        scanf("%d", &cash);
            if(cash<ttl){
                printf("\n\n\tPlease deposit a larger amount!");
                goto again;
                }
            else if (cash==ttl){
                printf("\n\n\tThere is no change, thanks for yout purchase! ");
                }
            else if (cash>ttl){
                change=cash-ttl;
                l.deposit+=change;
                pymnt2=fopen(userfile, "w+");
                fprintf(pymnt2,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, l.surname, l.pnumber, l.deposit);
                printf("\n\n\tChange have been transferred to the wallet, thanks for your purchase! \n\n");
                    }
                    fclose(pymnt);
                    fclose(pymnt2);
                    }
            break;
    case 2:
        while(fscanf(pymnt,"%s %s %s %s %s %llu %f", l.mail, l.username, l.password, l.name, l.surname, &l.pnumber, &l.deposit)!=EOF){
        system("cls");
        if(l.deposit>=ttl)
        {
            l.deposit-=ttl;
            pymnt2=fopen(userfile, "w+");
            fprintf(pymnt2,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, l.surname, l.pnumber, l.deposit);
            printf("\n\n\tThe transaction was completed successfully\n\tRemaining money in your wallet = %f \n\n", l.deposit);

        }
        else if(l.deposit<ttl){
            dpst:
            printf("\n\n\tThere is not enough money in your waller\n\tYou should deposit to pay");
            printf("\n\n\tHow much do you want to deposit: ");
            scanf("%f", &cash);

            l.deposit+=cash;
            pymnt2 =fopen(userfile,"w+");
            fprintf(pymnt2,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, l.name, l.surname, l.pnumber, l.deposit);
            loading();
            system("cls");
            printf("\n\n\t %f amount has been loaded successfully!", cash);

            if(l.deposit<ttl){
                goto dpst;}
            else{
            l.deposit-=ttl;
            pymnt2=fopen(userfile, "w+");
            fprintf(pymnt2,"%s %s %s %s %s %llu %f\n", l.mail, l.username, l.password, upd.name, l.surname, l.pnumber, l.deposit);
            printf("\n\n\tThe transaction was completed successfully\n\tRemaining money in your wallet = %f \n\n", l.deposit);
            }
        }
    }
    fclose(pymnt);
    fclose(pymnt2);
    break;

    default:
        printf("Error! number is not correct");
    }
}



