#include <stdio.h>

typedef struct node {
  int row;
  int column;
  int value;
} sparse;

int main(int argc, char *argv[]) {

  int size1, i, j;
  printf("Enter the number of non zero elements in the matrix: ");
  scanf("%d", &size1);

  sparse spa[size1 + 1];
  spa[0].value = size1;

  printf("Enter the number of rows and coloumns: ");
  scanf("%d %d", &spa[0].row, &spa[0].column);

  printf("Enter the sparse matrix representation: ");
  for (int i = 1; i <= size1; i++)
    scanf("%d %d %d", &spa[i].row, &spa[i].column, &spa[i].value);

  sparse tran[size1 + 1];

  int k = 1;
  printf("The sparse matrix representation is:\n");

  for (i = 0; i <= size1; i++) {
    printf("%d %d %d\n", spa[i].row, spa[i].column, spa[i].value);
  }

  tran[0].row = spa[0].column;
  tran[0].column = spa[0].row;
  tran[0].value = spa[0].value;

  int rowTerms[spa[0].column];
  int startpos[spa[0].column];

  startpos[0] = 1;

  for (i = 0; i < spa[0].column; i++) {
    rowTerms[i] = 0;
  }

  for (i = 1; i <= size1; i++) {
    rowTerms[spa[i].column]++;
  }

  for (i = 1; i < spa[0].column; i++) {
    startpos[i] = startpos[i - 1] + rowTerms[i - 1];
  }

  for (i = 1; i <= size1; i++) {
    j = startpos[spa[i].column]++;
    tran[j].row = spa[i].column;
    tran[j].column = spa[i].row;
    tran[j].value = spa[i].value;
  }

  printf("The representation of the transpose of the sparse matrix is:\n");

  printf("%d %d %d\n", tran[0].row, tran[0].column, tran[0].value);

  for (i = 1; i <= size1; i++) {
    printf("%d %d %d\n", tran[i].row, tran[i].column, tran[i].value);
  }
  return 0;
}
