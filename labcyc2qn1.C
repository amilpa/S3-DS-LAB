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

void display(my_poly *poly, int len, int i, int j) {
  for (i = 0; i < len; i++) {
    printf(" %dx^%d ", poly[i].coeff, poly[i].pow);
  }
  printf("\n");
}

int add(my_poly *sum, my_poly *poly1, my_poly *poly2, int len1, int len2, int i,
        int j, int sumlen) {
  int sumco = 0;
  int x = 0;
  int y = 0;
  int k = 0;

  while (x < len1 && y < len2) {
    if (poly1[x].pow == poly2[y].pow) {
      sum[k].coeff = poly1[x].coeff + poly2[y].coeff;
      sum[k].pow = poly1[x].pow;
      x++;
      y++;
      k++;
    }

    else if (poly1[x].pow > poly2[y].pow) {

      sum[k].coeff = poly1[x].coeff;
      sum[k].pow = poly1[x].pow;
      x++;
      k++;
    }

    else if (poly2[y].pow > poly1[x].pow) {

      sum[k].coeff = poly2[y].coeff;
      sum[k].pow = poly2[y].pow;
      y++;
      k++;
    }
  }

  while (x < len1) {

    sum[k].coeff = poly1[x].coeff;
    sum[k].pow = poly1[x].pow;
    x++;
    k++;
  }

  while (y < len2) {

    sum[k].coeff = poly2[y].coeff;
    sum[k].pow = poly2[y].pow;
    y++;
    k++;
  }

  return k;
}

int main(int argc, char const *argv[]) {
  int len1, len2, i, j, num;

  printf("Enter the length of the first polynomial:\n");
  scanf("%d", &len1);
  my_poly poly1[len1];
  create(poly1, len1, i);

  printf("Enter the length of the second polynomial:\n");
  scanf("%d", &len2);
  my_poly poly2[len2];
  create(poly2, len2, i);

  int sumlen;

  if (len1 > len2) {
    sumlen = len1;
  }

  else if (len1 < len2) {
    sumlen = len2;
  }

  else {
    sumlen = len1;
  }

  my_poly sum[sumlen];

  num = add(sum, poly1, poly2, len1, len2, i, j, sumlen);

  printf("First polynomial is:\n");

  display(poly1, len1, i, j);

  printf("Second polynomial is:\n");
  display(poly2, len2, i, j);

  printf("Sum is:\n");
  display(sum, num, i, j);

  return 0;
}
