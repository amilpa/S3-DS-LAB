#include <math.h>
#include <stdio.h>

int main() {
  int n, i, j, sum;
  printf("Enter the number of rows:\n");
  scanf("%d", &n);
  int a[n][4];
  printf("Enter the matrix:\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    sum = 0;
    for (j = 0; j < 4; j++) {
      sum += a[i][j] * pow(2, 3 - j);
    }
    if (sum < 10) {
      printf("The hexadecimal number is:%d\n", sum);

    } else {
      printf("The hexadecimal number is:%c\n", sum + 55);
    }
  }
  return 0;
}
