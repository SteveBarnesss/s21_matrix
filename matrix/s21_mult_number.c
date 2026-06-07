#include "../s21_matrix.h"

int s21_mult_number(s21_matrix* A, double number, s21_matrix* result) {
  if (!result || (!A || !A->matrix || A->rows <= 0 || A->columns <= 0) ||
      s21_create_matrix(A->rows, A->columns, result))
    return INCORRECT_MATRIX;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = number * (A->matrix[i][j]);
    }
  }

  return OK;
}