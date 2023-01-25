#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "product.h"



int main()
{



    CustomerNode *CustomerPtr=(CustomerNode *)malloc(sizeof(CustomerNode));
	CustomerPtr->next = NULL;

	ProductNode *ProductPtr=(ProductNode *)malloc(sizeof(ProductNode));
	ProductPtr-> next = NULL;

	PurchasedNode *PurchasedPtr=(PurchasedNode *)malloc(sizeof(PurchasedNode));
	PurchasedPtr-> next = NULL;

	CustomerNode customer_info[5] =
    {
    {1, "Ali Karaman",  1, 16.8, 10},
    {2,	"Zehra Cilek",  0, 12.4, 6.9},
    {3,	"Mehmet Derin",	0, 10.55, 15.4},
    {4,	"Veli Ortanca",	1, 5.1,	1.2},
    {5,	"Menekse Serin",1,	2, 7.9}
    };

    ProductNode product_info[7] =
    {
    {1,"Portakal",1, 5.99},
    {2,"Muz",1, 12.95},
    {3,"Sogan",2, 7.45},
    {4,"Pirasa",2, 3.95},
    {5,"Lahana",2, 5.95},
    {6,"Limon",1, 7.45},
    {7,"Hamsi",3, 15}
    };


	set_CustomerInfo(CustomerPtr, customer_info);
	set_ProductInfo(ProductPtr, product_info);

    int choice,cho, invoice_id=1, customer_id,product_id,quantity, purchased_id=0, j;
    int cho1, cho2, cho3, cho4, cho5, cho6, cho7,cho8, cho9;
    unsigned int customer_type,product_type;
    double cost;
    double price, s_fee;

    menu();


    printf("\n Enter your choice: ");
    scanf("%d", &choice);

     while(choice!=6)
    {
    switch(choice){
        case 1:
            flag1:
            printf("\n\t\t\t-------- Preprocessing --------");
            printf("\nInvoice ID: %d", invoice_id);
            printf("\nEnter the Customer ID: ");
            scanf("%d", &customer_id);

            if(CheckCustomerID(CustomerPtr, customer_id) == 0){
                printf("\nID does not exist");
                goto flag1;
            }
            else{
                    j=0;
                    flag2:
                    printf("\n\t\t\t-------- Product Sale --------");
                    printf("\nEnter the Product Number: ");
                    scanf("%d", &product_id);

                    if(CheckProductID(ProductPtr, product_id) == 0){
                        printf("\nProduct ID does not exist");
                        goto flag2;
                    }
                    else{
                        s_fee=0;
                        cost=0;
                        purchased_id++;
                        printf("\nEnter the quantity: ");
                        scanf("%d", &quantity);

                        cost=CalculateCost(ProductPtr,product_id,quantity);
                        printf("%f",cost);

                        if(j==0){
                        flag4:
                        printf("\n\t\t-------- Invoice finalization -------");
                        printf("\nIs customer buying from the shop? \n1.YES\n2.NO \nEnter Your Choice: ");
                        scanf("%d", &cho1);
                        if(cho1==1)
                            printf("\nThere is no shipping fee");
                        else if(cho1==2){
                            printf("\nThe shipping fee has been added to the cost ");
                            s_fee = CheckShippingFee(CustomerPtr, customer_id);
                            printf("\n--- %f ---", s_fee);
                        }
                        j++;
                        }
                        else{
                        printf("\nInvalid Option!");
                        goto flag4;
                        }

                        PurchasedStorage(PurchasedPtr,purchased_id,invoice_id,customer_id,product_id,cost,quantity,s_fee);

                        flag5:
                        printf("\nWould you like to add product? \n1.YES\n2.NO \nEnter Your Choice: ");
                        scanf("%d", &cho2);
                        if(cho2==1){
                            goto flag2;}
                        else if(cho2==2){
                        printf("\nPurchase has ended.");
                        }
                        else{
                        printf("\nInvalid Option!");
                        goto flag5;
                        }
                        invoice_id++;
                    }
                }
            break;
        case 2:
            flag6:
            printf("\n\t\t---------- Customer Information ---------\n");
            printf("\n 1. All Customers"
                   "\n 2. According to the customer type"
                   "\n 3. Single Customer");
            printf("\n\n Enter your choice: ");
            scanf("%d", &cho3);
                if(cho3==1){
                    print_AllCustomers(CustomerPtr);
                }
                else if(cho3==2){
                    flag7:
                    printf("\n What type of users are displayed? ");
                    printf("\n\n 1.Personal Type"
                           "\n 2.Commercial Type");
                    printf("\n Enter your choice: ");
                    scanf("%d", &cho4);
                        if(cho4==1){
                            printf("\n Personal Type Customers have been listed below");
                            customer_type=0;
                            CustomerTypeList(CustomerPtr,customer_type);
                        }
                        else if(cho4==2){
                            printf("\n Commercial Type Customers have been listed below");
                            customer_type=1;
                            CustomerTypeList(CustomerPtr,customer_type);
                        }
                        else{
                            printf("Invalid input!");
                            goto flag7;
                        }
                }
                else if(cho3==3){
                    printf("\nEnter Customer's ID number: ");
                    scanf("%d", &customer_id);
                    print_SingleCustomer(CustomerPtr, customer_id);
                }
                else {
                    printf("Invalid input!");
                    goto flag6;
                }
            break;
        case 3:
            flag8:
            printf("\n\t\t---------- Product Information ---------\n");
            printf("\n 1. All Products"
                   "\n 2. According to the product type"
                   "\n 3. Single Product");
            printf("\n\n Enter your choice: ");
            scanf("%d", &cho5);
                if(cho5==1){
                    print_AllProducts(ProductPtr);
                }
                else if(cho5==2){
                    flag9:
                    printf("\n What type of products are displayed? ");
                    printf("\n\n 1.Fruit Type "
                           "\n 2.Vegetable Type "
                           "\n 3.Meat Type ");
                    printf("\n Enter your choice: ");
                    scanf("%d", &cho6);
                if(cho6==1){
                    printf("\n Fruit Type Products have been listed below");
                    product_type=1;
                    ProductTypeList(ProductPtr,product_type);
                }
                else if(cho6==2){
                    printf("\n Vegetable Type Products have been listed below");
                    product_type=2;
                    ProductTypeList(ProductPtr,product_type);
                }
                else if(cho6==3){
                    printf("\n Meat Type Products have been listed below");
                    product_type=3;
                    ProductTypeList(ProductPtr,product_type);
                }
                else{
                    printf("Invalid input!");
                    goto flag9;
                }
                }
                else if(cho5==3){
                    printf("\nEnter Product's ID number: ");
                    scanf("%d", &product_id);
                    print_SingleProduct(ProductPtr, product_id);
                }
                else {
                    printf("Invalid input!");
                    goto flag8;
                }
            break;
        case 4:
            flag10:
            printf("\n\t\t---------- Customer Analysis ---------\n");
            printf("\n 1. Products purchased by a customer"
                   "\n 2. Total amount of purchased by a customer"
                   "\n 3. Total amount of products purchased by all customer "
                   "\n 4. Customers shipping fee ");
            printf("\n\n Enter your choice: ");
            scanf("%d", &cho7);
                if(cho7==1)
                {
                    flag11:
                    printf("\nEnter Customer ID to display products purchased by a customer: ");
                    scanf("%d", &customer_id);

                    if(CheckCustomerID(CustomerPtr, customer_id) == 0){
                        printf("\nID does not exist! ");
                        goto flag11;
                    }
                    else{
                    ListCustomerPurchased(PurchasedPtr,ProductPtr,customer_id);
                    }
                }
                else if(cho7==2)
                {
                    flag12:
                    printf("\nEnter Customer ID to display products purchased by a customer: ");
                    scanf("%d", &customer_id);

                    if(CheckCustomerID(CustomerPtr, customer_id) == 0){
                        printf("\nCustomer ID does not exist!");
                        goto flag12;
                    }
                    else{
                        ListACustomerTotal(PurchasedPtr, customer_id);
                    }
                }
                else if(cho7==3)
                {
                    AllCustomersTotal(PurchasedPtr);
                }
                else if(cho7==4)
                {
                    TotalShippingFee(PurchasedPtr);
                }
                else{
                    printf("\nInvalid Input!");
                    goto flag10;
                }
            break;
        case 5:
            flag13:
            printf("\n\t\t---------- Product Analysis ---------\n");
             printf("\n 1. Total purchase quantity of a product "
                   "\n 2. Total purchase amount of a product type "
                   "\n 3. Total purchase amount for all products ");
            printf("\n\n Enter your choice: ");
            scanf("%d", &cho8);

            if(cho8==1)
            {   flag14:
                printf("Enter the Product ID: ");
                scanf("%d", &product_id);
                if(CheckProductID(ProductPtr, product_id) == 0){
                    printf("\nProduct ID does not exist!");
                    goto flag14;
                }
                else{
                    TotalPurchaseQuantity(PurchasedPtr, product_id);
                }
            }
            else if(cho8==2)
            {       flag15:
                    printf("\n What type of product's cost will be displayed? ");
                    printf("\n\n 1.Fruit Type "
                           "\n 2.Vegetable Type "
                           "\n 3.Meat Type ");
                    printf("\n Enter your choice: ");
                    scanf("%d", &cho9);
                    if(cho9==1)
                    {
                        product_type=1;
                        printf("\n Costs of Fruit Type Products have been listed below");
                        TotalPurchaseType(ProductPtr,PurchasedPtr,product_type);

                    }
                    else if(cho9==2)
                    {
                        product_type=2;
                        printf("\n Costs of Vegetable Type Products have been listed below");
                        TotalPurchaseType(ProductPtr,PurchasedPtr,product_type);
                    }
                    else if(cho9==3)
                    {
                        product_type=3;
                        printf("\n Costs of Meat Type Products have been listed below");
                        TotalPurchaseType(ProductPtr,PurchasedPtr,product_type);
                    }
                    else{
                        printf("\n Invalid Input!");
                        goto flag15;
                    }
            }
            else if(cho8==3)
            {
                print_AllCosts(PurchasedPtr);
            }
            else{
                printf("\nInvalid Input!");
                goto flag13;
            }

            break;
        default:
            printf("\nInvalid choice! \n");
            menu();
            break;
    } //end of switch

    menu();
    printf("\n Enter your choice: ");
	scanf("%d", &choice);
    } //end of while

    printf("\n Program has ended.");

}


