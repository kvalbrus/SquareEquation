#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>

#include "sq_equation.h"

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = NAN, x2 = NAN;
    int roots;

    printf("Solution of a quadratic equation\n");
    printf("a, b, c:\n");
    
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        roots = QuadraticEquation(a, b, c, &x1, &x2);

        switch (roots)
        {
        case INF_ROOTS:
            printf("Endless roots\n");
            break;
        case NO_ROOTS:
            printf("0 roots\n");
            break;
        case ONE_ROOT:
            printf("1 root:\nx = %lf\n", x1);
            break;
        case TWO_ROOTS:
            printf("2 roots:\nx1 = %lf\nx2 = %lf\n", x1, x2);
            break;
        default:
            break;
        }
    } 
    else 
    {
        printf("Enter only numbers!\n");
    } 
    return 0;
}