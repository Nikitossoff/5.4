#include <stdio.h>
#include <locale.h>
#include "dynamic_m.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *inP = fopen("t2_P.txt", "r");
    FILE *inA = fopen("t2_A.txt", "r");
    FILE *out = fopen("output.txt", "w");

    int n;
    do {
        printf("Введите размерность N: ");
        scanf("%i", &n);
        if (n <= 1 || n > 100) {
            printf("Ошибка! N должно быть больше 1 и не больше 100.\n");
        }
    } while (n <= 1 || n > 100);

    int *P;
    int **A;
    VvodVect(&P, n, inP);
    VvodMatr(&A, n, n, inA);
    fclose(inP);
    fclose(inA);

    fprintf(out, "Массив P:\n");
    VivodVect(out, P, n);
    fprintf(out, "Матрица A:\n");
    VivodMatr(out, A, n, n);
    fprintf(out, "==================================\n");

    if (!NalSovpad(P, A, n)) {
        fprintf(out, "В P нет ни одного элемента, равного какому-либо элементу A.\n");
        float sr = SrArVect(P, n);
        fprintf(out, "Среднее арифметическое элементов P: %.2f\n", sr);
    }
    else {
        fprintf(out, "В P есть элемент, равный элементу A. Среднее арифметическое не вычисляется.\n");
    }

    OchistkaVect(&P);
    OchistkaMatr(&A, n);
    fclose(out);

    printf("Результат успешно записан в output.txt!\n");
    return 0;
}
