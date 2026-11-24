#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>

#define SIZE 10
#define TYPE_SIZE(type, name) type name[2];

void PrintBytes(void* ptr, size_t size);
void PrintBytesReversed(void* ptr, size_t size);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    setlocale(LC_NUMERIC, "C");

    // Task1
    printf("Задание 1\n\n");

    char* pc;
    int* pi;
    double* pd;

    printf("Размер указателя char*   : %zu байт\n", sizeof(pc));
    printf("Размер указателя int*    : %zu байт\n", sizeof(pi));
    printf("Размер указателя double* : %zu байт\n", sizeof(pd));

    // Task2
    printf("\nЗадание 2\n\n");

    float PI = 3.14159f, * p1, * p2;
    p1 = p2 = &PI;

    printf("По адресу p1 = %p (в hex: %llx) хранится *p1 = %g\n",
        (void*)p1, (unsigned long long)(size_t)p1, *p1);
    printf("По адресу p2 = %p (в hex: %llx) хранится *p2 = %g\n",
        (void*)p2, (unsigned long long)(size_t)p2, *p2);
    printf("Вывод: оба указателя ссылаются на одну и ту же область памяти переменной PI.\n");

    // Task3
    printf("\nЗадание 3\n\n");

    int x = 5, * pa = &x;
    double d = 12.34, * p_dbl = &d;
    char ch = 'A', * p_chr = &ch;
    long double ld = 99.99L, * p_ld = &ld;
    short unsigned int sui = 10, * p_sui = &sui;
    _Bool b = 1, * p_bool = &b;

    printf("--- Тип int (размер %zu байт) ---\n", sizeof(int));
    printf("По адресу %p хранится *pa = %d\n", (void*)pa, *pa);
    pa++;
    printf("После pa++ адрес = %p (сдвиг на %zu байт)\n", (void*)pa, sizeof(int));
    pa--;
    printf("После pa-- адрес = %p, *pa = %d\n\n", (void*)pa, *pa);

    printf("--- Тип double (размер %zu байт) ---\n", sizeof(double));
    printf("По адресу %p хранится *p_dbl = %g\n", (void*)p_dbl, *p_dbl);
    p_dbl++;
    printf("После p_dbl++ адрес = %p (сдвиг на %zu байт)\n", (void*)p_dbl, sizeof(double));
    p_dbl--;
    printf("После p_dbl-- адрес = %p, *p_dbl = %g\n\n", (void*)p_dbl, *p_dbl);

    printf("--- Тип char (размер %zu байт) ---\n", sizeof(char));
    printf("По адресу %p хранится *p_chr = %c\n", (void*)p_chr, *p_chr);
    p_chr++;
    printf("После p_chr++ адрес = %p (сдвиг на %zu байт)\n", (void*)p_chr, sizeof(char));
    p_chr--;
    printf("После p_chr-- адрес = %p, *p_chr = %c\n\n", (void*)p_chr, *p_chr);

    printf("--- Тип long double (размер %zu байт) ---\n", sizeof(long double));
    printf("Начальный адрес: %p -> после ++: %p\n", (void*)p_ld, (void*)(p_ld + 1));

    printf("--- Тип short unsigned int (размер %zu байт) ---\n", sizeof(short unsigned int));
    printf("Начальный адрес: %p -> после ++: %p\n", (void*)p_sui, (void*)(p_sui + 1));

    printf("--- Тип _Bool (размер %zu байт) ---\n", sizeof(_Bool));
    printf("Начальный адрес: %p -> после ++: %p\n", (void*)p_bool, (void*)(p_bool + 1));

    // Task4
    printf("\nЗадание 4\n\n");

    float array[SIZE] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.1f };
    float* ptr_a;
    int i;

    printf("4.1 Сравнение адресов начала массива:\n");
    printf("array     = %p\n", (void*)array);
    printf("&array[0] = %p\n", (void*)&array[0]);
    printf("&array    = %p\n\n", (void*)&array);

    printf("4.2 Перемещение по массиву:\n");
    ptr_a = array;
    printf("Начало (ptr_a)       : адрес = %p, *ptr_a = %.1f\n", (void*)ptr_a, *ptr_a);

    ptr_a++;
    printf("После ptr_a++        : адрес = %p, *ptr_a = %.1f\n", (void*)ptr_a, *ptr_a);

    printf("Сдвиг (ptr_a + 4)    : адрес = %p, *(ptr_a + 4) = %.1f\n", (void*)(ptr_a + 4), *(ptr_a + 4));

    ptr_a += 2; 
    printf("Сдвиг (ptr_a - 2) от array[3]: адрес = %p, *(ptr_a - 2) = %.1f\n\n",
        (void*)(ptr_a - 2), *(ptr_a - 2));

    printf("4.3 Прямой проход по массиву с шагом 2:\n");
    for (ptr_a = array; ptr_a < array + SIZE; ptr_a += 2)
    {
        printf("Адрес = %p | Значение = %.1f\n", (void*)ptr_a, *ptr_a);
    }
    printf("\n");

    printf("4.4 Обратный проход по массиву с декрементом:\n");
    ptr_a = &array[SIZE - 1];
    for (i = 0; i < SIZE; i++)
    {
        printf("Адрес = %p | Значение = %.1f\n", (void*)ptr_a, *ptr_a);
        if (i < SIZE - 1)
        {
            ptr_a--;
        }
    }

    // Task5
    printf("\nЗадание 5\n\n");

    x = 0x12345678;
    int* prt;
    unsigned char* a1, * a2, * a3, * a4;
    unsigned char* a;

    prt = &x;
    a = (unsigned char*)prt;
    a1 = a + 3;
    a2 = a + 2;
    a3 = a + 1;
    a4 = a;

    printf("5.1 Исследование числа 0x12345678:\n");
    printf("%.2x\n%.2x\n%.2x\n%.2x\n", *a1, *a2, *a3, *a4);
    printf("Вывод: по младшему адресу (*a) хранится младший байт %.2x -> порядок Little-Endian (схема B).\n\n", *a);

    int valInt = 12345;
    float valFloat = 12345.0f;
    double valDouble = 12345.0;

    printf("5.2 и 5.3 Сравнение представления числа 12345 в разных типах:\n");

    printf("[int 12345]\n");
    printf("  В памяти (от младшего адреса к старшему): ");
    PrintBytes(&valInt, sizeof(valInt));
    printf("  От старшего байта к младшему            : ");
    PrintBytesReversed(&valInt, sizeof(valInt));

    printf("\n[float 12345.0]\n");
    printf("  В памяти (от младшего адреса к старшему): ");
    PrintBytes(&valFloat, sizeof(valFloat));
    printf("  От старшего байта к младшему            : ");
    PrintBytesReversed(&valFloat, sizeof(valFloat));

    printf("\n[double 12345.0]\n");
    printf("  В памяти (от младшего адреса к старшему): ");
    PrintBytes(&valDouble, sizeof(valDouble));
    printf("  От старшего байта к младшему            : ");
    PrintBytesReversed(&valDouble, sizeof(valDouble));

    // TaskHW
    printf("\nДомашнее задание\n\n");

    TYPE_SIZE(char, arr_char);
    TYPE_SIZE(short int, arr_sint);
    TYPE_SIZE(unsigned short int, arr_usint);
    TYPE_SIZE(int, arr_int);
    TYPE_SIZE(unsigned char, arr_uchar);
    TYPE_SIZE(wchar_t, arr_wchar);
    TYPE_SIZE(long long int, arr_llint);
    TYPE_SIZE(size_t, arr_sizet);
    TYPE_SIZE(float, arr_float);
    TYPE_SIZE(double, arr_double);
    TYPE_SIZE(signed int, arr_sigint);

    printf("1)  char               : %td байт\n", (char*)&arr_char[1] - (char*)&arr_char[0]);
    printf("2)  short int          : %td байт\n", (char*)&arr_sint[1] - (char*)&arr_sint[0]);
    printf("3)  unsigned short int : %td байт\n", (char*)&arr_usint[1] - (char*)&arr_usint[0]);
    printf("4)  int                : %td байт\n", (char*)&arr_int[1] - (char*)&arr_int[0]);
    printf("5)  unsigned char      : %td байт\n", (char*)&arr_uchar[1] - (char*)&arr_uchar[0]);
    printf("6)  wchar_t            : %td байт\n", (char*)&arr_wchar[1] - (char*)&arr_wchar[0]);
    printf("7)  long long int      : %td байт\n", (char*)&arr_llint[1] - (char*)&arr_llint[0]);
    printf("8)  size_t             : %td байт\n", (char*)&arr_sizet[1] - (char*)&arr_sizet[0]);
    printf("9)  float              : %td байт\n", (char*)&arr_float[1] - (char*)&arr_float[0]);
    printf("10) double             : %td байт\n", (char*)&arr_double[1] - (char*)&arr_double[0]);
    printf("11) signed int         : %td байт\n", (char*)&arr_sigint[1] - (char*)&arr_sigint[0]);

    return 0;
}


void PrintBytes(void* ptr, size_t size)
{
    unsigned char* bytePtr = (unsigned char*)ptr;
    int i;

    for (i = 0; i < (int)size; i++)
    {
        printf("%.2x ", *(bytePtr + i));
    }
    printf("\n");
}


void PrintBytesReversed(void* ptr, size_t size)
{
    unsigned char* bytePtr = (unsigned char*)ptr;
    int i;

    for (i = (int)size - 1; i >= 0; i--)
    {
        printf("%.2x ", *(bytePtr + i));
    }
    printf("\n");
}
