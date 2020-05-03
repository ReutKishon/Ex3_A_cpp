#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "solver.hpp"
#include <complex>
#include <math.h>

using namespace std;
using namespace solver;

TEST_CASE("basic checks 1:")
{
    RealVariable x;
    CHECK(solve((x ^ 2) == 16) == 4); 
    CHECK(solve((x ^ 2) == 9) == 3);
    CHECK(solve(x + 5 == 12) == 7);
    CHECK(solve(-2 * x + 3 == 5) == -1);
    CHECK(solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == 4);
    // CHECK(solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == -4);
    CHECK(solve(2 * x - 4.0 == 10.0) == 7);
    // CHECK(solve((x ^ 2) + 2 * x - 24) == -6);
    CHECK(solve((x ^ 2) + 2 * x - 24) == 4);
    // CHECK(solve((x ^ 2) - 5 * x - 24) == 8);
    CHECK(solve((x ^ 2) - 5 * x - 24) == -3);
    // CHECK(solve((x ^ 2) - 2 * x - 9 * x + 16 + 2) == 9);
    CHECK(solve((x ^ 2) - 2 * x - 9 * x + 16 + 2) == 2);
    CHECK(solve((x ^ 2) + 12 * x + 32) == -4);
    // CHECK(solve((x ^ 2) + 12 * x + 32) == -8);
}

// TEST_CASE("complex checks: 2:")
// {
//     ComplexVariable y;
//     CHECK(solve((y ^ 2) == 16) == 4.0 + 0i);
//     CHECK(solve((y ^ 2) == 16) == -4.0 + 0i);
//     CHECK(solve((y ^ 2) == -16) == 0.0 + 4.0i);
//     CHECK(solve((y ^ 2) == -16) == 0.0 - 4.0i);
//     CHECK(solve((y ^ 2) + 2 * y + 4 == 20 + 6 * y / 2 - y) == 4.0 + 0i);
//     CHECK(solve((y ^ 2) + 2 * y + 4 == 20 + 6 * y / 2 - y) == -4.0 + 0i);
//     CHECK(solve((y ^ 2) == 9.0 - 40.0i) == -5.0 + 4.0i);
//     CHECK(solve((y ^ 2) == 9.0 - 40.0i) == 5.0 - 4.0i);
//     CHECK(solve(-4.0 == 6.0i + 2 * y) == 0.5 - 2.5i);
//     CHECK(solve(y + 2i == 8) == 8.0 - 2.0i);
//     CHECK(solve(2.0 == 6i + 2 * y) == 1.0 - 3.0i);
// }

// TEST_CASE("3")
// {

//     ComplexVariable z;
//     CHECK(solve((z ^ 2) == 9) == 3.0 + 0i);
//     CHECK(solve((z ^ 2) == 9) == -3.0 + 0i);
//     CHECK(solve((z ^ 2) == -9) == 0.0 + 3.0i);
//     CHECK(solve((z ^ 2) == -9) == 0.0 - 3.0i);
//     CHECK(solve((z ^ 2) == 25) == 5.0 + 0i);
//     CHECK(solve((z ^ 2) == 25) == -5.0 + 0i);
//     CHECK(solve((z ^ 2) == -25) == 0.0 + 5.0i);
//     CHECK(solve((z ^ 2) == -25) == 0.0 - 5.0i);
//     CHECK(solve((z ^ 2) == 36) == 6.0 + 0i);
//     CHECK(solve((z ^ 2) == 36) == -6.0 + 0i);
//     CHECK(solve((z ^ 2) == -36) == 0.0 + 6.0i);
//     CHECK(solve((z ^ 2) == -36) == 0.0 - 6.0i);
// }

// TEST_CASE("4:")
// {

//     ComplexVariable y;
//     CHECK(solve((y ^ 2) == 4) == 2.0 + 0i);
//     CHECK(solve((y ^ 2) == 4) == -2.0 + 0i);
//     CHECK(solve((y ^ 2) == -4) == 0.0 + 2.0i);
//     CHECK(solve((y ^ 2) == -4) == 0.0 - 2.0i);
//     CHECK(solve((y ^ 2) == 1) == 1.0 + 0i);
//     CHECK(solve((y ^ 2) == 1) == -1.0 + 0i);
//     CHECK(solve((y ^ 2) == -1) == 0.0 + 1.0i);
//     CHECK(solve((y ^ 2) == -1) == 0.0 - 1.0i);
//     CHECK(solve((y ^ 2) == 49) == 7.0 + 0i);
//     CHECK(solve((y ^ 2) == 49) == -7.0 + 0i);
//     CHECK(solve((y ^ 2) == -49) == 0.0 + 7.0i);
//     CHECK(solve((y ^ 2) == -49) == 0.0 - 7.0i);
// }

TEST_CASE("5:")
{
    RealVariable x;
    CHECK(solve((x ^ 2) - 5 * x == 45) == -8.0);
    CHECK(solve((x ^ 2) - 5 * x == 45) == 5.0);
    CHECK(solve((x ^ 2) == 5 * x + 45) == 5.0);
    CHECK(solve((x ^ 2) == 5 * x + 45) == -8.0);
    CHECK(solve((x ^ 2) - 5 * x - 45 == 0) == -8.0);
    CHECK(solve((x ^ 2) - 5 * x - 45 == 0) == 5.0);
    CHECK(solve((x ^ 2) - x - 2 == 0) == 2.0);
    CHECK(solve((x ^ 2) - x - 2 == 0) == -1.0);
    CHECK(solve((x ^ 2) - x == 2) == 2.0);
    CHECK(solve((x ^ 2) - x == 2) == -1.0);
    CHECK(solve((x ^ 2) == x + 2) == -1.0);
    CHECK(solve((x ^ 2) == x + 2) == 2.0);
}

