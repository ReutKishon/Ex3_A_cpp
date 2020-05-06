#ifndef SOLVER_H_
#define SOLVER_H_
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

        friend ostream &operator<<(ostream &out, const RealVariable &var);
        friend vector<RealVariable> operator^(vector<RealVariable> &vec, const int number);
        friend vector<RealVariable> operator^(RealVariable &x, const int number);
        friend vector<RealVariable> operator*(const int num, vector<RealVariable> &vec);
        friend vector<RealVariable> operator*(vector<RealVariable> &vec, const int num);
        friend vector<RealVariable> operator*(RealVariable &x, const int number);
        friend vector<RealVariable> operator*(const int number, RealVariable &x);
        friend vector<RealVariable> operator*(RealVariable &x1, RealVariable &x);
        friend vector<RealVariable> operator+(vector<RealVariable> &vec1, vector<RealVariable> &vec2);
        friend vector<RealVariable> operator+(RealVariable &var, const int number);
        friend vector<RealVariable> operator+(const int number, RealVariable &var);
        friend vector<RealVariable> operator+(vector<RealVariable> &vec, const int number);
        friend vector<RealVariable> operator+(const int number, vector<RealVariable> &vec);
        friend vector<RealVariable> operator-(RealVariable &x, RealVariable &x1);
        friend vector<RealVariable> operator-(RealVariable &var, vector<RealVariable> &vec);
        friend vector<RealVariable> operator-(vector<RealVariable> &vec1, vector<RealVariable> &vec2);
        friend vector<RealVariable> operator-(RealVariable &var, const int number);
        friend vector<RealVariable> operator-(vector<RealVariable> &vec, const int number);
        friend vector<RealVariable> operator-(vector<RealVariable> &vec, RealVariable &var);
        friend vector<RealVariable> operator/(vector<RealVariable> &vec, RealVariable &var);
        friend vector<RealVariable> operator/(RealVariable &var, RealVariable &var2);
        friend vector<RealVariable> operator/(RealVariable &var, const int number);
        friend vector<RealVariable> operator/(vector<RealVariable> &vec, const int number);
        friend vector<RealVariable> operator==(RealVariable &v1, RealVariable &v);
        friend vector<RealVariable> operator==(vector<RealVariable> &vec, RealVariable &v);
        friend vector<RealVariable> operator==(vector<RealVariable> &vec, const int number);
        friend vector<RealVariable> operator==(vector<RealVariable> &vec, vector<RealVariable> &vec2);
    };
    // : public RealVariable
    class ComplexVariable
    {
    public:
        double coefficient;
        int degree;
        double imag_coeffient;
        ComplexVariable(double coef = 1, int deg = 1, double imag_coef = 0) : coefficient(coef), degree(deg), imag_coeffient(imag_coef)
        // : RealVariable{coef, deg},
        //
        {
        }

        ComplexVariable(const ComplexVariable &other)
        {
            this->degree = other.degree;
            this->coefficient = other.coefficient;
            this->imag_coeffient = other.imag_coeffient;
        }

        friend ostream &operator<<(ostream &out, const ComplexVariable &var);

        // Complex overloads

        friend vector<ComplexVariable> operator^(vector<ComplexVariable> vec, double number);
        friend vector<ComplexVariable> operator^(ComplexVariable x, double number);
        friend vector<ComplexVariable> operator*(ComplexVariable x, double number);
        friend vector<ComplexVariable> operator*(double number, ComplexVariable x);
        friend vector<ComplexVariable> operator*(ComplexVariable y1, ComplexVariable y);
        friend vector<ComplexVariable> operator+(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
        friend vector<ComplexVariable> operator+(ComplexVariable var, double number);
        friend vector<ComplexVariable> operator+(ComplexVariable var, complex<double> number);
        friend vector<ComplexVariable> operator+(double number, ComplexVariable var);
        friend vector<ComplexVariable> operator+(complex<double> number, ComplexVariable var);
        friend vector<ComplexVariable> operator+(vector<ComplexVariable> vec, double number);
        friend vector<ComplexVariable> operator+(vector<ComplexVariable> vec, complex<double> number);
        friend vector<ComplexVariable> operator+(double number, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator+(complex<double> number, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
        friend vector<ComplexVariable> operator-(ComplexVariable var, double number);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec, double number);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec, ComplexVariable var);
        friend vector<ComplexVariable> operator-(complex<double> c, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator-(ComplexVariable y, complex<double> c);
        friend vector<ComplexVariable> operator-(complex<double> c, ComplexVariable y);
        friend vector<ComplexVariable> operator-(vector<ComplexVariable> vec, complex<double> c);
        friend vector<ComplexVariable> operator-(double number, complex<double> c);
        friend vector<ComplexVariable> operator-(double number, ComplexVariable y);
        friend vector<ComplexVariable> operator-(complex<double> c, double number);
        friend vector<ComplexVariable> operator/(ComplexVariable var, double number);
        friend vector<ComplexVariable> operator/(vector<ComplexVariable> vec, double number);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, ComplexVariable v);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, double number);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, vector<ComplexVariable> vec2);
        friend vector<ComplexVariable> operator==(vector<ComplexVariable> vec, complex<double> c);
        friend vector<ComplexVariable> operator==(double number, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator==(complex<double> c, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator==(double number, ComplexVariable y);
        friend vector<ComplexVariable> operator==(double number, complex<double> c);
        friend vector<ComplexVariable> operator==(ComplexVariable v, vector<ComplexVariable> vec);
        friend vector<ComplexVariable> operator==(ComplexVariable v, ComplexVariable v1);
        friend vector<ComplexVariable> operator==(ComplexVariable y, double number);
        friend vector<ComplexVariable> operator==(ComplexVariable y, complex<double> c);
        friend vector<ComplexVariable> operator==(complex<double> c, ComplexVariable y);
        friend vector<ComplexVariable> operator==(complex<double> c, double number);
    };
    std::complex<double> solve(vector<ComplexVariable> elements);
    double solve(vector<RealVariable> elements);

} // namespace solver

#endif