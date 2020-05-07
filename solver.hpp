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
        // realVariable operators

        //left
        friend vector<RealVariable> operator^(RealVariable x, double number);
        friend vector<RealVariable> operator*(RealVariable x, double number);
        friend vector<RealVariable> operator+(RealVariable var, double number);
        friend vector<RealVariable> operator-(RealVariable var, double number);
        friend vector<RealVariable> operator/(RealVariable var, double number);

        //rigth
        friend vector<RealVariable> operator*(double number, RealVariable x);
        friend vector<RealVariable> operator+(double number, RealVariable x);
        friend vector<RealVariable> operator-(double number, RealVariable var);

        //both

        friend vector<RealVariable> operator*(RealVariable x1, RealVariable x);
        friend vector<RealVariable> operator-(RealVariable x, RealVariable x1);
        friend vector<RealVariable> operator/(RealVariable var, RealVariable var2);
        friend vector<RealVariable> operator+(RealVariable x, RealVariable x1); //

        //vector
        //left
        friend vector<RealVariable> operator^(vector<RealVariable> vec, double number);

        friend vector<RealVariable> operator*(vector<RealVariable> vec, double num);
        friend vector<RealVariable> operator*(vector<RealVariable> vec, RealVariable x);            //
        friend vector<RealVariable> operator*(vector<RealVariable> vec, vector<RealVariable> vec1); //

        friend vector<RealVariable> operator+(vector<RealVariable> vec1, vector<RealVariable> vec2);
        friend vector<RealVariable> operator+(vector<RealVariable> vec, double number);
        friend vector<RealVariable> operator+(vector<RealVariable> vec, RealVariable x);

        friend vector<RealVariable> operator-(vector<RealVariable> vec1, vector<RealVariable> vec2);
        friend vector<RealVariable> operator-(vector<RealVariable> vec, double number);
        friend vector<RealVariable> operator-(vector<RealVariable> vec, RealVariable var);

        friend vector<RealVariable> operator/(vector<RealVariable> vec, RealVariable var);
        friend vector<RealVariable> operator/(vector<RealVariable> vec, double number);

        //right

        friend vector<RealVariable> operator*(double num, vector<RealVariable> vec);
        friend vector<RealVariable> operator*(RealVariable x, vector<RealVariable> vec); ///

        friend vector<RealVariable> operator+(double number, vector<RealVariable> vec);
        friend vector<RealVariable> operator+(RealVariable x, vector<RealVariable> vec);

        friend vector<RealVariable> operator-(double number, vector<RealVariable> vec);
        friend vector<RealVariable> operator-(RealVariable var, vector<RealVariable> vec);

        // vector<RealVariable> operator/(vector<RealVariable> vec, RealVariable var); //
        // vector<RealVariable> operator/(vector<RealVariable> vec, double number);    //

        // equals
        friend vector<RealVariable> operator==(RealVariable v1, RealVariable v);
        friend vector<RealVariable> operator==(vector<RealVariable> vec, RealVariable v);
        friend vector<RealVariable> operator==(RealVariable v, vector<RealVariable> vec);

        friend vector<RealVariable> operator==(double number, vector<RealVariable> vec);

        friend vector<RealVariable> operator==(vector<RealVariable> vec, double number);
        friend vector<RealVariable> operator==(vector<RealVariable> vec, vector<RealVariable> vec2);
    };
    class ComplexVariable : public RealVariable

    {
    public:
        double imag_coeffient;
        ComplexVariable(double coef = 1, int deg = 1, double imag_coef = 0) : RealVariable{coef, deg}, imag_coeffient(imag_coef)

        {
        }

        friend ostream &operator<<(ostream &out, const ComplexVariable &var);

        /////// complex:

        //left

        friend vector<ComplexVariable> operator^(ComplexVariable x, double number);
        friend vector<ComplexVariable> operator*(ComplexVariable x, double number);
        friend vector<ComplexVariable> operator+(ComplexVariable x, double number);
        friend vector<ComplexVariable> operator-(ComplexVariable x, double number);
        friend vector<ComplexVariable> operator/(ComplexVariable x, double number);

        // right

        friend vector<ComplexVariable> operator*(double number, ComplexVariable x);
        friend vector<ComplexVariable> operator+(double number, ComplexVariable x);
        friend vector<ComplexVariable> operator-(double number, ComplexVariable y);

        // both
        friend vector<ComplexVariable> operator*(ComplexVariable y1, ComplexVariable y);

        // vector - left

        friend vector<ComplexVariable> operator^(vector<ComplexVariable> vec, double number);

        friend vector<ComplexVariable> operator+(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
        friend vector<ComplexVariable> operator+(vector<ComplexVariable> vec, double number);

        friend vector<ComplexVariable> operator+(vector<ComplexVariable> vec, complex<double> number);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec, double number);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec, ComplexVariable var);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec, complex<double> c);
        friend vector<ComplexVariable> operator/(vector<ComplexVariable> vec, double number);

        // vector - right

        friend vector<ComplexVariable> operator+(double number, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator+(complex<double> number, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator-(complex<double> c, vector<ComplexVariable> vec);
        // imaginary

        friend vector<ComplexVariable> operator+(ComplexVariable var, complex<double> number);
        friend vector<ComplexVariable> operator+(complex<double> number, ComplexVariable var);
        friend vector<ComplexVariable> operator+(double number, complex<double> c); //
        friend vector<ComplexVariable> operator+(complex<double> c, double number); //
        friend vector<ComplexVariable> operator-(ComplexVariable y, complex<double> c);
        friend vector<ComplexVariable> operator-(complex<double> c, ComplexVariable y);
        friend vector<ComplexVariable> operator-(double number, complex<double> c);
        friend vector<ComplexVariable> operator-(complex<double> c, double number);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, ComplexVariable v);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, double number);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, complex<double> c);
        friend vector<ComplexVariable> operator==(double number, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator==(complex<double> c, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator==(double number, ComplexVariable y);
        friend vector<ComplexVariable> operator==(ComplexVariable v, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator==(ComplexVariable v, ComplexVariable v1);
        friend vector<ComplexVariable> operator==(ComplexVariable y, double number);
        friend vector<ComplexVariable> operator==(ComplexVariable y, complex<double> c);
        friend vector<ComplexVariable> operator==(complex<double> c, ComplexVariable y);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, vector<ComplexVariable> vec2);
    };
    //solve functions:
    double linear_solver(vector<RealVariable> elements);
    vector<RealVariable> minimize(vector<RealVariable> vec);
    bool compare_variable_by_degree(RealVariable v1, RealVariable v2);
    complex<double> linear_solver_complex(vector<ComplexVariable> elements);
    vector<ComplexVariable> minimize(vector<ComplexVariable> vec);
    bool compare_variable_by_degree_complex(ComplexVariable v1, ComplexVariable v2);

    std::complex<double> solve(vector<ComplexVariable> elements);
    double solve(vector<RealVariable> elements);

} // namespace solver

#endif