#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "product.h"

void menu(void){

    puts("\n"
	" 1.Sales \n"
	" 2.Customer Information \n"
	" 3.Product Information \n"
	" 4.Customer Analysis \n"
	" 5.Product Analysis \n"
	" 6.Close \n"
	);

}

void set_CustomerInfo(CustomerNode *r, CustomerNode *customer_info){

    int i=1;

    r->ID=customer_info[0].ID;
    strcpy(r->name,customer_info[0].name);
    r->type=customer_info[0].type;
    r->x_coord=customer_info[0].x_coord;
    r->y_coord=customer_info[0].y_coord;

        CustomerNode *temp = (CustomerNode *)malloc(sizeof(CustomerNode));

        CustomerNode *ptr;
        CustomerNode *mptr;


        mptr=temp;
        ptr=temp;


        while(i<5)

        {
            temp->ID=customer_info[i].ID;
            strcpy(temp->name,customer_info[i].name);
            temp->type=customer_info[i].type;
            temp->x_coord=customer_info[i].x_coord;
            temp->y_coord=customer_info[i].y_coord;

            temp=malloc(sizeof(CustomerNode));

            ptr->next = temp;
            ptr=ptr->next;
            i++;
        }
        ptr->next = NULL;

        r->next = mptr;

}






void set_ProductInfo(ProductNode *r, ProductNode *product_info){

    int i=1;

    r->ID=product_info[0].ID;
    strcpy(r->name,product_info[0].name);
    r->type=product_info[0].type;
    r->price=product_info[0].price;


        ProductNode *temp = (ProductNode *)malloc(sizeof(ProductNode));

        ProductNode *ptr;
        ProductNode *mptr;

        mptr=temp;
        ptr=temp;


        while(i<7)
        {
            temp->ID=product_info[i].ID;
            strcpy(temp->name,product_info[i].name);
            temp->type=product_info[i].type;
            temp->price=product_info[i].price;
            temp->next=NULL;
            temp=malloc(sizeof(ProductNode));
            ptr->next = temp;
            ptr=ptr->next;
            i++;
        }

        ptr->next = NULL;

        r->next = mptr;

}




void print_invoice(PurchasedNode *r, int invoice_id){


    PurchasedNode *NewNode=(PurchasedNode *)malloc(sizeof(PurchasedNode));
    NewNode->invoice_ID = invoice_id;
    NewNode->next = NULL;

    if(r == NULL)
         r = NewNode;
    else{

    PurchasedNode *LastNode = r;


    while(LastNode->next != NULL){
        LastNode = LastNode->next;
    }
    LastNode->next = NewNode;
    printf("\nInvoice ID = %d", NewNode->invoice_ID);
    }

}

int CheckCustomerID(CustomerNode *r, int customer_id){

    CustomerNode *temp = r;
    CustomerNode *temp2 = r;

    while(temp != NULL){

    if(temp->ID == customer_id)
    return 1;
    temp = temp->next;
    }

    return 0;
}



int CheckProductID(ProductNode *r, int product_id){

    ProductNode *temp = r;

    while(temp != NULL){

    if(temp->ID == product_id)
    return 1;

    temp = temp->next;
    }

    return 0;
}

double CheckShippingFee(CustomerNode *r, int customer_id)
{
    CustomerNode *temp = r;

    while(temp->next !=NULL)
    {
        if(temp->ID==customer_id)
        {
            if(temp->x_coord * temp->y_coord <= 50) //i pretend like source is on (0,0)
                return 9.90;
            else if(temp->x_coord * temp->y_coord <= 100)
                return 15.00;
            else if(temp->x_coord *temp->y_coord <= 200)
                return 19.90;
            else
                printf("\nThe shop cannot service there");

        }
        temp = temp->next;
    }
}

double CalculateCost(ProductNode *r, int product_id, int quantity)
{
    ProductNode *temp = r;

    double cost;

    while(temp->next != NULL){

        if(temp->ID==product_id)
    {

      cost = temp->price * quantity;
    }
    temp = temp->next;
    }
    return cost;
}


void PurchasedStorage(PurchasedNode *r, int purchased_id, int invoice_id, int customer_id, int product_id, double cost, int quantity, double s_fee)
{

    //create a new node
    PurchasedNode *newNode = (PurchasedNode *)malloc(sizeof(PurchasedNode));
    newNode->ID = purchased_id;
    newNode->invoice_ID = invoice_id;
    newNode->customer_ID = customer_id;
    newNode->product_ID = product_id;
    newNode->cost = cost;
    newNode->quantity = quantity;
    newNode->s_fee = s_fee;
    newNode->next = NULL;

    //if head is NULL, it is an empty list

    //Otherwise, find the last node and add the newNode

        PurchasedNode *lastNode = r;


        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
}



