#include <stdio.h>


typedef struct node{
  int row;
  int column;
  int value;
}sparse;

int main() {

  int i,j;

  int sparseMatrix[4][5] = {
      {0, 0, 3, 0, 4}, {0, 0, 5, 7, 0}, {0, 0, 0, 0, 0}, {0, 2, 6, 0, 0}};


  printf("The sparse matrix is:\n");

  int size = 0;
  for ( i = 0; i < 4; i++){
    for ( j = 0; j < 5; j++){
      printf("%d " , sparseMatrix[i][j]);
      if (sparseMatrix[i][j] != 0)
        size++;
    }
    
    printf("\n");

  }

  float sparsity = float(20 - size) / 20 ;

  sparse spar[size+1];

  spar[0].value = size;
  spar[0].column = 5;
  spar[0].row = 4;


  // Making of new matrix
  int k = 1;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 5; j++)
      if (sparseMatrix[i][j] != 0) {

        spar[k].row = i;
        spar[k].column = j;
        spar[k].value = sparseMatrix[i][j];

        k++;
      }


  printf("The sparse representation is:\n");
  for (i = 0; i < size + 1; i++) {
    printf("%d %d %d \n" , spar[i].row , spar[i].column , spar[i].value);
  }

  printf("The sparsity of the matrix = %.2f\n" , sparsity);
  return 0;
}
