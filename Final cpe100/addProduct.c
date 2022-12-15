#include"addProduct.h"
void addProduct() {
  FILE *fp, *fp1;
  struct Bill t1;
  struct Product t2;

  fp = fopen(file_product, "ab");

  t2.ID = getID();

  printf("\nEnter product name:");
  scanf("%s", t2.name);
  printf("\nEnter product cost:");
  scanf("%d", &t2.cost);
  printf("\nEnter product price:");
  scanf("%d", &t2.price);
  printf("\nEnter product quantity:");
  scanf("%d", &t2.qty);

  // printf("\nTesting: %d\n",-1*t2.cost*t2.qty);
  insertBalance(-1 * t2.cost * t2.qty);

  fwrite(&t2, sizeof(t2), 1, fp);
  fclose(fp);

  fp1 = fopen(file_bill, "ab");

  t1.PurchaseID = t2.ID;
  strcpy(t1.P_Name, t2.name);
  t1.P_Quantity = t2.qty;
  t1.P_Price = -1 * t2.cost * t2.qty;

  strcpy(t1.P_Date, getDate());
  strcpy(t1.P_Time, getTime());
  strcpy(t1.P_Day, getDay());
  strcpy(t1.P_Month, getMonth());
  strcpy(t1.P_Year, getYear());

  fwrite(&t1, sizeof(t1), 1, fp1);

  fclose(fp1);
}
