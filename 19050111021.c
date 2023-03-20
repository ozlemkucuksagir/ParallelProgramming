//#include <19050111021.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	 // call a function in another file
 // myPrintHelloMake();
  if (argc != 4) {
    printf("Please enter: %s rowsNumber columnsNumber file_name.txt \n", argv[0]);
    return 1;
  }
  // parse command line arguments
  int rows = atoi(argv[1]);
  int columns = atoi(argv[2]);
  char *output_file = argv[3];
  
  
  
  // set seed for random number generator
  srand(190501);

  // allocate memory for matrix
  double **matrix = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (double *)malloc(columns * sizeof(double));
  }

  // fill the matrix with random values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = (double)rand() / RAND_MAX * 99.0 + 1.0;
    }
  }

	printf("MATRIX: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%.2f ", (matrix)[i][j]);
        }
        printf("\n");
    }
    
  // allocate memory for vector
  double *vector = (double *)malloc(columns * sizeof(double));

  // fill vector with random values
  for (int i = 0; i < columns; i++) {
    vector[i] = (double)rand() / RAND_MAX * 99.0 + 1.0;
  }

  // multiplication of perform matrix-vector 
  double *result = (double *)calloc(rows, sizeof(double));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result[i] += matrix[i][j] * vector[j];
    }
  }

  // write result to outputfile
  FILE *f = fopen(output_file, "w");
  for (int i = 0; i < rows; i++) {
    fprintf(f, "%0.2f\n", result[i]);
  }
  fclose(f);

  // free allocated memory
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
  free(vector);
  free(result);
  
  return 0;
}
