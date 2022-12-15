// Online Inventory Management System
// CPE100 - Computer Programming

#include <conio.h>   // C standard Console Input/Output library
#include <stdio.h>   // C standard IO library
#include <stdlib.h>  // standard library
#include <string.h>  // string manipulation utility
#include <time.h>    // time utilities (UNIX time)
#include "insertBalance.c"
#include "getBalance.c"
#include "getID.c"
#include "manageProduct.c"
#include "addProduct.c"
#include "restock.c"
#include "displayAllProduct.c"
#include "purchaseProduct.c"
#include "Product_findProduct.c"
#include "updateProduct.c"
#include "generateBill.c"
#include "getDate.c"
#include "getDay.c"
#include "getMonth.c"
#include "getYear.c"
#include "getTime.c"
int getID();
// int billFileNo();
int getBalance();
int insertBalance(int value);
// product management functions
void manageProduct();
void addProduct();
void restock();
void displayAllProduct();
void updateProduct(int id, int qty);

// purchase related functions
void purchaseProduct();
void generateBill();

int main() {
  FILE* fp;  // file pointer
  int choice;

  // this clear screen is for UNIX-like system (Linux, macOS)
  system("clear");

  while (1) {
    // clear screen (cls command is for command promt type windows)
    system("cls");

    printf(
        "==============================================================\n\n");

    printf("\t\t Welcome to Shop Management System\n\n");

    printf(
        "==============================================================\n\n");

    printf("1. Manage Product\n\n");
    printf("2. Purchase Product\n\n");

    printf("3. Sales Record\n\n");

    printf("0. Exit\n\n");

    printf(
        "==============================================================\n\n");
    printf("Balance: %d\n", getBalance());
    printf("\nPlease enter your Choice:");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        manageProduct();
        break;

      case 2:
        purchaseProduct();
        break;

      case 3:
        generateBill();
        break;

      case 0:
        exit(0);
    }

    getch();
  }

  return 0;
}
