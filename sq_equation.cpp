#include <cstdio>
#include <cassert>
#include <math.h>

#include "sq_equation.h"

int QuadraticEquation(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (IsNumbersMatch(a, 0)) 
    {
        return LinearEquation(b, c, x1);
    } 
    else 
    {
        double discriminant = Discriminant(a, b, c);

        if (IsNumbersMatch(discriminant, 0)) 
        {
            *x1 = -b / (2 * a);

            return ONE_ROOT;
        } 
        else if (discriminant > 0) 
        {
            *x1 = (-b + sqrt(discriminant)) / (2 * a);
            *x2 = (-b - sqrt(discriminant)) / (2 * a);
            
            return TWO_ROOTS;
        } 
        else 
        {
            return NO_ROOTS;
        }
    }
}

int LinearEquation(double b, double c, double* x)
{
    assert(x != NULL);

    if (IsNumbersMatch(b, 0))
    {
        if (IsNumbersMatch(c, 0))
        {
            return INF_ROOTS;
        } 
        else 
        {
            return NO_ROOTS;
        }    
    } 
    else 
    {
        *x =  - c / b;
        return ONE_ROOT;
    }
}

void PrintiningResponse(int roots, double x1, double x2)
{
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
            break;
        }
}

double Discriminant(double a, double b, double c)
{
    return ((b * b) - (4 * a * c));
}

bool IsNumbersMatch(double num1, double num2)
{
    return (fabs(num1 - num2) < EPSILON);
}