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

class ComplexVariable : public RealVariable
{
public:
    int imag_coeffient;
    ComplexVariable(double coef = 1, int deg = 1, double imag_coef = 0) : RealVariable{coef, deg},
                                                                          imag_coeffient(imag_coef)
    {
    }

    friend ostream &operator<<(ostream &out, const ComplexVariable &var);
};

double solve(vector<RealVariable> elements);

vector<RealVariable> operator^(vector<RealVariable> vec, double number);
vector<RealVariable> operator^(RealVariable x, double number);
vector<RealVariable> operator*(RealVariable x, double number);
vector<RealVariable> operator*(double number, RealVariable x);
vector<RealVariable> operator*(RealVariable x1, RealVariable x);
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
vector<ComplexVariable> operator/(ComplexVariable var, int number);
vector<ComplexVariable> operator/(vector<ComplexVariable> vec, int number);
vector<ComplexVariable> operator==(vector<ComplexVariable> vec, ComplexVariable v);
vector<ComplexVariable> operator==(vector<ComplexVariable> vec, double number);
vector<ComplexVariable> operator==(vector<ComplexVariable> vec, vector<ComplexVariable> vec2);
vector<ComplexVariable> operator==(vector<ComplexVariable> vec, complex<double> c);
vector<ComplexVariable> operator==(double number, vector<ComplexVariable> vec);
vector<ComplexVariable> operator==(complex<double> c, vector<ComplexVariable> vec);

} // namespace solver

#endif