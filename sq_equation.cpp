#include <cstdio>
#include <cassert>
#include <math.h>
#include <cfloat>

#include "sq_equation.h"

RootsCount SolvesQuadraticEquation(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    
    if (IsEqual(a, 0)) 
    {
        return SolvesLinearEquation(b, c, x1);
    } 
    
    double discriminant = CountDiscriminant(a, b, c);

    if (IsEqual(discriminant, 0)) 
    {
        *x1 = -b / (2 * a);

        return ONE_ROOT;
    }

    if (discriminant > 0) 
    {
        *x1 = (-b + sqrt(discriminant)) / (2 * a);
        *x2 = (-b - sqrt(discriminant)) / (2 * a);
            
        return TWO_ROOTS;
    } 
     
    return NO_ROOTS;
}

RootsCount SolvesLinearEquation(double b, double c, double* x)
{
    assert(x != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (IsEqual(b, 0))
    {
        if (IsEqual(c, 0))
        {
            return INF_ROOTS;
        } 
        
        return NO_ROOTS;
    } 
    
    *x =  - c / b;
    
    return ONE_ROOT;
}

void PrintResponse(RootsCount roots, double x1, double x2)
{
    assert(x1 != x2);

    switch (roots)
    {
        case INF_ROOTS:
            printf("Infinity roots\n");
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
            printf("Error! Invalid roots!");
            break;
    }
}

double CountDiscriminant(double a, double b, double c)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    return ((b * b) - (4 * a * c));
}

bool IsEqual(double num1, double num2)
{
    return (fabs(num1 - num2) < DBL_EPSILON);
}