void print_AllCustomers(CustomerNode *r){

    CustomerNode *temp = r;

    while(temp->next!=NULL)
    {
        printf("\n\n\t -Customer ID-    -Customer Name-    -Customer Type-    -Customer X Coor.-    -Customer Y Coor.-");
        printf("\n\t\t%d\t      %s\t    %d\t\t    %f\t\t    %f ",temp->ID, temp->name, temp->type, temp->x_coord, temp->y_coord);
        temp = temp->next;
    }
}

void CustomerTypeList(CustomerNode *r, unsigned int type){

    CustomerNode *temp = r;

    while(temp->next != NULL){

        if(temp->type==type){
        printf("\n\n\t -Customer ID-    -Customer Name-    -Customer Type-    -Customer X Coor.-    -Customer Y Coor.-");
        printf("\n\t\t%d\t      %s\t   %d\t\t    %f\t\t    %f ",temp->ID, temp->name, temp->type, temp->x_coord, temp->y_coord);
        }
        temp = temp->next;

    }

}

void print_SingleCustomer(CustomerNode *r, int customer_id){

    CustomerNode *temp = r;

    while(temp->next != NULL){
        if(temp->ID==customer_id)
        break;
    temp=temp->next;
    }
    printf("\n\n\t -Customer ID-    -Customer Name-    -Customer Type-    -Customer X Coor.-    -Customer Y Coor.-");
    printf("\n\t\t%d\t    %s\t    %d\t\t     %f\t\t   %f ",temp->ID, temp->name, temp->type, temp->x_coord, temp->y_coord);
}

void print_AllProducts(ProductNode *r)
{
    ProductNode *temp = r;

    while(temp->next!=NULL)
    {
        printf("\n\n\t -Product ID-\t -Product Name-\t -Product Type-\t -Product Price-  ");
        printf("\n\t      %d\t\t   %s\t\t%u\t\t%.2f\t\t  ",temp->ID, temp->name, temp->type, temp->price);
        temp = temp->next;
    }
}


void ProductTypeList(ProductNode *r, unsigned int type)
{
    ProductNode *temp = r;

    while(temp->next != NULL){

        if(temp->type==type){
        printf("\n\n\t -Product ID-\t -Product Name-\t -Product Type-\t -Product Price-");
        printf("\n\t   %d\t\t    %s\t\t%u\t\t%f\t\t",temp->ID, temp->name, temp->type, temp->price);
        }
        temp = temp->next;

    }
}


void print_SingleProduct(ProductNode *r, int product_id)
{
    ProductNode *temp = r;

    while(temp->next != NULL){
        if(temp->ID==product_id)
        break;
    temp=temp->next;
    }
    printf("\n\n\t -Product ID-      -Product Name-      -Product Type-      -Product Price-");
    printf("\n\t      %d \t\t%s \t\t     %u \t\t\t%f ",temp->ID, temp->name, temp->type, temp->price);
}

void ListCustomerPurchased(PurchasedNode *r, ProductNode *z, int customer_id)
{
    int counter[101] = {0}, x=0,i, maximum = 0, minimum=0,t=1;


    PurchasedNode *temp = r;
    ProductNode *temp2 = z;


    while(temp != NULL){
        if(temp->customer_ID==customer_id)
        {
        x=temp->product_ID;
        counter[x] += temp->quantity;
        printf("\n\n\t -Customer ID-\t -Invoice ID-\t-Purchased ID-\t -Product ID-\t -Quantity-\t -Cost-");
        printf("\n%d.          %d\t             %d\t\t        %d\t      %d\t\t     %d\t\t   %.2f",t,temp->customer_ID, temp->invoice_ID, temp->ID, temp->product_ID, temp->quantity, temp->cost);
        t++;
        }
        temp=temp->next;
    }

    maximum = counter[0];
    minimum = counter[0];
    int index = 0;
    int index2 = 0;
    for (i = 0; i < 101; i++) {
        if (counter[i] >= maximum) {
        index = i;
        maximum = counter[i];
        }
        if(counter[i] <=minimum){
        index2 = i;
        minimum = counter[i];
        }
    }
    while(temp2 != NULL)
    {
        if(index==temp2->ID){
    printf("\n The most preferred product by the user number %d was %s, which was purchased %d times. \n", customer_id, temp2->name, maximum);
    }
        if(index2==temp2->ID){
    printf("\n The less preffered product by the user number %d was %s, which was purchased %d times. \n", customer_id, temp2->name, minimum);
    }
    temp2=temp2->next;
    }
}

