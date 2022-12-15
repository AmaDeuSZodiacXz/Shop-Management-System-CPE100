#include"purchaseProduct.h"
void purchaseProduct() {
  char ch1, ch2;
  int id, qty;
  system("cls");
  printf("==============================================================\n\n");

  printf("\t\t Welcome to Shop Management System\n\n");

  printf("==============================================================\n\n");

  while (1) {
    displayAllProduct();
    fflush(stdin);
    // Less Y/N uses 0 to exit instead;
    printf("\n\n\nEnter the Product ID to Purchase(0=Exit):");
    scanf("%d", &id);
    if (id == 0) {
      break;
    }
    FILE* fp;
    struct Bill t1;
    struct Product t2;

    fp = fopen(file_bill, "ab");
    t2 = findProduct(id);

    printf("\n\nEnter Product Quantity:");
    scanf("%d", &qty);

    // added to prevent negative count in stock
    if (t2.qty - qty < 0) {
      printf("\nSorry, Insufficient Product");
      fflush(stdin);
      getch();
      continue;
    }
    // remove desired product qty
    updateProduct(t2.ID, t2.qty - qty);
    insertBalance(t2.price * qty);

    t1.PurchaseID = t2.ID;
    strcpy(t1.P_Name, t2.name);
    t1.P_Quantity = qty;
    t1.P_Price = t2.price * qty;

    strcpy(t1.P_Time, getTime());
    strcpy(t1.P_Date, getDate());
    strcpy(t1.P_Day, getDay());
    strcpy(t1.P_Month, getMonth());
    strcpy(t1.P_Year, getYear());

    fwrite(&t1, sizeof(t1), 1, fp);

    fclose(fp);

    fflush(stdin);
    getch();
  }
}
