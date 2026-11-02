#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double area_triangle(double R) {
    return R * R;
}

double get_radius(void) {
    double r;
    printf("Введите радиус описанной окружности R: ");
    scanf("%lf", &r);
    return r;
}

void draw_triangle(int R, char symbol) {
    int height = R * 2;
    if (height < 2) height = 2;

    printf("\nРисунок фигуры:\n");
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == height) {
                printf("%c", symbol);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

double compare_triangle(double R1, double R2) {
    return area_triangle(R1) - area_triangle(R2);
}

void zadanie3(void) {
    int choice;
    double R = 0, R2 = 0;
    int has_figure = 0;

    do {
        printf("\n--- Меню (Задание 3) ---\n");
        printf("1 - Рассчитать площадь\n");
        printf("2 - Вывести определение фигуры (радиус)\n");
        printf("3 - Нарисовать фигуру\n");
        printf("4 - Сравнить две фигуры по площади\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (!has_figure) {
                R = get_radius();
                has_figure = 1;
            }
            printf("Площадь треугольника: %.2lf\n", area_triangle(R));
            break;
        case 2:
            if (!has_figure) {
                R = get_radius();
                has_figure = 1;
            }
            printf("Определение фигуры:\n");
            printf("Прямоугольный треугольник, вписанный в окружность.\n");
            printf("Радиус описанной окружности R = %.2lf\n", R);
            printf("Гипотенуза (диаметр) c = %.2lf\n", 2 * R);
            break;
        case 3:
            if (!has_figure) {
                R = get_radius();
                has_figure = 1;
            }
            draw_triangle((int)R, '*');
            break;
        case 4:
            if (!has_figure) {
                R = get_radius();
                has_figure = 1;
            }
            printf("Введите радиус R2 для второй фигуры: ");
            scanf("%lf", &R2);
            double diff = compare_triangle(R, R2);
            if (diff > 0) printf("Первая фигура больше второй на %.2lf\n", diff);
            else if (diff < 0) printf("Вторая фигура больше первой на %.2lf\n", -diff);
            else printf("Площади фигур равны.\n");
            break;
        case 0:
            printf("Выход из задания 3.\n");
            break;
        default:
            printf("Неверный выбор.\n");
        }
    } while (choice != 0);
}

int main(void) {
    setlocale(LC_ALL, ".UTF-8");
    zadanie3();
    return 0;
}