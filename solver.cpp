#include "solver.hpp"
#include <bits/stdc++.h>
#include <cmath>
using namespace solver;
using namespace std;

bool compare_variable_by_degree(RealVariable v1, RealVariable v2)
{
    return v1.degree > v2.degree;
}

vector<RealVariable> minimize(vector<RealVariable> vec)
{

    for (auto &var : vec)
    {
        cout << var << ", ";
    }
    cout << endl;

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

// double solver::solve(vector<RealVariable> elements)
// {
//     elements = minimize(elements);
//     for (auto &var : elements)
//     {
//         cout << var << ", ";
//     }
//     cout << endl;

//     return 0.0;
// }

double linear_solver(vector<RealVariable> elements)
{
    double result = 0;

    for (unsigned i = 0; i < elements.size(); i++)
    {
        int curr_degree = elements.at(i).degree;
        double curr_coef = elements.at(i).coefficient;

        if (curr_degree == 0)
        {
            curr_coef *= -1;
            result += curr_coef;
        }
        else
        {
            if (curr_coef != 1)
            {
                for (auto &v : elements)
                {
                    v.coefficient /= curr_coef;
                }
            }
        }
    }
    return result;
}

double solver::solve(vector<RealVariable> elements)

{

    elements = minimize(elements);
    double a, b, c;
    a = b = c = 0;
    int index = 0;
    while (index < elements.size())
    {
        RealVariable curr_element = elements.at(index);
        int element_degree = curr_element.degree;
        switch (element_degree)
        {
        case 0:

            c = curr_element.coefficient;
            cout << "c = " << c << endl;

            break;
        case 1:
            b = curr_element.coefficient;
            cout << "b = " << b << endl;

            break;
        case 2:
            a = curr_element.coefficient;
            cout << "a = " << a << endl;

            break;
        }
        index++;
    }

    if (a == 0)
    {
        return linear_solver(elements);
    }

    double discriminant = pow(b, 2) - 4 * a * c;
    double x1, x2;

    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        return x1; // check if thre is option to choose randomly;
    }

    else if (discriminant == 0)
    {
        cout << "Roots are real and same." << endl;
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << "x1 = x2 =" << x1 << endl;
        return x1;
    }
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

// vector<RealVariable> solver::operator-(RealVariable x, RealVariable x1)
// {

//     vector<RealVariable> vec;
//     vec.push_back(x);
//     x1.coefficient *= -1;
//     vec.push_back(x1);
//     return vec;
// }

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
    if (var.coefficient >= 0)
    {

        var.coefficient *= -1;
        vec.push_back(var);
    }
    else
    {
        vec.push_back(var);
    }

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
        v.coefficient /= number;
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
