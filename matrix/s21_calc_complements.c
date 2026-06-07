#include "../s21_matrix.h"

static void s21_get_calcomp_matrix(s21_matrix *A, int r, int c,
                                   s21_matrix *result) {
  int res_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (r == i)
      continue;
    int res_j = 0;
    for (int j = 0; j < A->columns; j++) {
      if (c == j)
        continue;
      result->matrix[res_i][res_j] = A->matrix[i][j];
      res_j++;
    }
    res_i++;
  }
}

static int s21_get_calccomp_value(s21_matrix *A, int i, int j, double *result) {
  s21_matrix minor = {0};

  int err = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  if (err != 0)
    return err;

  s21_get_calcomp_matrix(A, i, j, &minor);

  double det_minor = 0.0;
  err = s21_determinant(&minor, &det_minor);

  s21_remove_matrix(&minor);

  if (err != 0)
    return err;

  double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
  *result = sign * det_minor;

  return 0;
}

int s21_calc_complements(s21_matrix *A, s21_matrix *result) {
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALC_ERROR;
  }

  int n = A->rows;

  int err = s21_create_matrix(n, n, result);
  if (err != 0)
    return err;

  // матрица 1x1
  if (n == 1) {
    result->matrix[0][0] = 1.0;
    return 0;
  }

  // Вычисляем алгебраические дополнения для каждого элемента
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double value = 0.0;

      err = s21_get_calccomp_value(A, i, j, &value);
      if (err != 0) {
        s21_remove_matrix(result);
        return err;
      }

      result->matrix[i][j] = value;
    }
  }

  return 0;
}