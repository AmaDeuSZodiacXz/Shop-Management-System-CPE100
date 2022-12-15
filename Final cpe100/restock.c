#include"restock.h"
void restock()  // new function
{
  int id, qty;
  system("cls");
  printf("==============================================================\n\n");

  printf("\t\t Welcome to Shop Management System\n\n");

  printf("==============================================================\n\n");

  while (1) {
    FILE* fp;
    struct Bill t1;
    struct Product t2;

    displayAllProduct();
    fflush(stdin);
    // Less Y/N uses 0 to exit instead
    printf("\n\n\nEnter Product ID to Restock(0=Exit):");
    scanf("%d", &id);
    if (id == 0) {
      break;
    }
    fp = fopen(file_product, "ab");
    fp = fopen(file_bill, "ab");

    t2 = findProduct(id);
    // restock in 1 go
    printf("\n\nEnter Product Quantity:");
    scanf("%d", &qty);
    if (t2.qty + qty < 0) {
      printf("\n!!Invalid Quantity!!");
      getch();
      continue;
    }
    insertBalance(-1 * t2.cost * qty);
    updateProduct(t2.ID, t2.qty + qty);

    t1.PurchaseID = t2.ID;
    strcpy(t1.P_Name, t2.name);
    t1.P_Quantity = qty;
    t1.P_Price = -1 * t2.cost * qty;

    strcpy(t1.P_Time, getTime());
    strcpy(t1.P_Date, getDate());
    strcpy(t1.P_Day, getDay());
    strcpy(t1.P_Month, getMonth());
    strcpy(t1.P_Year, getYear());

    fwrite(&t1, sizeof(t1), 1, fp);

    fflush(stdin);
    // getch();
    fclose(fp);
  }
}
