#ifndef SOLVER_H_
#define SOLVER_H_
// #include <complex>
#include <iostream>
#include <vector>
using namespace std;

namespace solver
{
class RealVariable
{
public:
    int degree;
    double coefficient;
    RealVariable(int coef = 1, int deg = 1) : coefficient(coef), degree(deg)
    {
    }

    friend ostream &operator<<(ostream &out, const RealVariable &var);
    // friend vector<RealVariable> operator^(RealVariable x, double number);
    // friend vector<RealVariable> operator*(RealVariable x, double number);
    // friend vector<RealVariable> operator*(double number, RealVariable x);
    // friend vector<RealVariable> operator+(vector<RealVariable> vec1, vector<RealVariable> vec2);
    // friend vector<RealVariable> operator-(vector<RealVariable> vec1, vector<RealVariable> vec2);
    // friend vector<RealVariable> operator-(RealVariable var, double number);
    // friend vector<RealVariable> operator-(vector<RealVariable> vec, double number);
    // friend vector<RealVariable> operator==(vector<RealVariable> vec, double number);
    // friend vector<RealVariable> operator==(vector<RealVariable> vec, vector<RealVariable> vec2);
};
vector<RealVariable> operator^(vector<RealVariable> vec, double number);
vector<RealVariable> operator^(RealVariable x, double number);
vector<RealVariable> operator*(RealVariable x, double number);
vector<RealVariable> operator*(double number, RealVariable x);
vector<RealVariable> operator+(vector<RealVariable> vec1, vector<RealVariable> vec2);
vector<RealVariable> operator+(RealVariable var, double number);
vector<RealVariable> operator+(double number, RealVariable var);
vector<RealVariable> operator+(vector<RealVariable> vec, double number);
vector<RealVariable> operator+(double number, vector<RealVariable> vec);
vector<RealVariable> operator-(vector<RealVariable> vec1, vector<RealVariable> vec2);
vector<RealVariable> operator-(RealVariable var, double number);
vector<RealVariable> operator-(vector<RealVariable> vec, double number);
vector<RealVariable> operator-(vector<RealVariable> vec, RealVariable var);
vector<RealVariable> operator/(RealVariable var, int number);
vector<RealVariable> operator/(vector<RealVariable> vec, int number);
vector<RealVariable> operator==(vector<RealVariable> vec, RealVariable v);
vector<RealVariable> operator==(vector<RealVariable> vec, double number);
vector<RealVariable> operator==(vector<RealVariable> vec, vector<RealVariable> vec2);
double solve(vector<RealVariable> elements);

} // namespace solver

#endif