#ifndef product_h_
#define product_h_

struct customer {
    int ID;
    char name[50];
    unsigned int type: 1;
    double x_coord;
    double y_coord;
    struct customer *next;
};
typedef struct customer CustomerNode;
typedef CustomerNode *CustomerPtr;

struct product {
    int ID;
    char name[50];
    unsigned int type : 4;
    double price;
    struct product *next;
};

typedef struct product ProductNode;
typedef ProductNode *ProductPtr;

struct purchased {
    int ID;
    int invoice_ID;
    int customer_ID;
    int product_ID;
    double cost;
    int quantity;
    double s_fee;
    struct Purchased *next;
};
typedef struct purchased PurchasedNode;
typedef PurchasedNode *PurchasedPtr;
void menu(void);
void set_CustomerInfo(CustomerNode *r, CustomerNode *customer_info);
void set_ProductInfo(ProductNode *r, ProductNode *product_info);

int CheckCustomerID(CustomerNode *r, int customer_id);
int CheckProductID(ProductNode *r, int product_id);
double CheckShippingFee(CustomerNode *r, int customer_id);
double CalculateCost(ProductNode *r, int product_id, int quantity);
void PurchasedStorage(PurchasedNode *r, int purchased_id, int invoice_id, int customer_id, int product_id, double cost,int quantity, double s_fee);

void print_AllCustomers(CustomerNode *r);
void CustomerTypeList(CustomerNode *r, unsigned int type);
void print_SingleCustomer(CustomerNode *r, int customer_id);

void print_AllProducts(ProductNode *r);
void ProductTypeList(ProductNode *r, unsigned int type);
void print_SingleProduct(ProductNode *r, int product_id);

void ListCustomerPurchased(PurchasedNode *r, ProductNode *z, int customer_id);
void ListACustomerTotal(PurchasedNode *r, int customer_id);

void AllCustomersTotal(PurchasedNode *r);
void TotalShippingFee(PurchasedNode *r);

void TotalPurchaseQuantity(PurchasedNode *r, int product_id);
void TotalPurchaseType(ProductNode *r,PurchasedNode *z, unsigned int product_type);
void print_AllCosts(PurchasedNode *r);


#endif // product_h_

