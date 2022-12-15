#include "getID.h"
int getID() {
  FILE* fp;
  int value = 0;

  fp = fopen("prodid.txt", "r");

  if (fp == NULL) {
    fp = fopen("prodid.txt", "w");
    fprintf(fp, "%d", 0);
    fclose(fp);
    fp = fopen("prodid.txt", "r");
  }

  fscanf(fp, "%d", &value);

  fclose(fp);

  fp = fopen("prodid.txt", "w");

  fprintf(fp, "%d", value + 1);

  fclose(fp);

  return value + 1;
}
