#include "../s21_matrix.h"

int s21_inverse_matrix(s21_matrix *A, s21_matrix *result) {
  if (!A || !A->matrix || A->rows <= 0 || A->columns <= 0 || !result)
    return INCORRECT_MATRIX;

  if (A->rows != A->columns)
    return CALC_ERROR;

  int status = OK;
  double det = 0.0;

  // Вычисление детерминанта:
  status = s21_determinant(A, &det);
  if (status != OK || fabs(det) < EPS)
    return status;

  // Вычисление матрицы алгебраических дополнений:
  s21_matrix matrix_minor = {0};
  status = s21_calc_complements(A, &matrix_minor);
  if (status != OK) {

    s21_remove_matrix(&matrix_minor);
    return status;
  }

  // Транспонирование матрицы дополнений:
  s21_matrix matrix_transposed = {0};
  status = s21_transpose(&matrix_minor, &matrix_transposed);
  s21_remove_matrix(&matrix_minor);
  if (status != OK) {
    s21_remove_matrix(&matrix_transposed);
    return status;
  }

  // Умножение на 1 / det:
  status = s21_mult_number(&matrix_transposed, 1.0 / det, result);
  s21_remove_matrix(&matrix_transposed);

  if (status != OK)
    return status;

  return OK;
}