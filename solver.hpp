#ifndef SOLVER_H_
#define SOLVER_H_
#pragma once

#include <complex>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <vector>

using namespace std;

namespace solver
{
    class RealVariable
    {
    public:
        int degree;
        double coefficient;
        RealVariable(double coef = 1, int deg = 1) : coefficient(coef), degree(deg)
        {
        }

        RealVariable(const RealVariable &other)
        {
            this->degree = other.degree;
            this->coefficient = other.coefficient;
        }

        friend ostream &operator<<(ostream &out, RealVariable var);
    };
    class ComplexVariable : public RealVariable

    {
    public:
        double imag_coeffient;
        ComplexVariable(double coef = 1, int deg = 1, double imag_coef = 0) : RealVariable{coef, deg}, imag_coeffient(imag_coef)

        {
        }

        friend ostream &operator<<(ostream &out, const ComplexVariable &var);
    };
    // realVariable operators

    //left
    vector<RealVariable> operator^(RealVariable x, double number);
    vector<RealVariable> operator*(RealVariable x, double number);
    vector<RealVariable> operator+(RealVariable var, double number);
    vector<RealVariable> operator-(RealVariable var, double number);
    vector<RealVariable> operator/(RealVariable var, double number);

    //rigth
    vector<RealVariable> operator*(double number, RealVariable x);
    vector<RealVariable> operator+(double number, RealVariable x);
    vector<RealVariable> operator-(double number, RealVariable var);

    //both

    vector<RealVariable> operator*(RealVariable x1, RealVariable x);
    vector<RealVariable> operator-(RealVariable x, RealVariable x1);
    vector<RealVariable> operator/(RealVariable var, RealVariable var2);
    vector<RealVariable> operator+(RealVariable x, RealVariable x1); //

    //vector
    //left
    vector<RealVariable> operator^(vector<RealVariable> vec, double number);

    vector<RealVariable> operator*(vector<RealVariable> vec, double num);
    vector<RealVariable> operator*(vector<RealVariable> vec, RealVariable x);            //
    vector<RealVariable> operator*(vector<RealVariable> vec, vector<RealVariable> vec1); //

    vector<RealVariable> operator+(vector<RealVariable> vec1, vector<RealVariable> vec2);
    vector<RealVariable> operator+(vector<RealVariable> vec, double number);
    vector<RealVariable> operator+(vector<RealVariable> vec, RealVariable x);

    vector<RealVariable> operator-(vector<RealVariable> vec1, vector<RealVariable> vec2);
    vector<RealVariable> operator-(vector<RealVariable> vec, double number);
    vector<RealVariable> operator-(vector<RealVariable> vec, RealVariable var);

    vector<RealVariable> operator/(vector<RealVariable> vec, RealVariable var);
    vector<RealVariable> operator/(vector<RealVariable> vec, double number);

    //right

    vector<RealVariable> operator*(double num, vector<RealVariable> vec);
    vector<RealVariable> operator*(RealVariable x, vector<RealVariable> vec); ///

    vector<RealVariable> operator+(double number, vector<RealVariable> vec);
    vector<RealVariable> operator+(RealVariable x, vector<RealVariable> vec);

    vector<RealVariable> operator-(double number, vector<RealVariable> vec);
    vector<RealVariable> operator-(RealVariable var, vector<RealVariable> vec);

    // vector<RealVariable> operator/(vector<RealVariable> vec, RealVariable var); //
    // vector<RealVariable> operator/(vector<RealVariable> vec, double number);    //

    // equals
    vector<RealVariable> operator==(RealVariable v1, RealVariable v);
    vector<RealVariable> operator==(vector<RealVariable> vec, RealVariable v);
    vector<RealVariable> operator==(RealVariable v, vector<RealVariable> vec);

    vector<RealVariable> operator==(double number, vector<RealVariable> vec);

    vector<RealVariable> operator==(vector<RealVariable> vec, double number);
    vector<RealVariable> operator==(vector<RealVariable> vec, vector<RealVariable> vec2);

    /////// complex:

    //left

    vector<ComplexVariable> operator^(ComplexVariable x, double number);
    vector<ComplexVariable> operator*(ComplexVariable x, double number);
    vector<ComplexVariable> operator+(ComplexVariable x, double number);
    vector<ComplexVariable> operator-(ComplexVariable x, double number);
    vector<ComplexVariable> operator/(ComplexVariable x, double number);

    // right

    vector<ComplexVariable> operator*(double number, ComplexVariable x);
    vector<ComplexVariable> operator+(double number, ComplexVariable x);
    vector<ComplexVariable> operator-(double number, ComplexVariable y);

    // both
    vector<ComplexVariable> operator*(ComplexVariable y1, ComplexVariable y);

    // vector - left

    vector<ComplexVariable> operator^(vector<ComplexVariable> vec, double number);

    vector<ComplexVariable> operator+(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
    vector<ComplexVariable> operator+(vector<ComplexVariable> vec, double number);

    vector<ComplexVariable> operator+(vector<ComplexVariable> vec, complex<double> number);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec, double number);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec, ComplexVariable var);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec, complex<double> c);
    vector<ComplexVariable> operator/(vector<ComplexVariable> vec, double number);

    // vector - right

    vector<ComplexVariable> operator+(double number, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator+(complex<double> number, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator-(complex<double> c, vector<ComplexVariable> vec);
    // imaginary

    vector<ComplexVariable> operator+(ComplexVariable var, complex<double> number);
    vector<ComplexVariable> operator+(complex<double> number, ComplexVariable var);
    vector<ComplexVariable> operator+(double number, complex<double> c); //
    vector<ComplexVariable> operator+(complex<double> c, double number); //
    vector<ComplexVariable> operator-(ComplexVariable y, complex<double> c);
    vector<ComplexVariable> operator-(complex<double> c, ComplexVariable y);
    vector<ComplexVariable> operator-(double number, complex<double> c);
    vector<ComplexVariable> operator-(complex<double> c, double number);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, ComplexVariable v);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, double number);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, complex<double> c);
    vector<ComplexVariable> operator==(double number, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator==(complex<double> c, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator==(double number, ComplexVariable y);
    vector<ComplexVariable> operator==(ComplexVariable v, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator==(ComplexVariable v, ComplexVariable v1);
    vector<ComplexVariable> operator==(ComplexVariable y, double number);
    vector<ComplexVariable> operator==(ComplexVariable y, complex<double> c);
    vector<ComplexVariable> operator==(complex<double> c, ComplexVariable y);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, vector<ComplexVariable> vec2);

    //solve functions:
    std::complex<double> solve(vector<ComplexVariable> elements);
    double solve(vector<RealVariable> elements);

} // namespace solver

#endif