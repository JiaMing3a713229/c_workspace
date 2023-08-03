#include <stdio.h>

// 函數用於執行多項式除法，並將結果存儲在指定的陣列中
void polynomial_division(int dividend[], int dividend_degree, int divisor[], int divisor_degree, int quotient[], int remainder[]) {
    int i, j;

    // 初始化商的陣列為0
    for (i = 0; i < dividend_degree - divisor_degree + 1; i++) {
        quotient[i] = 0;
    }

    // 執行多項式除法
    for (i = 0; i <= dividend_degree - divisor_degree; i++) {
        quotient[i] = dividend[i] / divisor[0];

        for (j = 0; j <= divisor_degree; j++) {
            dividend[i + j] -= quotient[i] * divisor[j];
        }
    }

    // 將剩餘的項存儲在餘式陣列中
    for (i = 0; i <= dividend_degree; i++) {
        remainder[i] = dividend[i];
    }
}

// 函數用於顯示多項式
void display_polynomial(int coefficients[], int degree) {
    int i;
    for (i = degree; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (i != degree) {
                printf(" + ");
            }
            printf("%dx^%d", coefficients[i], i);
        }
    }
    printf("\n");
}

int main() {
    int dividend_coefficients[] = {2, 3, -6, 5};
    int dividend_degree = 3;
    int divisor_coefficients[] = {1, -2};
    int divisor_degree = 1;

    int quotient[dividend_degree - divisor_degree + 1];
    int remainder[dividend_degree + 1];

    // 執行多項式除法
    polynomial_division(dividend_coefficients, dividend_degree, divisor_coefficients, divisor_degree, quotient, remainder);

    printf("Dividend: ");
    display_polynomial(dividend_coefficients, dividend_degree);

    printf("Divisor: ");
    display_polynomial(divisor_coefficients, divisor_degree);

    printf("Quotient: ");
    display_polynomial(quotient, dividend_degree - divisor_degree);

    printf("Remainder: ");
    display_polynomial(remainder, dividend_degree);

    return 0;
}
