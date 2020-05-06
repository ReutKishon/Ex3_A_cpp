#include "solver.hpp"
#include <bits/stdc++.h>
#include <complex>
using namespace solver;
using namespace std;


bool compare_variable_by_degree(ComplexVariable v1, ComplexVariable v2)
{
    return v1.degree > v2.degree;
}

vector<ComplexVariable> minimize(vector<ComplexVariable> vec)
{

    sort(vec.begin(), vec.end(), compare_variable_by_degree);
    int degree = vec.front().degree;
    double coef = vec.front().coefficient;
    double imag_coef = vec.front().imag_coeffient;
    int current_degree = 0;

    vector<ComplexVariable> new_vec;

    for (auto &var : vec)
    {
        cout << var << ", ";
    }
    cout << endl;

    for (unsigned i = 1; i < vec.size(); i++)
    {
        current_degree = vec.at(i).degree;
        if (current_degree == degree)
        {
            coef += vec.at(i).coefficient;
            imag_coef += vec.at(i).imag_coeffient;
            if (i == (vec.size() - 1))

            {
                ComplexVariable new_element(coef, degree, imag_coef);
                new_vec.push_back(new_element);
            }
        }
        else
        {
            ComplexVariable new_element(coef, degree, imag_coef);
            new_vec.push_back(new_element);
            degree = vec.at(i).degree;
            coef = vec.at(i).coefficient;
            imag_coef = vec.at(i).imag_coeffient;
            if (i == (vec.size() - 1))

            {

                ComplexVariable new_element(coef, degree, imag_coef);
                new_vec.push_back(new_element);
            }
        }
    }

    for (auto &var : new_vec)
    {
        cout << var << ", ";
    }
    cout << endl;

    return new_vec;
}

complex<double> linear_solver(vector<ComplexVariable> elements)
{
    complex<double> result(0, 0);
    double result_coef;
    double result_imag_coef;

    for (unsigned i = 0; i < elements.size(); i++)
    {
        int curr_degree = elements.at(i).degree;
        double curr_coef = elements.at(i).coefficient;
        double curr_imag_coef = elements.at(i).imag_coeffient;

        if (curr_degree == 0)
        {

            result.real(-curr_coef);
            result.imag(-curr_imag_coef);
        }
        else
        {
            if (curr_coef != 1 && curr_degree == 1)
            {
                for (auto &v : elements)
                {
                    v.coefficient /= curr_coef;
                    v.imag_coeffient /= curr_coef;
                }
            }
        }
    }
    cout << "x1 = " << result << endl;

    return result;
}

std::complex<double> solver::solve(vector<ComplexVariable> elements)
{

    elements = minimize(elements);
    double a, b, c;
    a = b = c = 0;
    int index = 0;
    while (index < elements.size())
    {
        ComplexVariable curr_element = elements.at(index);
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

    complex<double> x1;
    complex<double> x2;
    float discriminant, realPart, imaginaryPart;

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        x1.real((-b + sqrt(discriminant)) / (2 * a));
        x1.imag(0);
        x2.real((-b - sqrt(discriminant)) / (2 * a));
        x2.imag(0);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        return x1;
    }

    else if (discriminant == 0)
    {
        x1.real((-b + sqrt(discriminant)) / (2 * a));
        x1.imag(0);
        cout << "x1 = x2 =" << x1 << endl;
        return x1;
    }

    else
    {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        x1.real(realPart);
        x1.imag(imaginaryPart);
        x2.real(realPart);
        x2.imag(-imaginaryPart);
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
        return x2;
    }
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
    auto vec = vector<ComplexVariable>();
    vec.push_back(x);
    return vec;
}

vector<ComplexVariable> solver::operator*(ComplexVariable y1, ComplexVariable y)
{

    if (y.degree + y1.degree < 3)
    {
        auto vec = vector<ComplexVariable>();
        y1.degree += y.degree;
        vec.push_back(y1);
        return vec;
    }
    throw("the degree is greater than 2!");
}

// vector<ComplexVariable> solver::operator^(vector<ComplexVariable> vec, double number)
// {

//     for (auto &v : vec)
//     {
//         if (v.degree *= number < 2)
//             v.degree *= number;
//         else
//         {
//             throw("degree is greater than 2!");
//         }
//     }

//     return vec;
// }

vector<ComplexVariable> solver::operator^(ComplexVariable x, double number)
{
    if (x.degree * number < 3)
    {
        auto vec = vector<ComplexVariable>();
        x.degree *= number;
        vec.push_back(x);
        return vec;
    }
    throw("the degree is greater than 2!");
}

