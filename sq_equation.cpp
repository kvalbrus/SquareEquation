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

double Discriminant(double a, double b, double c)
{
    return ((b * b) - (4 * a * c));
}

bool IsNumbersMatch(double num1, double num2)
{
    return (fabs(num1 - num2) < EPSILON);
}

bool IsNAN(double num)
{
    return (num != num);
}