// TEST_CASE("6:")
// {
//     ComplexVariable y;

//     CHECK(solve(-10 == 6i + 2 * y) == -5.0 - 3.0i);
//     CHECK(solve(-10.0 - 6.0i == 2 * y) == -5.0 - 3.0i);
//     CHECK(solve(-10.0 - 6.0i - 2 * y == 0) == -5.0 - 3.0i);
//     CHECK(solve(6 == 6i + 2 * y) == 3.0 - 3.0i);
//     CHECK(solve(-6.0 - 6i == 2 * y) == -3.0 - 3.0i);
//     CHECK(solve(-6.0 + 2i == 6i + 2 * y) == -3.0 - 2.0i);
//     CHECK(solve(-2 * y - 6.0 + 2i == 6i) == -3.0 - 2.0i);
//     CHECK(solve(-6.0 + 2i - 6i == 2 * y) == -3.0 - 2.0i);
//     CHECK(solve(3 + y == 6i) == 6i - 3.0);
//     CHECK(solve(3 == 6i - y) == 6i - 3.0);
// }

// TEST_CASE("7:")
// {

//     ComplexVariable y;

//     CHECK(solve((y ^ 2) - 5.0 == -30.0) == 0.0 + 5.0i);
//     CHECK(solve((y ^ 2) - 5.0 == -30.0) == 0.0 - 5.0i);
//     CHECK(solve((y ^ 2) - 10.0 == -35.0) == 0.0 + 5.0i);
//     CHECK(solve((y ^ 2) - 9.0 == -58.0) == 0.0 - 7.0i);
//     CHECK(solve((y ^ 2) - 9.0 == -58.0) == 0.0 + 7.0i);
//     CHECK(solve((y ^ 2) - 3.0 - 6.0 == -58.0) == 0.0 - 7.0i);
//     CHECK(solve((y ^ 2) - 3.0 - 6.0 == -58.0) == 0.0 + 7.0i);
//     CHECK(solve(y - 9.0i == -58) == -58.0 + 9.0i);
//     CHECK(solve(y - 6.0i - 3.0i == -58) == -58.0 + 9.0i);
//     CHECK(solve(y - 8.0i - 1.0i == -58) == -58.0 + 9.0i);
// }

// TEST_CASE("8:")
// {

//     RealVariable x;

//     CHECK(solve(x * x == 0) == 0);
//     CHECK(solve(x * 2 == 2) == 1);
//     CHECK(solve(x * 4 == 2) == 0.25);
//     CHECK(solve(x * 2 == 4) == 2);
//     CHECK(solve(2 * x + 3 == 9) == 3);
//     CHECK(solve(x * x == 16) == 4.0);
//     CHECK(solve(x * x == 16) == -4.0);
//     CHECK(solve(8 * x == 24) == 3);
//     CHECK(solve(6 * x == 36) == 6);
//     CHECK(solve(12 * x == 144) == 12);
//     CHECK(solve(10 * x == 100) == 10);
//     CHECK(solve(3 * x == 9) == 3);
// }

// TEST_CASE("9:")
// {

//     ComplexVariable y1;
//     RealVariable x1;

//     CHECK(solve(2 * y1 - 6i - 3i == -20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 9i == -20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 6i == 3i - 20) == -10.0 + 4.5i);
//     CHECK(solve(-6i - 3i == -2 * y1 - 20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 6i - 3i == -20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 6i - 3i + 20 == 0) == -10.0 + 4.5i);

//     CHECK(solve(2 * y1 - 6i - 3i == -20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 9i == -20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 6i == 3i - 20) == -10.0 + 4.5i);
//     CHECK(solve(-6i - 3i == -2 * y1 - 20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 6i - 3i == -20) == -10.0 + 4.5i);
//     CHECK(solve(2 * y1 - 6i - 3i + 20 == 0) == -10.0 + 4.5i);
//     CHECK(solve((y1 ^ 2) - 5.0 == -30.0) == 0.0 - 5.0i);
//     CHECK(solve(-2 * y1 - 6.0 + 2i == 6i) == -3.0 - 2.0i);
//     CHECK(solve((y1 ^ 2) == 16) == 4.0 + 0i);
//     CHECK(solve((y1 ^ 2) == 16) == -4.0 + 0i);
//     CHECK(solve((y1 ^ 2) == 16) == 4.0 + 0i);
//     CHECK(solve((y1 ^ 2) == 16) == -4.0 + 0i);
//     CHECK(solve(-6.0 - 6i == 2 * y1) == -3.0 - 3.0i);
//     CHECK(solve(-6.0 + 2i == 6i + 2 * y1) == -3.0 - 2.0i);
//     CHECK(solve(-2 * y1 - 6.0 + 2i == 6i) == -3.0 - 2.0i);
//     CHECK(solve(-6.0 + 2i - 6i == 2 * y1) == -3.0 - 2.0i);
//     CHECK(solve(3 + y1 == 6i) == 6i - 3.0);
//     CHECK(solve(3 == 6i - y1) == 6i - 3.0);
// }
