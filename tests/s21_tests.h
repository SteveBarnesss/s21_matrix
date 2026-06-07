#ifndef TESTS_H
#define TESTS_H

#include <check.h>

#include "../s21_matrix.h"

// matrix functions
Suite *s21_create_matrix_suite(void);
Suite *s21_eq_matrix_suite(void);
// arithmetic operation
Suite *s21_sum_matrix_suite(void);
Suite *s21_sub_matrix_suite(void);
Suite *s21_mult_number_suite(void);
Suite *s21_mult_matrix_suite(void);
// other operation
Suite *s21_transpose_suite(void);
Suite *s21_determinant_suite(void);
Suite *s21_calc_complements_suite(void);
Suite *s21_inverse_matrix_suite(void);

/* UTILS */
void s21_fill_matrix(s21_matrix *A, const double *data);

/* DATA SETS: */

// 1x1
extern const double DATA_1X1_1[1];

// 2x2
extern const double DATA_2X2_1[4];

// 3x3
extern const double DATA_3X3_1[9];
extern const double DATA_3X3_2[9];

// sum&sub previous
extern const double DATA_3X3_3[9];
extern const double DATA_3X3_4[9];
extern const double DATA_3X3_5[9];
extern const double DATA_3X3_6[9];
extern const double DATA_3X3_7[9];
extern const double DATA_3X3_8[9];

// 2x3
extern const double DATA_2X3_1[6];
extern const double DATA_2X3_2[6];

// 3x2
extern const double DATA_3X2_1[6];
extern const double DATA_3X2_2[6];
extern const double DATA_3X2_3[6];

// 10x10
extern const double DATA_10X10[100];
extern const double DATA_10X10_T[100];
extern const double RESULT_10X10_SUM[100];

// 3x3 float
extern const double DATA_FLOAT_3X3[9];
extern const double DATA_FLOAT_3X3_RES[9];
extern const double DATA_FLOAT_3X3_SUB[9];

// 3x3 negative
extern const double DATA_NEG_3X3[9];
extern const double DATA_NEG_3X3_2[9];
extern const double DATA_NEG_3X3_3[9];

// no transpose
extern const double DATA_PATTERN_3X3[9];

// other
extern const double DATA_ID_3X3[9];
extern const double DATA_3X3_FULL[9];
extern const double DATA_4X4[16];
extern const double DATA_BAD_3X3[9];
extern const double DATA_FRAC_2X2[4];
extern const double DATA_SWAP_A[4];
extern const double DATA_SWAP_B[4];
extern const double DATA_SINGULAR_3X3[9];
extern const double DATA_TRI_3X3[9];
extern const double DATA_COMPARE_FLOAT_SMALL[4];
extern const double DATA_3x3_INV[9];
extern const double DATA_3x3_INV_EXP[9];
extern const double DATA_15x15[225];

#endif