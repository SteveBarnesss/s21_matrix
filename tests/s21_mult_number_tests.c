#include "s21_tests.h"

START_TEST(mult_number_basic) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&expected, DATA_3X3_5);

  int status = s21_mult_number(&A, 2, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST;

START_TEST(mult_number_zero) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&expected, DATA_NEG_3X3_3);  // все нули

  int status = s21_mult_number(&A, 0, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST;

START_TEST(mult_number_negative) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&expected, DATA_NEG_3X3);  // на -1

  int status = s21_mult_number(&A, -1, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST;

START_TEST(mult_number_float) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_FLOAT_3X3);
  s21_fill_matrix(&expected, DATA_FLOAT_3X3_RES);

  int status = s21_mult_number(&A, 2, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST;

START_TEST(mult_number_10x10) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &expected);

  s21_fill_matrix(&A, DATA_10X10);
  s21_fill_matrix(&expected, RESULT_10X10_SUM);  // *2

  int status = s21_mult_number(&A, 2, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST;

START_TEST(mult_number_invalid_matrix) {
  s21_matrix A = {0}, result = {0};

  int status = s21_mult_number(&A, 2, &result);

  ck_assert_int_eq(status, 1);
}
END_TEST;

START_TEST(mult_number_null_result) {
  s21_matrix A = {0};

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_mult_number(&A, 2, NULL);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST;

Suite* s21_mult_number_suite(void) {
  Suite* s = suite_create("s21_mult_number");
  TCase* tc = tcase_create("mult_number");

  tcase_add_test(tc, mult_number_basic);
  tcase_add_test(tc, mult_number_zero);
  tcase_add_test(tc, mult_number_negative);
  tcase_add_test(tc, mult_number_float);
  tcase_add_test(tc, mult_number_10x10);
  tcase_add_test(tc, mult_number_invalid_matrix);
  tcase_add_test(tc, mult_number_null_result);

  suite_add_tcase(s, tc);
  return s;
}