void ListACustomerTotal(PurchasedNode *r, int customer_id)
{
    PurchasedNode *temp = r;
    PurchasedNode *temp2 = r;
    double total=0;
    int i,n=0;
    int maximum=0, minimum=0;
    int temp3;
    double arr[n];

    while(temp != NULL){
        if(temp->customer_ID == customer_id){
        printf("\n\n\tCustomer ID: %d\n ", customer_id);
        printf("\n---------------------------------");
        printf("\n\t-Product ID- \t\t -Quantity- \t\t -Cost-");
        printf("\n\t %d \t\t\t     %d \t\t\t  %f", temp->product_ID, temp->quantity, temp->cost );
        total+= temp->cost;
        printf("\n----------------------------------");
        printf("\n\t TOTAL: %f", total);
        }
        temp=temp->next;
    }

    while(temp2!=NULL)
    {
        if(temp2->customer_ID==customer_id){
            temp3=temp2->invoice_ID;
            arr[n]=temp2->cost;

            if(temp3 != temp2->invoice_ID)
            arr[n+1]=temp2->cost;

            n++;
        }
        temp2=temp2->next;
    }

    maximum=arr[0];
    minimum=arr[0];
    for(i=0; i<=n; i++)
    {
        if(arr[i]>maximum)
            maximum=arr[i];

        if(arr[i]<minimum)
            minimum=arr[i];
    }

    printf("The maximum invoice amount: %f\nThe minimum invoice amount: %f", maximum, minimum);
}

void AllCustomersTotal(PurchasedNode *r)
{
    PurchasedNode *temp = r;
    double total=0;

    while(temp->next!=NULL)
    {
        printf("\n\t -Customer ID-   -Product ID-   -Quantity-    -Cost-");
        printf("\n\t      %d             %d               %d            %f", temp->customer_ID, temp->product_ID, temp->quantity, temp->cost );
        total = total + temp->cost;
        temp=temp->next;
    }
    printf("\n----------------------------------");
    printf("\n\t TOTAL: %f", total);
}

void TotalShippingFee(PurchasedNode *r)
{
    PurchasedNode *temp = r;
    double total=0;

    while(temp!=NULL)
    {
        printf("\n\t -Invoice ID-   -Shipping Fee-");
        printf("\n\t      %d                %f", temp->invoice_ID, temp->s_fee);
        total = total + temp->s_fee;
        temp=temp->next;
    }
     printf("\n----------------------------------");
        printf("\n\t TOTAL: %f", total);
}

void TotalPurchaseQuantity(PurchasedNode *r, int product_id)
{
    PurchasedNode *temp = r;
    int total=0;
    double total2=0;
    while(temp!=NULL)
    {
        if(temp->product_ID==product_id){
        printf("\n\t -Product ID-    -Quantity-   -Cost- ");
        printf("\n\t      %d              %d       %f", temp->product_ID, temp->quantity, temp->cost);
        total += temp->quantity;
        total2 += temp->cost;
        }
    temp = temp->next;
    }
    printf("\n----------------------------------");
    printf("\n\t TOTAL: %d", total);
    printf("\n\t TOTAL: %f\n", total2);
}

void TotalPurchaseType(ProductNode *r,PurchasedNode *z, unsigned int product_type)
{
    ProductNode *temp = r;
    PurchasedNode *temp2 = z;
    double total = 0;

    while(temp != NULL)
    {
        if(temp->type==product_type)
        {
            while(temp2 != NULL)
            {
                if(temp->ID==temp2->product_ID)
                {
                    printf("\n\t -Product ID-    -Product Type-    -Quantity-    -Cost-");
                    printf("\n\t      %d               %u              %d           %f", temp->ID, temp->type, temp2->quantity, temp2->cost);
                    total += temp2->cost;

        }
            temp2 = temp2->next;
            }
        }
    temp = temp->next;
    }
    printf("\n----------------------------------");
    printf("\n\t TOTAL: %f\n", total);
}


void print_AllCosts(PurchasedNode *r)
{
    PurchasedNode *temp = r;
    double total=0;

    while(temp != NULL)
    {
        printf("\n\t -Purchased ID-   -Product ID-   -Quantity-   -Cost-");
        printf("\n\t    %d               %d            %d          %f", temp->ID, temp->product_ID, temp->quantity, temp->cost );
        total+= temp->cost;

        temp=temp->next;
    }

    printf("\n----------------------------------");
    printf("\n\t TOTAL: %f\n", total);
}

