#ifndef SQ_EQUATION_H
#define SQ_EQUATION_H

/// Possible number of roots of the equation
enum RootsCount 
{
    INF_ROOTS = -1, ///< An infinite number of roots
    NO_ROOTS = 0,   ///< Zero roots
    ONE_ROOT = 1,   ///< One root
    TWO_ROOTS = 2,  ///< Two roots
};

/*!
Solves equations with given parameters a, b, c,
\param[in] a Coefficient a
\param[in] b Coefficient b
\param[in] c Coefficient c
\param[out] x1 The first root of the equation
\param[out] x2 The second root of the equation
/return Number of roots of the equation
*/
RootsCount SolvesQuadraticEquation(double a, double b, double c, double* x1, double* x2);

/*!
Solves equations with given parameters b, c,
\param[in] b Coefficient b
\param[in] c Coefficient c
\param[out] x The root of the equation
/return Number of roots of the equation
*/
RootsCount SolvesLinearEquation(double b, double c, double* x);

/*!
Calculates the discriminant
\param[in] a Coefficient a
\param[in] b Coefficient b
\param[in] c Coefficient c
/return The discriminant
*/
double CountDiscriminant(double a, double b, double c);

/*!
Prints the result of calculating the equation
\param[in] roots Number of roots
\param[in] x1 First root
\param[in] x2 Second root
*/
void PrintResponse(RootsCount rooots, double x1, double x2);

/*!
Checks if two numbers are close
\param[in] num1 First number
\param[in] num2 Second number
/return True if the numbers are almost the same or the same. False if the numbers are not the same
*/
bool IsEqual(double num1, double num2);


#endif //SQ_EQUATION_H