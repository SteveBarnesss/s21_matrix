#include "../s21_matrix.h"

int s21_sub_matrix(s21_matrix* A, s21_matrix* B, s21_matrix* result) {
  if (!result || (!A || !A->matrix || A->rows <= 0 || A->columns <= 0) ||
      (!B || !B->matrix || B->rows <= 0 || B->columns <= 0))
    return INCORRECT_MATRIX;

  if (A->rows != B->rows || A->columns != B->columns) return CALC_ERROR;

  if (s21_create_matrix(A->rows, A->columns, result)) {
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}