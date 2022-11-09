#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct link {
  int coeff;
  int pow;
} my_poly;

void create(my_poly *poly, int len, int i) {

  printf("Enter the elements\n");

  for (i = 0; i < len; i++) {
    printf("Enter the coefficient:");
    scanf("%d", &poly[i].coeff);

    printf("Enter the power:");
    scanf("%d", &poly[i].pow);
  }
}

void evaluate(my_poly *poly, int len, int x, int i, int j) {

  int eval;
  for (i = 0; i < len; i++) {
    eval += poly[i].coeff * pow(x, poly[i].pow);
  }

  printf("The evaluated value is:\n");
  printf("%d\n", eval);
}

void display(my_poly *poly, int len, int i, int j) {
  for (i = 0; i < len; i++) {
    printf(" %dx^%d ", poly[i].coeff, poly[i].pow);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {

  int len, i, j;
  int x;
  printf("Enter the length of the polynomial:\n");
  scanf("%d", &len);
  my_poly poly[len];
  create(poly, len, i);

  printf("The polynomial is:\n");
  display(poly, len, i, j);

  printf("Enter the value to evaluate the polynomial:\n");
  scanf("%d", &x);

  evaluate(poly, len, x, i, j);

  return 0;
}
