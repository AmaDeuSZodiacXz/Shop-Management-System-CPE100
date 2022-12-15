#include "updateProduct.h"
void updateProduct(int id, int qty) {
  FILE *fp, *fp1;
  struct Product t, t1;
  int found = 0;

  fp = fopen(file_product, "rb");
  fp1 = fopen("temp.dat", "wb");

  while (1) {
    fread(&t, sizeof(t), 1, fp);

    if (feof(fp)) {
      break;
    }
    if (t.ID == id) {
      found = 1;
      t.qty = qty;
      fwrite(&t, sizeof(t), 1, fp1);
    } else {
      fwrite(&t, sizeof(t), 1, fp1);
    }
  }
  fclose(fp);
  fclose(fp1);

  if (found == 0) {
    printf("Sorry No Record Found\n\n");
  } else {
    fp = fopen(file_product, "wb");
    fp1 = fopen("temp.dat", "rb");

    while (1) {
      fread(&t, sizeof(t), 1, fp1);

      if (feof(fp1)) {
        break;
      }
      fwrite(&t, sizeof(t), 1, fp);
    }
  }
  fclose(fp);
  fclose(fp1);
}
