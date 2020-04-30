#include "solver.hpp"
#include <bits/stdc++.h>
#include <complex>
using namespace solver;
using namespace std;

// complex methods

bool compare_variable_by_degree(ComplexVariable v1, ComplexVariable v2)
{
    return v1.degree > v2.degree;
}

vector<ComplexVariable> minimize(vector<ComplexVariable> vec)
{
    sort(vec.begin(), vec.end(), compare_variable_by_degree);
    int degree = vec.front().degree;
    int current_degree = 0;
    double coef = vec.front().coefficient;
    vector<ComplexVariable> new_vec;
    for (unsigned i = 1; i < vec.size(); i++)
    {
        current_degree = vec.at(i).degree;
        if (current_degree == degree)
        {
            coef += vec.at(i).coefficient;
            if (i == (vec.size() - 1))

            {
                ComplexVariable new_element(coef, degree);
                new_vec.push_back(new_element);
            }
        }
        else
        {
            ComplexVariable new_element(coef, degree);
            new_vec.push_back(new_element);
            degree = vec.at(i).degree;
            coef = vec.at(i).coefficient;
            if (i == (vec.size() - 1))

            {
                ComplexVariable new_element(coef, degree);
                new_vec.push_back(new_element);
            }
        }
    }
    return new_vec;
}

std::complex<double> solver::solve(vector<ComplexVariable> elements)
{
    elements = minimize(elements);
    for (auto &var : elements)
    {
        cout << var << ", ";
    }
    cout << endl;

    return 0.0;
}

ostream &solver::operator<<(ostream &out, const solver::ComplexVariable &var)
{
    out << var.coefficient;
    if (var.degree > 0)
    {
        out << "y^" << var.degree;
    }
    out << "+" << var.imag_coeffient << "i";

    out << " ";
    return out;
}

vector<ComplexVariable> solver::operator*(ComplexVariable x, double number)
{
    x.coefficient *= number;
    auto vec = vector<ComplexVariable>();
    vec.push_back(x);
    return vec;
}

vector<ComplexVariable> solver::operator*(double number, ComplexVariable x)
{
    x.coefficient *= number;
    vector<ComplexVariable> vec;
    vec.push_back(x);
    return vec;
}

vector<ComplexVariable> solver::operator*(ComplexVariable y1, ComplexVariable y)
{

    if (y.degree + y1.degree < 3)
    {
        vector<ComplexVariable> vec;
        y1.degree += y.degree;
        vec.push_back(y1);
        return vec;
    }
    throw("the degree is greater than 2!");
}

vector<ComplexVariable> solver::operator^(vector<ComplexVariable> vec, double number)
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

vector<ComplexVariable> solver::operator^(ComplexVariable x, double number)
{
    if (number > 2)
    {
        throw("degree is greater than 2!");
    }
    x.degree = number;
    vector<ComplexVariable> vec;
    vec.push_back(x);
    return vec;
}

vector<ComplexVariable> solver::operator+(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2)
{
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

vector<ComplexVariable> solver::operator+(ComplexVariable var, double number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(number, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(double number, ComplexVariable var)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(number, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(ComplexVariable var, complex<double> number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(real(number), 0, imag(number));

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(complex<double> number, ComplexVariable var)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(real(number), 0, imag(number));

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(vector<ComplexVariable> vec, double number)
{
    ComplexVariable var2(number, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(vector<ComplexVariable> vec, complex<double> number)
{
    ComplexVariable var2(real(number), 0, imag(number));
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(double number, vector<ComplexVariable> vec)
{
    ComplexVariable var2(number, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(complex<double> number, vector<ComplexVariable> vec)
{
    ComplexVariable var2(real(number), 0, imag(number));
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator-(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2)
{

    for (auto var : vec2)
    {
        var.coefficient *= -1;
    }

    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

vector<ComplexVariable> solver::operator-(ComplexVariable var, double number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(-1 * number, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator-(vector<ComplexVariable> vec, double number)
{
    ComplexVariable var2(-1 * number, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator-(vector<ComplexVariable> vec, ComplexVariable var)
{
    var.coefficient *= -1;
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator-(complex<double> c, vector<ComplexVariable> vec)
{
    ComplexVariable var(real(c), 0, imag(c));
    vec.push_back(var);

    for (auto v : vec)
    {
        v.coefficient *= -1;
    }
    return vec;
}

vector<ComplexVariable> solver::operator-(vector<ComplexVariable> vec, complex<double> c)
{
    ComplexVariable var(-1 * real(c), 0, imag(c));
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator-(complex<double> c, ComplexVariable y)
{
    vector<ComplexVariable> vec;
    ComplexVariable var(real(c), 0, imag(c));
    y.coefficient *= -1;
    vec.push_back(var);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator-(ComplexVariable y, complex<double> c)
{
    vector<ComplexVariable> vec;
    ComplexVariable var(-1 * real(c), 0, imag(c));
    vec.push_back(var);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator/(ComplexVariable var, int number)
{
    var.coefficient /= 2;
    vector<ComplexVariable> vec;
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator/(vector<ComplexVariable> vec, int number)
{
    for (auto &v : vec)
    {
        v.coefficient /= 2;
    }

    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, ComplexVariable v)
{
    v.coefficient *= -1;
    vec.push_back(v);

    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, double number)
{
    ComplexVariable var2(-1 * number, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, vector<ComplexVariable> vec2)
{

    for (auto &v : vec2)
    {
        v.coefficient *= -1;
        vec.push_back(v);
    }
    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, complex<double> c)
{
    ComplexVariable var(real(c), 0, imag(c));
    vec.push_back(var);

    return vec;
}

vector<ComplexVariable> solver::operator==(double number, vector<ComplexVariable> vec)
{

    ComplexVariable var2(-1 * number, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator==(complex<double> c, vector<ComplexVariable> vec)
{

    ComplexVariable var(real(c), 0, imag(c));
    vec.push_back(var);
    return vec;
}
