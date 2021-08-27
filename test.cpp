#include <cstdio>
#include <math.h>

#include "sq_equation.h"

/*!
Runs tests with different parameters 
\return Number of Failed Tests 
*/
int RunTestEquation();

/*!
Performs a test with the specified equation parameters
\param[in] test Test number
\param[in] a Coefficient a
\param[in] b Coefficient b
\param[in] c Coefficient c
\param[in] rootsRef Number of expected roots
\param[in] x1Ref Expected first root of the equation
\param[in] x2Ref Expected second root of the equation
\return 0 if test fails, 1 if test succeeds
*/
int TestEquation(int test, double a, double b, double c, int rootsRef, double x1Ref, double x2Ref);

/*!
Displays a message about a failed test
\param[in] test Test number
\param[in] roots Number of roots
\param[in] x1 The first root of the equation resulting from the calculation
\param[in] x1Ref The first root of the equation, which is supposed to be obtained
\param[in] x2 The second root of the equation resulting from the calculation
\param[in] x2Ref The second root of the equation, which is supposed to be obtained
*/
void TestMessage(int test, int roots, double x1, double x1Ref, double x2, double x2Ref);

int main() 
{
    int failedTest = RunTestEquation();

    printf("%d test is FAILED\n", failedTest);
}

int RunTestEquation()
{
    int failed = 0, test = 1;
    
    //                 #     a  b  c  roots      x1    x2
    if (TestEquation(test++, 1, 1, 1, NO_ROOTS,  2,    1)     == 0) failed++;
    if (TestEquation(test++, 1, 1, 1, NO_ROOTS,  NAN,  NAN)   == 0) failed++;
    if (TestEquation(test++, 2, 4, 2, ONE_ROOT,  -1,   NAN)   == 0) failed++;
    if (TestEquation(test++, 0, 0, 0, INF_ROOTS, NAN,  NAN)   == 0) failed++;
    if (TestEquation(test++, 1, 6, 9, ONE_ROOT,  -3,   1)     == 0) failed++;
    if (TestEquation(test++, 0, 0, 1, NO_ROOTS,  NAN,  NAN)   == 0) failed++;

    return failed;
}

int TestEquation(int test, double a, double b, double c, int rootsRef, double x1Ref, double x2Ref)
{
    int failed = 0;
    double x1 = NAN, x2 = NAN;
    int roots = QuadraticEquation(a, b, c, &x1, &x2);
    
    if (roots != rootsRef)
    {
        printf("Test %d FAILED! roots = %d, rootsRef = %d\n", test, roots, rootsRef);
        return 0; 
    }
    if (roots == -1) return 1;
    
    if (roots == 0)
    {
        if (!(isnan(x1) && isnan(x1Ref) && isnan(x2) && isnan(x2Ref))) 
        {
            TestMessage(test, roots, x1, x1Ref, x2, x2Ref);
            return 0;
        }
        return 1;
    }
    if (roots == 1)
    {
        if (!IsNumbersMatch(x1, x1Ref) || !isnan(x2Ref))
        {
            TestMessage(test, roots, x1, x1Ref, x2, x2Ref);
            return 0;
        }
        return 1;
    }
    
    if (!IsNumbersMatch(x1, x1Ref) || !IsNumbersMatch(x2, x2Ref))
    {
        TestMessage(test, roots, x1, x1Ref, x2, x2Ref);
        return 0;
    }

    return 1;
}

void TestMessage(int test, int roots, double x1, double x1Ref, double x2, double x2Ref)
{
    printf("Test %d FAILED! roots = %d, x1 = %lf, x1Ref = %lf, x2 = %lf, x2Ref = %lf\n", test, roots, x1, x1Ref, x2, x2Ref);
}