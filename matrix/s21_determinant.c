#include "../s21_matrix.h"
int s21_determinant(s21_matrix *A, double *result) {
  if (!result || (!A || !A->matrix || A->rows <= 0 || A->columns <= 0))
    return INCORRECT_MATRIX;

  if (A->rows != A->columns)
    return CALC_ERROR;

  int n = A->rows;
  *result = 1.0;

  // создаем копию матрицы
  s21_matrix tmp = {0};
  if (s21_create_matrix(n, n, &tmp) != OK)
    return INCORRECT_MATRIX;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp.matrix[i][j] = A->matrix[i][j];
    }
  }

  int sign = 1;

  for (int i = 0; i < n; i++) {
    // поиск ненулевого pivot
    int pivot = i;
    while (pivot < n && fabs(tmp.matrix[pivot][i]) < 1e-7)
      pivot++;

    // если вся колонка 0 → det = 0
    if (pivot == n) {
      *result = 0.0;
      s21_remove_matrix(&tmp);
      return OK;
    }

    // свап строк
    if (pivot != i) {
      for (int j = 0; j < n; j++) {
        double temp = tmp.matrix[i][j];
        tmp.matrix[i][j] = tmp.matrix[pivot][j];
        tmp.matrix[pivot][j] = temp;
      }
      sign *= -1;
    }

    // обнуление ниже
    for (int k = i + 1; k < n; k++) {
      double factor = tmp.matrix[k][i] / tmp.matrix[i][i];
      for (int j = i; j < n; j++) {
        tmp.matrix[k][j] -= factor * tmp.matrix[i][j];
      }
    }
  }

  // произведение диагонали
  for (int i = 0; i < n; i++) {
    *result *= tmp.matrix[i][i];
  }

  *result *= sign;

  s21_remove_matrix(&tmp);
  return OK;
}