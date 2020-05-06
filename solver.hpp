#ifndef SOLVER_H_
#define SOLVER_H_
#include <complex>
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
        RealVariable(double coef = 1, int deg = 1) : coefficient(coef), degree(deg)
        {
        }

        RealVariable(const RealVariable &other)
        {
            this->degree = other.degree;
            this->coefficient = other.coefficient;
        }

        friend ostream &operator<<(ostream &out, const RealVariable &var);
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
    };

    double solve(vector<RealVariable> elements);

    vector<RealVariable> operator^(vector<RealVariable> &vec, const int number);
    vector<RealVariable> operator^(RealVariable &x, const int number);
    vector<RealVariable> operator*(const int num, vector<RealVariable> &vec);
    vector<RealVariable> operator*(vector<RealVariable> &vec, const int num);
    vector<RealVariable> operator*(RealVariable &x, const int number);
    vector<RealVariable> operator*(const int number, RealVariable &x);
    vector<RealVariable> operator*(RealVariable &x1, RealVariable &x);
    vector<RealVariable> operator+(vector<RealVariable> &vec1, vector<RealVariable> &vec2);
    vector<RealVariable> operator+(RealVariable &var, const int number);
    vector<RealVariable> operator+(const int number, RealVariable &var);
    vector<RealVariable> operator+(vector<RealVariable> &vec, const int number);
    vector<RealVariable> operator+(const int number, vector<RealVariable> &vec);
    vector<RealVariable> operator-(RealVariable &x, RealVariable &x1);
    vector<RealVariable> operator-(RealVariable &var, vector<RealVariable> &vec);
    vector<RealVariable> operator-(vector<RealVariable> &vec1, vector<RealVariable> &vec2);
    vector<RealVariable> operator-(RealVariable &var, const int number);
    vector<RealVariable> operator-(vector<RealVariable> &vec, const int number);
    vector<RealVariable> operator-(vector<RealVariable> &vec, RealVariable &var);
    vector<RealVariable> operator/(vector<RealVariable> &vec, RealVariable &var);
    vector<RealVariable> operator/(RealVariable &var, RealVariable &var2);
    vector<RealVariable> operator/(RealVariable &var, const int number);
    vector<RealVariable> operator/(vector<RealVariable> &vec, const int number);
    vector<RealVariable> operator==(RealVariable &v1, RealVariable &v);
    vector<RealVariable> operator==(vector<RealVariable> &vec, RealVariable &v);
    vector<RealVariable> operator==(vector<RealVariable> &vec, const int number);
    vector<RealVariable> operator==(vector<RealVariable> &vec, vector<RealVariable> &vec2);

    // Complex overloads
    std::complex<double> solve(vector<ComplexVariable> elements);

    vector<ComplexVariable> operator^(vector<ComplexVariable> vec, double number);
    vector<ComplexVariable> operator^(ComplexVariable x, double number);
    vector<ComplexVariable> operator*(ComplexVariable x, double number);
    vector<ComplexVariable> operator*(double number, ComplexVariable x);
    vector<ComplexVariable> operator*(ComplexVariable y1, ComplexVariable y);
    vector<ComplexVariable> operator+(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
    vector<ComplexVariable> operator+(ComplexVariable var, double number);
    vector<ComplexVariable> operator+(ComplexVariable var, complex<double> number);
    vector<ComplexVariable> operator+(double number, ComplexVariable var);
    vector<ComplexVariable> operator+(complex<double> number, ComplexVariable var);
    vector<ComplexVariable> operator+(vector<ComplexVariable> vec, double number);
    vector<ComplexVariable> operator+(vector<ComplexVariable> vec, complex<double> number);
    vector<ComplexVariable> operator+(double number, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator+(complex<double> number, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec1, vector<ComplexVariable> vec2);
    vector<ComplexVariable> operator-(ComplexVariable var, double number);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec, double number);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec, ComplexVariable var);
    vector<ComplexVariable> operator-(complex<double> c, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator-(ComplexVariable y, complex<double> c);
    vector<ComplexVariable> operator-(complex<double> c, ComplexVariable y);
    vector<ComplexVariable> operator-(vector<ComplexVariable> vec, complex<double> c);
    vector<ComplexVariable> operator-(double number, complex<double> c);
    vector<ComplexVariable> operator-(double number, ComplexVariable y);
    vector<ComplexVariable> operator-(complex<double> c, double number);
    vector<ComplexVariable> operator/(ComplexVariable var, double number);
    vector<ComplexVariable> operator/(vector<ComplexVariable> vec, double number);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, ComplexVariable v);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, double number);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, vector<ComplexVariable> vec2);
    vector<ComplexVariable> operator==(vector<ComplexVariable> vec, complex<double> c);
    vector<ComplexVariable> operator==(double number, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator==(complex<double> c, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator==(double number, ComplexVariable y);
    vector<ComplexVariable> operator==(double number, complex<double> c);
    vector<ComplexVariable> operator==(ComplexVariable v, vector<ComplexVariable> vec);
    vector<ComplexVariable> operator==(ComplexVariable v, ComplexVariable v1);
    vector<ComplexVariable> operator==(ComplexVariable y, double number);
    vector<ComplexVariable> operator==(ComplexVariable y, complex<double> c);
    vector<ComplexVariable> operator==(complex<double> c, ComplexVariable y);
    vector<ComplexVariable> operator==(complex<double> c, double number);

} // namespace solver

#endif