#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, s21_matrix *result) {
  if (rows <= 0 || columns <= 0 || result == NULL)
    return INCORRECT_MATRIX;

  result->rows = 0;
  result->columns = 0;
  result->matrix = NULL;

  result->matrix = malloc(rows * sizeof(double *));
  if (!result->matrix) {
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = malloc(columns * sizeof(double));
    if (!result->matrix[i]) {
      for (int j = 0; j < i; j++)
        free(result->matrix[j]);
      free(result->matrix);
      return INCORRECT_MATRIX;
    }
  }
  result->rows = rows;
  result->columns = columns;

  return OK;
}

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