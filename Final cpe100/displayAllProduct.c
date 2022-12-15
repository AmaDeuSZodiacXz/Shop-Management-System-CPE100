#include"displayAllProduct.h"
void displayAllProduct() {
  FILE* fp;
  struct Product t;
  int id, found = 0;

  system("cls");

  fp = fopen(file_product, "rb");

  printf("==============================================================\n\n");
  printf("\t\t Product Details \n\n");
  printf("==============================================================\n\n");

  printf("   ID\tName\t\t Cost\tQuantity\tPrice\n\n");

  while (1) {
    fread(&t, sizeof(t), 1, fp);

    if (feof(fp) || fp == NULL) {
      break;
    }

    printf("  %3d\t", t.ID);
    printf("%-15s\t", t.name);
    printf("%5d\t", t.cost);
    printf("%7d\t", t.qty);
    printf("%13d\n", t.price);
  }
  printf("==============================================================\n\n");
  printf("Balance: %d\n", getBalance());
  fclose(fp);
}
