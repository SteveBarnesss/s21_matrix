#include "s21_tests.h"

START_TEST(calccomp_basic) {
  double DATA_COMPARE[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  s21_matrix A = {0}, result = {0}, compare = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &compare);

  s21_fill_matrix(&A, DATA_3X3_8);
  s21_fill_matrix(&compare, DATA_COMPARE);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &compare), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&compare);
}
END_TEST

START_TEST(calccomp_1x1) {
  double DATA_COMPARE[1] = {1};
  s21_matrix A = {0}, result = {0}, compare = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &compare);

  s21_fill_matrix(&A, DATA_1X1_1);
  s21_fill_matrix(&compare, DATA_COMPARE);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &compare), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&compare);
}
END_TEST

START_TEST(calccomp_2x2) {
  double DATA_COMPARE[4] = {4, -3, -2, 1};
  s21_matrix A = {0}, result = {0}, compare = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &compare);

  s21_fill_matrix(&A, DATA_2X2_1);
  s21_fill_matrix(&compare, DATA_COMPARE);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &compare), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&compare);
}
END_TEST

START_TEST(err_input1) {
  s21_matrix A = {0};
  s21_matrix result = {0};

  s21_create_matrix(-3, 2, &A);
  s21_fill_matrix(&A, DATA_3X2_1);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(err_input2) {
  s21_matrix A = {0};
  s21_matrix result = {0};

  s21_create_matrix(0, 2, &A);
  s21_fill_matrix(&A, DATA_3X2_1);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(err_input3) {
  s21_matrix A = {0};
  s21_matrix result = {0};

  s21_create_matrix(3, 2, &A);
  s21_fill_matrix(&A, DATA_3X2_1);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(null_result) {
  s21_matrix A = {0};

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(null_A) {
  s21_matrix result = {0};

  int status = s21_calc_complements(NULL, &result);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(broken_matrix_data) {
  s21_matrix A = {0};
  s21_matrix result = {0};

  A.rows = 3;
  A.columns = 3;
  A.matrix = NULL;

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(null_result_no_crash) {
  s21_matrix A = {0};

  s21_create_matrix(3, 3, &A);
  s21_fill_matrix(&A, DATA_3X3_1);

  int status = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(non_square_1x3) {
  s21_matrix A = {0};
  s21_matrix result = {0};

  s21_create_matrix(1, 3, &A);
  s21_fill_matrix(&A, DATA_3X2_1);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(zero_matrix) {
  s21_matrix A = {0};
  s21_matrix result = {0};

  s21_create_matrix(0, 0, &A);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(float_values1) {
  double data[4] = {1e-9, 2e-9, 3e-9, 4e-9};

  s21_matrix A = {0}, result = {0}, compare = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &compare);

  s21_fill_matrix(&A, data);
  s21_fill_matrix(&compare, DATA_COMPARE_FLOAT_SMALL);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &compare), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&compare);
}
END_TEST

START_TEST(float_values2) {
  double data[4] = {1e-9, 2e-9, 3e-9, 4e-9};

  s21_matrix A = {0}, result = {0}, compare = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &compare);

  s21_fill_matrix(&A, data);
  s21_fill_matrix(&compare, DATA_COMPARE_FLOAT_SMALL);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &compare), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&compare);
}
END_TEST

START_TEST(test_calc_complements_2x2) {
  s21_matrix A = {0}, result = {0}, expected = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &expected);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  expected.matrix[0][0] = 4;
  expected.matrix[0][1] = -3;
  expected.matrix[1][0] = -2;
  expected.matrix[1][1] = 1;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_calc_complements_negative) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(3, 3, &A);

  double data[3][3] = {{1, -2, 3}, {0, 4, -1}, {5, 2, 0}};

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) A.matrix[i][j] = data[i][j];

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], (4 * 0 - (-1) * 2), 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], (1 * 0 - 3 * 5), 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_1x1) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 42;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_double_eq(result.matrix[0][0], 1.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_singular) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(3, 3, &A);

  double data[3][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}};

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) A.matrix[i][j] = data[i][j];

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_not_square) {
  s21_matrix A = {0};

  s21_create_matrix(2, 3, &A);

  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_null) {
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_calc_complements_4x4) {
  s21_matrix A = {0}, result = {0};

  s21_create_matrix(4, 4, &A);

  double val = 1;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) A.matrix[i][j] = val++;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite* s21_calc_complements_suite(void) {
  Suite* s = suite_create("s21_calc_complements");
  TCase* tc = tcase_create("calc_complements");

  tcase_add_test(tc, calccomp_basic);
  tcase_add_test(tc, calccomp_1x1);
  tcase_add_test(tc, calccomp_2x2);
  tcase_add_test(tc, err_input1);
  tcase_add_test(tc, err_input2);
  tcase_add_test(tc, err_input3);
  tcase_add_test(tc, null_result);
  tcase_add_test(tc, null_A);
  tcase_add_test(tc, broken_matrix_data);
  tcase_add_test(tc, null_result_no_crash);
  tcase_add_test(tc, non_square_1x3);
  tcase_add_test(tc, zero_matrix);

  tcase_add_test(tc, float_values1);
  tcase_add_test(tc, float_values2);

  tcase_add_test(tc, test_calc_complements_2x2);
  tcase_add_test(tc, test_calc_complements_negative);
  tcase_add_test(tc, test_calc_complements_1x1);
  tcase_add_test(tc, test_calc_complements_singular);
  tcase_add_test(tc, test_calc_complements_not_square);
  tcase_add_test(tc, test_calc_complements_null);
  tcase_add_test(tc, test_calc_complements_4x4);

  suite_add_tcase(s, tc);
  return s;
}