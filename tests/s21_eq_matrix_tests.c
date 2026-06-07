#include "s21_tests.h"

START_TEST(equal_AB) {
  s21_matrix A = {0}, B = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&B, DATA_3X3_1);

  int status = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(different_AB) {
  s21_matrix A = {0}, B = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&B, DATA_3X3_2);

  int status = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(null_matrix) {
  int status = s21_eq_matrix(NULL, NULL);

  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(different_columns) {
  s21_matrix A = {0}, B = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 2, &B);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&B, DATA_3X2_1);

  int status = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(different_rows) {
  s21_matrix A = {0}, B = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&B, DATA_2X3_1);

  int status = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite* s21_eq_matrix_suite(void) {
  Suite* s = suite_create("s21_eq_matrix");
  TCase* tc = tcase_create("eq_matrix");

  tcase_add_test(tc, equal_AB);
  tcase_add_test(tc, different_AB);
  tcase_add_test(tc, null_matrix);
  tcase_add_test(tc, different_columns);
  tcase_add_test(tc, different_rows);

  suite_add_tcase(s, tc);
  return s;
}