#include "s21_tests.h"

START_TEST(test_inverse_matrix_3x3) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_3x3_INV);
  s21_fill_matrix(&expected, DATA_3x3_INV_EXP);

  s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_inverse_matrix_determinant_zero) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;

  int status = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_not_square) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(2, 3, &A);

  int status = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status, CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_null) {
  s21_matrix result = {0};

  int status = s21_inverse_matrix(NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_inverse_matrix_1x1) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &expected);

  A.matrix[0][0] = 5;
  expected.matrix[0][0] = 1.0 / 5.0;

  int status = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_inverse_matrix_2x2) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &expected);

  A.matrix[0][0] = 4;
  A.matrix[0][1] = 7;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 6;

  double det = 4 * 6 - 7 * 2;

  expected.matrix[0][0] = 6.0 / det;
  expected.matrix[0][1] = -7.0 / det;
  expected.matrix[1][0] = -2.0 / det;
  expected.matrix[1][1] = 4.0 / det;

  int status = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_inverse_matrix_null_result) {
  s21_matrix A = {0};

  s21_create_matrix(2, 2, &A);

  int status = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_invalid_structure) {
  s21_matrix A = {0}, result = {0};

  A.rows = 3;
  A.columns = 3;
  A.matrix = NULL;

  int status = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_inverse_matrix_no_alloc_on_error) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(2, 3, &A);

  int status = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status, CALC_ERROR);
  ck_assert_ptr_eq(result.matrix, NULL);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_data_reuse) {
  s21_matrix A = {0}, B = {0}, R = {0}, EXPECTED = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &EXPECTED);

  s21_fill_matrix(&A, DATA_2X2_1);
  s21_fill_matrix(&B, DATA_2X2_1);

  EXPECTED.matrix[0][0] = -2.0;
  EXPECTED.matrix[0][1] = 1.0;
  EXPECTED.matrix[1][0] = 1.5;
  EXPECTED.matrix[1][1] = -0.5;

  int statusA = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(statusA, OK);
  ck_assert_int_eq(s21_eq_matrix(&R, &EXPECTED), SUCCESS);

  s21_remove_matrix(&R);

  int statusB = s21_inverse_matrix(&B, &R);
  ck_assert_int_eq(statusB, OK);
  ck_assert_int_eq(s21_eq_matrix(&R, &EXPECTED), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&EXPECTED);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc = tcase_create("inverse_matrix");

  tcase_add_test(tc, test_inverse_matrix_3x3);
  tcase_add_test(tc, test_inverse_matrix_determinant_zero);
  tcase_add_test(tc, test_inverse_matrix_not_square);
  tcase_add_test(tc, test_inverse_matrix_null);

  tcase_add_test(tc, test_inverse_matrix_1x1);
  tcase_add_test(tc, test_inverse_matrix_2x2);
  tcase_add_test(tc, test_inverse_matrix_null_result);
  tcase_add_test(tc, test_inverse_matrix_invalid_structure);
  tcase_add_test(tc, test_inverse_matrix_no_alloc_on_error);
  tcase_add_test(tc, test_inverse_matrix_data_reuse);

  suite_add_tcase(s, tc);
  return s;
}