vector<ComplexVariable> solver::operator+(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2)
{
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

vector<ComplexVariable> solver::operator+(ComplexVariable var, double number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(number, 0, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(double number, ComplexVariable var)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(number, 0, 0);

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
    ComplexVariable var2(number, 0, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(double number, vector<ComplexVariable> vec)
{
    ComplexVariable var2(number, 0, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator+(vector<ComplexVariable> vec, complex<double> number)
{
    ComplexVariable var2(real(number), 0, imag(number));
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

    for (auto &var : vec2)
    {
        var.coefficient *= -1;
        var.imag_coeffient *= -1;
    }

    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

vector<ComplexVariable> solver::operator-(vector<ComplexVariable> vec, double number)
{
    ComplexVariable var(-number, 0, 0);
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator-(ComplexVariable var, double number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var2(-1 * number, 0, 0);

    vec.push_back(var);
    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator-(double number, ComplexVariable y)
{
    vector<ComplexVariable> vec;
    ComplexVariable var1(number, 0, 0);
    y.coefficient *= -1;
    y.imag_coeffient *= -1;
    vec.push_back(var1);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator-(vector<ComplexVariable> vec, ComplexVariable var) //////
{
    var.coefficient *= -1;
    var.imag_coeffient *= -1;
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator-(complex<double> c, vector<ComplexVariable> vec)
{
    ComplexVariable var(real(c), 0, imag(c));

    for (auto &v : vec)
    {
        v.coefficient *= -1;
    }
    vec.push_back(var);

    return vec;
}

vector<ComplexVariable> solver::operator-(vector<ComplexVariable> vec, complex<double> c)
{
    ComplexVariable var(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator-(double number, complex<double> c)
{

    vector<ComplexVariable> vec;
    ComplexVariable var1(number, 0, 0);
    ComplexVariable var2(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var1);
    vec.push_back(var2);
    return vec;
}

vector<ComplexVariable> solver::operator-(complex<double> c, ComplexVariable y)
{
    vector<ComplexVariable> vec;
    ComplexVariable var(real(c), 0, imag(c));
    y.coefficient *= -1;
    y.imag_coeffient *= -1;
    vec.push_back(var);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator-(ComplexVariable y, complex<double> c)
{
    vector<ComplexVariable> vec;
    ComplexVariable var(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator-(complex<double> c, double number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var1(real(c), 0, imag(c));
    ComplexVariable var2(-number, 0, 0);
    vec.push_back(var1);
    vec.push_back(var2);
    return vec;
}

vector<ComplexVariable> solver::operator/(ComplexVariable var, double number)
{
    var.coefficient /= number;
    var.imag_coeffient /= number;
    vector<ComplexVariable> vec;
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator/(vector<ComplexVariable> vec, double number)
{
    for (auto &v : vec)
    {
        v.coefficient /= number;
        v.imag_coeffient /= number;
    }

    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, ComplexVariable v)
{
    v.coefficient *= -1;
    v.imag_coeffient *= -1;
    vec.push_back(v);

    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, double number)
{
    ComplexVariable var2(-1 * number, 0, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, vector<ComplexVariable> vec2)
{

    for (auto &v : vec2)
    {
        v.coefficient *= -1;
        v.imag_coeffient *= -1;
        vec.push_back(v);
    }
    return vec;
}

vector<ComplexVariable> solver::operator==(vector<ComplexVariable> vec, complex<double> c)
{
    ComplexVariable var(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var);

    return vec;
}

vector<ComplexVariable> solver::operator==(double number, vector<ComplexVariable> vec)
{

    ComplexVariable var2(-1 * number, 0, 0);

    vec.push_back(var2);

    return vec;
}

vector<ComplexVariable> solver::operator==(complex<double> c, vector<ComplexVariable> vec)
{

    ComplexVariable var(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator==(double number, ComplexVariable y)
{
    vector<ComplexVariable> vec;
    ComplexVariable var1(-number, 0, 0);

    vec.push_back(var1);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator==(double number, complex<double> c)
{
    vector<ComplexVariable> vec;
    ComplexVariable var1(number, 0, 0);
    ComplexVariable var2(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var1);
    vec.push_back(var2);
    return vec;
}

vector<ComplexVariable> solver::operator==(ComplexVariable v, vector<ComplexVariable> vec)
{

    v.coefficient *= -1;
    v.imag_coeffient *= -1;
    vec.push_back(v);

    return vec;
}

vector<ComplexVariable> solver::operator==(ComplexVariable v, ComplexVariable v1)
{

    vector<ComplexVariable> vec;
    v1.coefficient *= -1;
    v1.imag_coeffient *= -1;
    vec.push_back(v);
    vec.push_back(v1);
    return vec;
}

vector<ComplexVariable> solver::operator==(ComplexVariable y, double number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var1(-number, 0, 0);

    vec.push_back(var1);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator==(ComplexVariable y, complex<double> c)
{

    vector<ComplexVariable> vec;
    ComplexVariable var(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(y);
    vec.push_back(var);
    return vec;
}

vector<ComplexVariable> solver::operator==(complex<double> c, ComplexVariable y)
{

    vector<ComplexVariable> vec;
    ComplexVariable var(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var);
    vec.push_back(y);
    return vec;
}

vector<ComplexVariable> solver::operator==(complex<double> c, double number)
{
    vector<ComplexVariable> vec;
    ComplexVariable var1(number, 0, 0);
    ComplexVariable var2(-1 * real(c), 0, -1 * imag(c));
    vec.push_back(var1);
    vec.push_back(var2);
    return vec;
}
