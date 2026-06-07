#include "s21_tests.h"

START_TEST(invalid_input1) {
  s21_matrix A = {0};

  int status = s21_create_matrix(0, 0, &A);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(invalid_input2) {
  s21_matrix A = {0};

  int status = s21_create_matrix(-2, -2, &A);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(invalid_input3) {
  s21_matrix A = {0};

  int status = s21_create_matrix(3, 0, &A);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(invalid_input4) {
  s21_matrix A = {0};

  int status = s21_create_matrix(3, -2, &A);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(invalid_input5) {
  s21_matrix A = {0};

  int status = s21_create_matrix(-2, 3, &A);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(invalid_input6) {
  s21_matrix A = {0};

  int status = s21_create_matrix(0, 3, &A);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(invalid_input7) {
  int status = s21_create_matrix(3, 3, NULL);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(create_and_remove) {
  s21_matrix A = {0};

  int status = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(recreate_matrix) {
  s21_matrix A = {0};

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  s21_remove_matrix(&A);

  // повторно
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  s21_remove_matrix(&A);
}
END_TEST

Suite* s21_create_matrix_suite(void) {
  Suite* s = suite_create("s21_create_matrix");
  TCase* tc = tcase_create("create_matrix");

  tcase_add_test(tc, invalid_input1);
  tcase_add_test(tc, invalid_input2);
  tcase_add_test(tc, invalid_input3);
  tcase_add_test(tc, invalid_input4);
  tcase_add_test(tc, invalid_input5);
  tcase_add_test(tc, invalid_input6);
  tcase_add_test(tc, invalid_input7);

  tcase_add_test(tc, create_and_remove);
  tcase_add_test(tc, recreate_matrix);
  suite_add_tcase(s, tc);
  return s;
}