#include "solver.hpp"
#include <bits/stdc++.h>
using namespace solver;
using namespace std;

bool compare_variable_by_degree(RealVariable v1, RealVariable v2)
{
    return v1.degree > v2.degree;
}

vector<RealVariable> minimize(vector<RealVariable> vec)
{
    sort(vec.begin(), vec.end(), compare_variable_by_degree);
    int degree = vec.front().degree;
    int current_degree = 0;
    double coef = vec.front().coefficient;
    vector<RealVariable> new_vec;
    for (unsigned i = 1; i < vec.size(); i++)
    {
        current_degree = vec.at(i).degree;
        if (current_degree == degree)
        {
            coef += vec.at(i).coefficient;
            if (i == (vec.size() - 1))

            {
                RealVariable new_element(coef, degree);
                new_vec.push_back(new_element);
            }
        }
        else
        {
            RealVariable new_element(coef, degree);
            new_vec.push_back(new_element);
            degree = vec.at(i).degree;
            coef = vec.at(i).coefficient;
            if (i == (vec.size() - 1))

            {
                RealVariable new_element(coef, degree);
                new_vec.push_back(new_element);
            }
        }
    }
    return new_vec;
}

double solver::solve(vector<RealVariable> elements)
{
    elements = minimize(elements);
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

vector<RealVariable> solver::operator*(RealVariable x1, RealVariable x)
{

    if (x.degree + x1.degree < 3)
    {
        vector<RealVariable> vec;
        x1.degree += x.degree;
        vec.push_back(x1);
        return vec;
    }
    throw("the degree is greater than 2!");
}

vector<RealVariable> solver::operator^(vector<RealVariable> vec, double number)
{

    for (auto &v : vec)
    {
        if (v.degree *= number < 2)
            v.degree *= number;
        else
        {
            throw("degree is greater than 2!");
        }
    }

    return vec;
}

vector<RealVariable> solver::operator^(RealVariable x, double number)
{
    if (number > 2)
    {
        throw("degree is greater than 2!");
    }
    x.degree = number;
    vector<RealVariable> vec;
    vec.push_back(x);
    return vec;
}

vector<RealVariable> solver::operator+(vector<RealVariable> vec1, vector<RealVariable> vec2)
{
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

vector<RealVariable> solver::operator+(RealVariable var, double number)
{
    vector<RealVariable> vec;
    RealVariable var2(number, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<RealVariable> solver::operator+(double number, RealVariable var)
{
    vector<RealVariable> vec;
    RealVariable var2(number, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<RealVariable> solver::operator+(vector<RealVariable> vec, double number)
{
    RealVariable var2(number, 0);

    vec.push_back(var2);

    return vec;
}

vector<RealVariable> solver::operator+(double number, vector<RealVariable> vec)
{
    RealVariable var2(number, 0);

    vec.push_back(var2);

    return vec;
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

vector<RealVariable> solver::operator-(vector<RealVariable> vec, RealVariable var)
{
    var.coefficient *= -1;
    vec.push_back(var);
    return vec;
}

vector<RealVariable> solver::operator/(RealVariable var, int number)
{
    var.coefficient /= 2;
    vector<RealVariable> vec;
    vec.push_back(var);
    return vec;
}

vector<RealVariable> solver::operator/(vector<RealVariable> vec, int number)
{
    for (auto &v : vec)
    {
        v.coefficient /= 2;
    }

    return vec;
}

vector<RealVariable> solver::operator==(vector<RealVariable> vec, RealVariable v)
{
    v.coefficient *= -1;
    vec.push_back(v);

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
