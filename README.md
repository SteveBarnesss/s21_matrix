# s21_matrix

Реализация библиотеки для работы с матрицами на языке C.

## 📌 О проекте

`s21_matrix` — библиотека для выполнения операций с матрицами, написанная на языке **C (C11)**.

Проект реализует основные операции линейной алгебры и ориентирован на работу с динамическими матрицами через структуры и функции.

---

## 🚀 Возможности

### 🔢 Базовые операции
- Сложение матриц
- Вычитание матриц
- Умножение матриц
- Умножение матрицы на число
- Сравнение матриц

### 🧮 Линейная алгебра
- Транспонирование
- Определитель матрицы
- Матрица алгебраических дополнений
- Обратная матрица

---

## 🧱 Интерфейс библиотеки

Основная структура:

```c
typedef struct matrix_struct {
    double **matrix;
    int rows;
    int columns;
} matrix_t;
````

### Основные функции

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```

---

## 📁 Структура проекта

```
src/
 ├── s21_matrix.h
 ├── s21_matrix.c
 ├── s21_helpers.c
 ├── tests/
 │    └── test_matrix.c
 ├── Makefile
```

---

## 🧪 Тестирование

Для тестирования используется **Check framework**.

### Запуск тестов:

```bash
make test
```

### Проверка покрытия (если настроено):

```bash
make gcov_report
```

---

## ⚙️ Сборка

### Сборка библиотеки:

```bash
make s21_matrix.a
```

### Полная сборка:

```bash
make all
```

### Очистка:

```bash
make clean
```

---

## 📋 Требования

* C11
* GCC или Clang
* Check (unit tests)
* Make

---

## ⚠️ Особенности реализации

* Матрицы хранятся в динамической памяти (`double **`)
* Все функции возвращают коды ошибок:

  * `0` — OK
  * `1` — ошибка вычислений
  * `2` — некорректные данные
* Обязательная проверка размеров матриц
* Освобождение памяти через `s21_remove_matrix`

---

## 🎯 Цель проекта

Проект разработан для практики:

* работы с динамической памятью в C
* структур данных
* модульного программирования
* реализации алгоритмов линейной алгебры
* написания unit-тестов

---

Проект выполнен в рамках School 21.

```
