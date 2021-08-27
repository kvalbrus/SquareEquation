#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>

#include "sq_equation.h"

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = NAN, x2 = NAN;

    printf("Solution of a quadratic equation\n");
    printf("a, b, c:\n");
    
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        int roots = QuadraticEquation(a, b, c, &x1, &x2);

        PrintiningResponse(roots, x1, x2);
    } 
    else 
    {
        printf("Enter only numbers!\n");
    } 
    return 0;
}