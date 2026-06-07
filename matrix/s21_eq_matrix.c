#include "../s21_matrix.h"
int s21_eq_matrix(s21_matrix* A, s21_matrix* B) {
  if (!A || !B) return FAILURE;

  if (!A->matrix || !B->matrix || A->rows <= 0 || A->columns <= 0 ||
      B->rows <= 0 || B->columns <= 0)
    return FAILURE;

  if (A->rows != B->rows || A->columns != B->columns) return FAILURE;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}