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
\param[in] rootsExpected Number of expected roots
\param[in] x1Expected Expected first root of the equation
\param[in] x2Expected Expected second root of the equation
\return 0 if test fails, 1 if test succeeds
*/
int TestEquation(int test, double a, double b, double c, int rootsExpected, double x1Expected, double x2Expected);

/*!
Displays a message about a failed test
\param[in] test Test number
\param[in] roots Number of roots
\param[in] x1 The first root of the equation resulting from the calculation
\param[in] x1Expected The first root of the equation, which is supposed to be obtained
\param[in] x2 The second root of the equation resulting from the calculation
\param[in] x2Expected The second root of the equation, which is supposed to be obtained
*/
void TestMessage(int test, RootsCount roots, double x1, double x1Expected, double x2, double x2Expected);

int main() 
{
    int failedTest = RunTestEquation();

    printf("%d test is FAILED\n", failedTest);
}

int RunTestEquation()
{
    int failed = 0, test = 1;
    
    //                 #     a    b    c  roots      x1    x2
    if (TestEquation(test++, 1,   1,   1, NO_ROOTS,  NAN,  NAN)        == 0)   failed++;
    if (TestEquation(test++, 1,   1,   1, NO_ROOTS,  NAN,  NAN)        == 0)   failed++;
    if (TestEquation(test++, 2,   4,   2, ONE_ROOT,  -1,   NAN)        == 0)   failed++;
    if (TestEquation(test++, 0,   0,   0, INF_ROOTS, NAN,  NAN)        == 0)   failed++;
    if (TestEquation(test++, 1,   6,   9, ONE_ROOT,  -3,   NAN)        == 0)   failed++;
    if (TestEquation(test++, 0,   0,   1, NO_ROOTS,  NAN,  NAN)        == 0)   failed++;

    return failed;
}

int TestEquation(int test, double a, double b, double c, int rootsExpected, double x1Expected, double x2Expected)
{
    int failed = 0;
    double x1 = NAN, x2 = NAN;
    RootsCount roots = SolvesQuadraticEquation(a, b, c, &x1, &x2);
    
    if (roots != rootsExpected)
    {
        printf("Test %d FAILED! roots = %d, rootsExpected = %d\n", test, roots, rootsExpected);
        
        return 0; 
    }

    if (roots == INF_ROOTS) 
    {
        return 1;
    }

    if (roots == NO_ROOTS)
    {
        if (!(isnan(x1) && isnan(x1Expected) && isnan(x2) && isnan(x2Expected))) 
        {
            TestMessage(test, roots, x1, x1Expected, x2, x2Expected);

            return 0;
        }

        return 1;
    }

    if (roots == ONE_ROOT)
    {
        if (!IsEqual(x1, x1Expected) || !isnan(x2Expected))
        {
            TestMessage(test, roots, x1, x1Expected, x2, x2Expected);

            return 0;
        }

        return 1;
    }
    
    if (!IsEqual(x1, x1Expected) || !IsEqual(x2, x2Expected))
    {
        TestMessage(test, roots, x1, x1Expected, x2, x2Expected);

        return 0;
    }

    return 1;
}

void TestMessage(int test, RootsCount roots, double x1, double x1Expected, double x2, double x2Expected)
{
    printf("Test %d FAILED! roots = %d, x1 = %lf, x1Expected = %lf, x2 = %lf, x2Expected = %lf\n", test, roots, x1, x1Expected, x2, x2Expected);
}