#include "solver.hpp"
// #include <complex>
using namespace solver;
using namespace std;

double solver::solve(vector<RealVariable> elements)
{

    for (auto &var : elements)
    {
        cout << var << ", ";
    }
    cout << endl;

    return 0.0;
}

ostream &solver::operator<<(ostream &out, const solver::RealVariable &var)
{
    out << var.coefficient;
    if (var.degree > 0)
    {
        out << "x^" << var.degree;
    }

    out << " ";
    return out;
}

vector<RealVariable> solver::operator*(RealVariable x, double number)
{
    x.coefficient *= number;
    auto vec = vector<RealVariable>();
    vec.push_back(x);
    return vec;
}

vector<RealVariable> solver::operator*(double number, RealVariable x)
{
    x.coefficient *= number;
    vector<RealVariable> vec;
    vec.push_back(x);
    return vec;
}

vector<RealVariable> solver::operator^(RealVariable x, double number)
{
    x.degree *= number;
    vector<RealVariable> vec;
    vec.push_back(x);
    return vec;
}

vector<RealVariable> solver::operator+(vector<RealVariable> vec1, vector<RealVariable> vec2)
{
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

vector<RealVariable> solver::operator-(vector<RealVariable> vec1, vector<RealVariable> vec2)
{

    for (auto var : vec2)
    {
        var.coefficient *= -1;
    }

    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

vector<RealVariable> solver::operator-(RealVariable var, double number)
{
    vector<RealVariable> vec;
    RealVariable var2(-number, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<RealVariable> solver::operator-(vector<RealVariable> vec, double number)
{
    RealVariable var2(-number, 0);

    vec.push_back(var2);

    return vec;
}

vector<RealVariable> solver::operator==(vector<RealVariable> vec, double number)
{
    RealVariable var2(-number, 0);

    vec.push_back(var2);

    return vec;
}

vector<RealVariable> solver::operator==(vector<RealVariable> vec, vector<RealVariable> vec2)
{

    for (auto &v : vec2)
    {
        v.coefficient *= -1;
        vec.push_back(v);
    }
    return vec;
}

