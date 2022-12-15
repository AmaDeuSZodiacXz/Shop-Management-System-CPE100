#include"Product_findProduct.h"
struct Product findProduct(int id) {
  FILE* fp;
  struct Product t;

  fp = fopen(file_product, "rb");

  while (1) {
    fread(&t, sizeof(t), 1, fp);

    if (feof(fp)) {
      printf("This Product Does Not Exist");
      break;
    }

    if (t.ID == id) {
      updateProduct(id, t.qty);  // change minus 1 when purchase to line 261
      break;
    }
  }
  fclose(fp);
  return t;
}
