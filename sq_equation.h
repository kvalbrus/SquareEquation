#ifndef SQ_EQUATION_H
#define SQ_EQUATION_H

/*!
Solves equations with given parameters a, b, c,
\param[in] a Coefficient a
\param[in] b Coefficient b
\param[in] c Coefficient c
\param[out] x1 The first root of the equation
\param[out] x2 The second root of the equation
/return Number of roots of the equation
*/
int QuadraticEquation(double a, double b, double c, double* x1, double* x2);

/*!
Solves equations with given parameters b, c,
\param[in] b Coefficient b
\param[in] c Coefficient c
\param[out] x The root of the equation
/return Number of roots of the equation
*/
int LinearEquation(double b, double c, double* x);

/*!
Calculates the discriminant
\param[in] a Coefficient a
\param[in] b Coefficient b
\param[in] c Coefficient c
/return The discriminant
*/

double Discriminant(double a, double b, double c);

/*!
Prints the result of calculating the equation
\param[in] roots Number of roots
\param[in] x1 First root
\param[in] x2 Second root
*/
void PrintiningResponse(int roots, double x1, double x2);

/*!
Checks if two numbers are close
\param[in] num1 First number
\param[in] num2 Second number
/return True if the numbers are almost the same or the same. False if the numbers are not the same
*/
bool IsNumbersMatch(double num1, double num2);

/*!
Calculates whether a number is NUN
\param[in] num number
/return True if the numbers is NUN. False if the numbers is not NUN
*/
bool IsNAN(double num);

const double EPSILON = 0.00000001;

/// Possible number of roots of the equation
enum RootsCount 
{
    INF_ROOTS = -1, ///< An infinite number of roots
    NO_ROOTS = 0,   ///< Zero roots
    ONE_ROOT = 1,   ///< One root
    TWO_ROOTS = 2,  ///< Two roots
};

#endif //SQ_EQUATION_H