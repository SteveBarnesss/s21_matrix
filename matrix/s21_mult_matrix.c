#include "../s21_matrix.h"

int s21_mult_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result) {
  if (!result || (!A || !A->matrix || A->rows <= 0 || A->columns <= 0) ||
      (!B || !B->matrix || B->rows <= 0 || B->columns <= 0))
    return INCORRECT_MATRIX;

  if (A->columns != B->rows)
    return CALC_ERROR;

  if (s21_create_matrix(A->rows, B->columns, result)) {
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);
      }
    }
  }
  return OK;
}