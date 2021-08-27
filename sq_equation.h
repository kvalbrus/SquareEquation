#ifndef SQ_EQUATION_H
#define SQ_EQUATION_H


int QuadraticEquation(double a, double b, double c, double* x1, double* x2);

int LinearEquation(double b, double c, double* x);

double Discriminant(double a, double b, double c);

bool IsNumbersMatch(double x1, double x1Ref);

bool IsNAN(double num);

const double EPSILON = 0.00000001;

enum RootsCount 
{
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,    
};

#endif //SQ_EQUATION_H