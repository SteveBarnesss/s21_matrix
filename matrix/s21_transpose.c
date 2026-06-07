#include "../s21_matrix.h"

int s21_transpose(s21_matrix* A, s21_matrix* result) {
  if (!result || !A || !A->matrix || A->rows <= 0 || A->columns <= 0)
    return INCORRECT_MATRIX;

  if (s21_create_matrix(A->columns, A->rows, result)) {
    return INCORRECT_MATRIX;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}