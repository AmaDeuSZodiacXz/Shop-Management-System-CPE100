#include "getBalance.h"
int getBalance() {
  FILE* fp;
  int balance = 0;
  fp = fopen("balance.txt", "r");

  if (fp == NULL) {
    fp = fopen("balance.txt", "w");
    fprintf(fp, "%d", 10000);
    fclose(fp);
    fp = fopen("balance.txt", "r");
  }

  fscanf(fp, "%d", &balance);

  fclose(fp);

  fp = fopen("balance.txt", "w");

  fprintf(fp, "%d", balance);

  fclose(fp);

  return balance;
}
