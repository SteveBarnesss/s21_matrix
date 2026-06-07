#include "s21_tests.h"

START_TEST(determinant_basic) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_7);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_1x1) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(1, 1, &A);
  s21_fill_matrix(&A, DATA_1X1_1);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(result, 99);
  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2x2) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(2, 2, &A);
  s21_fill_matrix(&A, DATA_2X2_1);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(result, -2);
  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_input1) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, 2, &A);
  s21_fill_matrix(&A, DATA_3X2_1);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_input2) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(2, 3, &A);
  s21_fill_matrix(&A, DATA_2X3_1);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_input3) {
  s21_matrix A = {0};

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_determinant(&A, NULL);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_input4) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_determinant(NULL, &result);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_input5) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(-3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_input6) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, 0, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_input7) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, -3, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(float1) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_FLOAT_3X3_RES);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_all_zero) {
  s21_matrix A = {0};
  double result = 1.0;

  s21_create_matrix(3, 3, &A);
  double data[9] = {0};

  s21_fill_matrix(&A, data);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(result, 0.0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_identity) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_ID_3X3);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(result, 1.0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_triangular) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_TRI_3X3);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(result, 70.0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_singular) {
  s21_matrix A = {0};
  double result = 123.0;

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_SINGULAR_3X3);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(result, 0.0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_sign_change) {
  s21_matrix A = {0}, B = {0};
  double detA = 0.0, detB = 0.0;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  s21_fill_matrix(&A, DATA_SWAP_A);
  s21_fill_matrix(&B, DATA_SWAP_B);

  s21_determinant(&A, &detA);
  s21_determinant(&B, &detB);

  ck_assert_double_eq_tol(detB, -detA, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(determinant_fractional) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(2, 2, &A);
  s21_fill_matrix(&A, DATA_FRAC_2X2);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(result, -1.5, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4x4) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(4, 4, &A);
  s21_fill_matrix(&A, DATA_4X4);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(result, 1.0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_repeat_call) {
  s21_matrix A = {0};
  double r1 = 0.0, r2 = 0.0;

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_7);

  s21_determinant(&A, &r1);
  s21_determinant(&A, &r2);

  ck_assert_double_eq_tol(r1, r2, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_15x15) {
  s21_matrix A = {0};
  double result = 0.0;

  s21_create_matrix(15, 15, &A);
  s21_fill_matrix(&A, DATA_15x15);

  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, 0);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("determinant");

  tcase_add_test(tc, determinant_basic);
  tcase_add_test(tc, determinant_1x1);
  tcase_add_test(tc, determinant_2x2);
  tcase_add_test(tc, error_input1);
  tcase_add_test(tc, error_input2);
  tcase_add_test(tc, error_input3);
  tcase_add_test(tc, error_input4);
  tcase_add_test(tc, error_input5);
  tcase_add_test(tc, error_input6);
  tcase_add_test(tc, error_input7);
  tcase_add_test(tc, float1);
  tcase_add_test(tc, determinant_all_zero);

  tcase_add_test(tc, determinant_identity);
  tcase_add_test(tc, determinant_triangular);
  tcase_add_test(tc, determinant_singular);
  tcase_add_test(tc, determinant_sign_change);
  tcase_add_test(tc, determinant_fractional);
  tcase_add_test(tc, determinant_4x4);
  tcase_add_test(tc, determinant_repeat_call);

  tcase_add_test(tc, determinant_15x15);

  suite_add_tcase(s, tc);
  return s;
}