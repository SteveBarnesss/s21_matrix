#include "../s21_matrix.h"

void s21_remove_matrix(s21_matrix* A) {
  if (!A || !A->matrix) return;
  for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
  free(A->matrix);

  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}