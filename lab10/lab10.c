#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double fa(double x) {
    double y;
    if (x <= 3) {
        y = x * x - 3 * x + 9;
    }
    else {
        y = 1.0 / (x * x * x + 3);
    }
    return y;
}

double fb(double x) {
    return x * exp(sin(x * x));
}

void zadanie1(void) {
    printf("\n Задание 1\n");
    double x, val_a, val_b;
    int choice;

    do {
        printf("\n1 - fa(x) и fb(x)\n");
        printf("2 - произведение, разность квадратов, удвоенная сумма\n");
        printf("0 - Назад\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Введите x: ");
            scanf("%lf", &x);
            val_a = fa(x);
            val_b = fb(x);
        }

        if (choice == 1) {
            printf("fa(x) = %lf, fb(x) = %lf\n", val_a, val_b);
        }
        else if (choice == 2) {
            printf("Произведение: %lf\n", val_a * val_b);
            printf("Разность квадратов: %lf\n", val_a * val_a - val_b * val_b);
            printf("Удвоенная сумма: %lf\n", 2 * (val_a + val_b));
        }
    } while (choice != 0);
}

double sin_x_div_x_standard(double x) {
    if (x == 0) return 1.0;
    return sin(x) / x;
}

double sin_x_div_x_n(double x, int N) {
    double sum = 1.0;
    double term = 1.0;
    if (N < 1) N = 1;
    for (int k = 1; k <= N; k++) {
        term = term * (-x * x) / ((2 * k) * (2 * k + 1));
        sum += term;
    }
    return sum;
}

double sin_x_div_x_eps(double x, double eps) {
    double sum = 1.0;
    double term = 1.0;
    int k = 1;
    if (eps <= 0) eps = 1e-9;
    do {
        term = term * (-x * x) / ((2 * k) * (2 * k + 1));
        sum += term;
        k++;
    } while (fabs(term) > eps);
    return sum;
}

void zadanie2(void) {
    printf("\n Задание 2\n");
    double x, eps, res_std, res_n, res_eps;
    int N;

    printf("Введите x: ");
    scanf("%lf", &x);
    printf("Введите N: ");
    scanf("%d", &N);
    printf("Введите eps: ");
    scanf("%lf", &eps);

    res_std = sin_x_div_x_standard(x);
    res_n = sin_x_div_x_n(x, N);
    res_eps = sin_x_div_x_eps(x, eps);

    printf("Стандартная: %lf\n", res_std);
    printf("Ряд (N): %lf\n", res_n);
    printf("Ряд (eps): %lf\n", res_eps);
    printf("Отклонение (N): %lf\n", fabs(res_std - res_n));
    printf("Отклонение (eps): %lf\n", fabs(res_std - res_eps));
}

int main(void) {
    setlocale(LC_ALL, "RUS");
    zadanie1();
    zadanie2();
    return 0;
}
