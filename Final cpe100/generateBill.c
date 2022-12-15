#include "generateBill.h"
void generateBill() {
  total = 0;
  FILE *fp, *fp1;
  struct Bill t;
  int id, found = 0;
  char ch, date[20];
  system("cls");
  fflush(stdin);
  fp = fopen(file_bill, "rb");

  printf("==============================================================\n\n");
  printf("\t\t Sales Record \n\n");
  printf("==============================================================\n\n");

  printf("Date    \t\tPro-ID\tPro-Name\tPro-Quantity\tPro-Price\n\n");

  while (1) {
    fread(&t, sizeof(t), 1, fp);

    if (feof(fp) || fp == NULL) {
      break;
    }
    printf("%s_%s", t.P_Date, t.P_Time);
    printf("        %3d\t", t.PurchaseID);
    printf("%-10s\t", t.P_Name);
    printf("%8d\t", t.P_Quantity);
    printf("%7d\t\t\t\n", t.P_Price);
    total = total + t.P_Price;
  }
  if (total >= 0) {
    printf("\n\n==========>>>>> [Total : %d Baht] {Status: Profit}\n\n", total);
  } else {
    printf("\n\n==========>>>>> [Total : %d Baht] {Status: Loss}\n\n", total);
  }
  printf("Balance: %d\n\n", getBalance());
  printf("==============================================================\n\n");
  printf("1.Specific Day\n\n");
  printf("2.Specific Month\n\n");
  printf("3.Specific Year\n\n");
  printf("0.Back\n\n");
  printf("==============================================================\n\n");
  printf("Enter Your Choice:");
  scanf("%c", &ch);
  fclose(fp);

  if (ch == '0') {
    return;
  }
  if (ch == '1') {
    fflush(stdin);
    fp = fopen(file_bill, "rb");
    total = 0;
    printf("\n\nEnter Date/Month/Year:");
    scanf("%s", date);
    printf("Date    \t\tPro-ID\tPro-Name\tPro-Quantity\tPro-Price\n\n");
    while (1) {
      fread(&t, sizeof(t), 1, fp);

      if (feof(fp) || fp == NULL) {
        break;
      }
      if (strcmp(date, t.P_Date) == 0) {
        printf("%s_%s", t.P_Date, t.P_Time);
        printf("        %3d\t", t.PurchaseID);
        printf("%-10s\t", t.P_Name);
        printf("%8d\t", t.P_Quantity);
        printf("%7d\t\t\t\n", t.P_Price);
        total = total + t.P_Price;
      }
    }
    printf("\n->Total: %d Baht\n", total);
    fclose(fp);
  }
  if (ch == '2') {
    fflush(stdin);
    char temp[20];

    fp = fopen(file_bill, "rb");
    total = 0;
    printf("\n\nEnter Month/Year:");
    scanf("%s", date);
    printf("Date    \t\tPro-ID\tPro-Name\tPro-Quantity\tPro-Price\n\n");
    while (1) {
      fread(&t, sizeof(t), 1, fp);
      sprintf(temp, "%s/%s", t.P_Month, t.P_Year);
      if (feof(fp) || fp == NULL) {
        break;
      }
      if (strcmp(date, temp) == 0) {
        printf("%s_%s", t.P_Date, t.P_Time);
        printf("        %3d\t", t.PurchaseID);
        printf("%-10s\t", t.P_Name);
        printf("%8d\t", t.P_Quantity);
        printf("%7d\t\t\t\n", t.P_Price);
        total = total + t.P_Price;
      }
    }
    printf("\n->Total: %d Baht\n", total);
    fclose(fp);
  }
  if (ch == '3') {
    fflush(stdin);
    fp = fopen(file_bill, "rb");
    total = 0;
    printf("\n\nEnter Year:");
    scanf("%s", date);
    printf("Date    \t\tPro-ID\tPro-Name\tPro-Quantity\tPro-Price\n\n");
    while (1) {
      fread(&t, sizeof(t), 1, fp);
      if (feof(fp) || fp == NULL) {
        break;
      }
      if (strcmp(date, t.P_Year) == 0) {
        printf("%s_%s", t.P_Date, t.P_Time);
        printf("        %3d\t", t.PurchaseID);
        printf("%-10s\t", t.P_Name);
        printf("%8d\t", t.P_Quantity);
        printf("%7d\t\t\t\n", t.P_Price);
        total = total + t.P_Price;
      }
    }
    printf("\n->Total: %d Baht\n", total);
    fclose(fp);
  }

}
