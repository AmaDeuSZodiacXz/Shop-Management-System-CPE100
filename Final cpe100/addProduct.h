#ifndef addProduct_H_INCLUDED
#define addProduct_H_INCLUDED

#include <conio.h>   // C standard Console Input/Output library
#include <stdio.h>   // C standard IO library
#include <stdlib.h>  // standard library
#include <string.h>  // string manipulation utility
#include <time.h> 
struct Product {
  int ID;
  char name[50];
  int price;
  int qty;
  int cost;
};
// invoice information of a single purchase event
struct Bill {
  int PurchaseID;  // purchase ID

  // purchase information
  char P_Name[20];  // purchase name
  int P_Quantity;   // purchase quantity
  int P_Price;      // purchase price

  // time of purchase (just a redundant technique used to mention the purchases)
  char P_Year[20];   // purchase year
  char P_Month[20];  // purchase month
  char P_Day[20];    // purchase day
  char P_Date[20];   // purchase data
  char P_Time[20];   // purchase time
};
// this is where all the product information are stored
char file_product[] = {"product.dat"};

// this is where all the invoice are stored
char file_bill[] = {"bill.dat"};
void manageProduct();
void addProduct();
void restock();
void displayAllProduct();
struct Product findProduct(int);
void updateProduct(int, int);
char* getDate();
char* getTime();
char* getYear();
char* getMonth();
char* getDay();
int total = 0;
#endif // insertBalance_H_INCLUDED
