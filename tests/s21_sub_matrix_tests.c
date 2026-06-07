#include "s21_tests.h"

START_TEST(base_sub) {
  s21_matrix A = {0}, B = {0}, C = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&B, DATA_3X3_2);
  s21_fill_matrix(&expected, DATA_3X3_4);

  s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(s21_eq_matrix(&C, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(negative_sub) {
  s21_matrix A = {0}, B = {0}, C = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_NEG_3X3);
  s21_fill_matrix(&B, DATA_NEG_3X3);
  s21_fill_matrix(&expected, DATA_NEG_3X3_3);

  s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(s21_eq_matrix(&C, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(float_sub) {
  s21_matrix A = {0}, B = {0}, C = {0}, expected = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);

  s21_fill_matrix(&A, DATA_FLOAT_3X3);
  s21_fill_matrix(&B, DATA_FLOAT_3X3);
  s21_fill_matrix(&expected, DATA_FLOAT_3X3_SUB);

  s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(s21_eq_matrix(&C, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(big_sub) {
  s21_matrix A = {0}, B = {0}, C = {0};

  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);

  s21_fill_matrix(&A, DATA_10X10);
  s21_fill_matrix(&B, DATA_10X10);

  s21_sub_matrix(&A, &B, &C);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(different_size) {
  s21_matrix A = {0}, B = {0}, C = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  s21_fill_matrix(&A, DATA_3X2_1);
  s21_fill_matrix(&B, DATA_2X3_2);

  int status = s21_sub_matrix(&A, &B, &C);

  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_null) {
  s21_matrix A = {0}, B = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &A), 1);
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &B), 1);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_invalid) {
  s21_matrix A = {0}, B = {0}, result = {0};

  A.rows = 2;
  A.columns = 2;
  A.matrix = NULL;

  s21_create_matrix(2, 2, &B);

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&B);
}
END_TEST

Suite* s21_sub_matrix_suite(void) {
  Suite* s = suite_create("s21_sub_matrix");
  TCase* tc = tcase_create("sub_matrix");

  tcase_add_test(tc, base_sub);
  tcase_add_test(tc, negative_sub);
  tcase_add_test(tc, float_sub);
  tcase_add_test(tc, big_sub);
  tcase_add_test(tc, different_size);
  tcase_add_test(tc, sub_matrix_null);
  tcase_add_test(tc, sub_matrix_invalid);

  suite_add_tcase(s, tc);
  return s;
}