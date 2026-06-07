#include "s21_tests.h"

START_TEST(mult_basic) {
  s21_matrix A = {0}, B = {0}, C = {0}, EXPECTED = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &EXPECTED);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&B, DATA_3X3_2);

  double res[9] = {30, 24, 18, 84, 69, 54, 138, 114, 90};
  s21_fill_matrix(&EXPECTED, res);

  int status = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(status, 0);
  ck_assert(s21_eq_matrix(&C, &EXPECTED));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&EXPECTED);
}
END_TEST;

START_TEST(mult_zero_matrix) {
  s21_matrix A = {0}, B = {0}, C = {0}, ZERO = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &ZERO);

  s21_fill_matrix(&A, DATA_3X3_1);

  double zero[9] = {0};
  s21_fill_matrix(&B, zero);
  s21_fill_matrix(&ZERO, zero);

  s21_mult_matrix(&A, &B, &C);

  ck_assert(s21_eq_matrix(&C, &ZERO));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&ZERO);
}
END_TEST;

START_TEST(mult_identity) {
  s21_matrix A = {0}, B = {0}, C = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  s21_fill_matrix(&A, DATA_3X3_1);

  double identity[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  s21_fill_matrix(&B, identity);

  // Ручной расчёт:
  // [1 4 7]   [1 0 0]   [1 4 7]
  // [2 5 8] * [0 1 0] = [2 5 8]
  // [3 6 9]   [0 0 1]   [3 6 9]

  s21_mult_matrix(&A, &B, &C);

  ck_assert(s21_eq_matrix(&A, &C));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST;

START_TEST(mult_wrong_size) {
  s21_matrix A = {0}, B = {0}, C = {0};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);

  int status = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(mult_invalid_matrix) {
  s21_matrix A = {0}, B = {0}, C = {0};

  s21_create_matrix(-3, 3, &A);
  s21_create_matrix(3, 3, &B);

  int status = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(mult_null_result) {
  s21_matrix A = {0}, B = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  s21_fill_matrix(&A, DATA_3X3_1);
  s21_fill_matrix(&B, DATA_3X3_2);

  int status = s21_mult_matrix(&A, &B, NULL);

  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(mult_rectangular) {
  s21_matrix A = {0}, B = {0}, C = {0}, EXPECTED = {0};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 2, &EXPECTED);

  double a_data[6] = {1, 2, 3, 4, 5, 6};

  double b_data[6] = {7, 8, 9, 10, 11, 12};

  // Ручной расчёт:
  // [1 2 3]   [ 7  8]   [ 58  64]
  // [4 5 6] * [ 9 10] = [139 154]
  //           [11 12]

  double result[4] = {58, 64, 139, 154};

  s21_fill_matrix(&A, a_data);
  s21_fill_matrix(&B, b_data);
  s21_fill_matrix(&EXPECTED, result);

  int status = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(status, 0);
  ck_assert(s21_eq_matrix(&C, &EXPECTED));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&EXPECTED);
}
END_TEST;

Suite* s21_mult_matrix_suite(void) {
  Suite* s = suite_create("s21_mult_matrix");
  TCase* tc = tcase_create("mult_matrix");

  tcase_add_test(tc, mult_basic);
  tcase_add_test(tc, mult_zero_matrix);
  tcase_add_test(tc, mult_identity);
  tcase_add_test(tc, mult_wrong_size);
  tcase_add_test(tc, mult_invalid_matrix);
  tcase_add_test(tc, mult_null_result);
  tcase_add_test(tc, mult_rectangular);
  suite_add_tcase(s, tc);
  return s;
}