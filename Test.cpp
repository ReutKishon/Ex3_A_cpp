#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "solver.hpp"

using namespace std;
using namespace solver;

TEST_CASE("basic checks:")
{
    RealVariable x;
    CHECK(solve((x ^ 2 == 0) - 16) == 4);
    CHECK(solve((x ^ 2) == 9) == 3);
    CHECK(solve(x + 5 == 12) == 7);
    CHECK(solve(2 * x + 3 == 5) == 1);
    CHECK((solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == 4 || solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == -4));
    CHECK(solve(2 * x - 4.0 == 10.0) == 7);
    CHECK((solve((x ^ 2) + 2 * x - 24) == -6 || solve((x ^ 2) + 2 * x - 24) == 4));
    CHECK((solve((x ^ 2) - 5 * x - 24) == 8 || solve((x ^ 2) - 5 * x - 24) == -3));
    CHECK((solve((x ^ 2) - 2 * x - 9 * x + 16 + 2) == 9 || solve((x ^ 2) - 2 * x - 9 * x + 16 + 2) == 2));
    CHECK((solve((x ^ 2) + 12 * x + 32) == -4 || solve((x ^ 2) + 12 * x + 32) == -8));
}

// TEST_CASE(" ")