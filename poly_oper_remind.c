#include <stdio.h>/* Devide high oder by low oder */

int main()
{
    int i, j, m, n;

    scanf("%d", &m);
    double a[m + 1]; //Dividend
    for (i = 0; i <= m; i++)
        scanf("%lf", &a[i]);

    scanf("%d", &n);
    double b[n + 1]; //Divisor
    for (i = 0; i <= n; i++)
        scanf("%lf", &b[i]);

    double c[m - n + 1]; //Quotient
    for (i = 0; i <= m - n; i++)
        c[i] = 0;

    for (i = m - n; i >= 0; i--)
    {
        c[i] = a[n + i] / b[n];
        for (j = n; j >= 0; j--)
        {
            a[i + j] -= b[j] * c[i];//Reminder
        }
    }

    printf("Quotient is %f*x^%d", c[0], 0);
    for (i = 1; i <= m - n; i++)
        printf(" + %f*x^%d", c[i], i);
    putchar('\n');
    printf("Reminder is %f*x^%d", a[0], 0);
    for (i = 1; i <= n-1; i++)
        printf(" + %f*x^%d", a[i], i);
    return 0;
}

