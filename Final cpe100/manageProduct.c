#include"manageProduct.h"
void manageProduct() {
  int choice;
  int back = 0;
  while (1) {
    system("cls");

    printf(
        "==============================================================\n\n");

    printf("\t\t Welcome to Shop Management System\n\n");

    printf(
        "==============================================================\n\n");

    printf("1. Add New Product\n\n");
    printf("2. Restock Available Product\n\n");
    printf("3. Display All Product\n\n");

    printf("0. Back\n\n");

    printf(
        "==============================================================\n\n");
    printf("Balance: %d\n", getBalance());
    printf("\nPlease enter your Choice:");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addProduct();
        break;

      case 2:
        restock();
        break;

      case 3:
        displayAllProduct();
        printf("\nPress Any Key to Exit>>");
        break;

      case 0:
        back = 1;
        break;
    }

    if (back == 1) {
      break;
    } else {
      getch();
    }
  }
}
