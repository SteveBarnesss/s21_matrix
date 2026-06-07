#include "s21_tests.h"

START_TEST(transpose_basic) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &expected);

  s21_fill_matrix(&A, DATA_2X3_1);
  s21_fill_matrix(&expected, DATA_3X2_3);

  s21_transpose(&A, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_square) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&expected, DATA_3X3_6);

  s21_transpose(&A, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_big) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &expected);

  s21_fill_matrix(&A, DATA_10X10);
  s21_fill_matrix(&expected, DATA_10X10_T);

  s21_transpose(&A, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(err_size_input) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(-3, 3, &A);
  s21_create_matrix(3, 2, &expected);

  s21_fill_matrix(&A, DATA_2X3_1);
  s21_fill_matrix(&expected, DATA_3X2_3);

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(null_input) {
  s21_matrix A = {0};

  s21_create_matrix(2, 3, &A);

  s21_fill_matrix(&A, DATA_2X3_1);

  int status = s21_transpose(&A, NULL);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(null_input_matrix) {
  s21_matrix result = {0};

  int status = s21_transpose(NULL, &result);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(null_both) {
  int status = s21_transpose(NULL, NULL);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(transpose_1x1) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &expected);

  double data[1] = {5.0};

  s21_fill_matrix(&A, data);
  s21_fill_matrix(&expected, data);

  s21_transpose(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_symmetric) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(3, 3, &A);

  s21_fill_matrix(&A, DATA_PATTERN_3X3);

  s21_transpose(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&A, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s = suite_create("s21_transpose");
  TCase *tc = tcase_create("transpose");

  tcase_add_test(tc, transpose_basic);
  tcase_add_test(tc, transpose_square);
  tcase_add_test(tc, transpose_big);
  tcase_add_test(tc, err_size_input);
  tcase_add_test(tc, null_input);
  tcase_add_test(tc, null_input_matrix);
  tcase_add_test(tc, null_both);
  tcase_add_test(tc, transpose_1x1);
  tcase_add_test(tc, transpose_symmetric);

  suite_add_tcase(s, tc);
  return s;
}