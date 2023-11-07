#include <iostream>

using namespace std;

class Rational
{

public:
    Rational(const int &n = 0, const int &d = 1);
    // Rational(const double& doub);
    int getNpart() const;
    int getDpart() const;
    void setNpart(const int &n);
    void setDpart(const int &d);
    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const;
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational &other) const;
    bool operator>(const Rational &other) const;
    friend ostream &operator<<(std::ostream &os, const Rational &rational);

private:
    int numerator;
    int denominator;
    static int count;
    void simplfy();
};

int Rational::count = 0;

Rational::Rational(const int &n, const int &d)
{
    setNpart(n);
    setDpart(d);
    simplfy();
    ++count;
}

int Rational::getNpart() const
{
    return numerator;
}

int Rational::getDpart() const
{
    return denominator;
}

void Rational::setNpart(const int &n)
{
    numerator = n;
}

void Rational::setDpart(const int &d)
{
    denominator = d;
}

Rational Rational::operator+(const Rational &other) const
{
    int new_d = denominator * other.getDpart();
    int new_n = (numerator * other.getDpart()) + (other.getNpart() * denominator);
    return Rational(new_n, new_d);
}

Rational Rational::operator-(const Rational &other) const
{
    int new_d = denominator * other.getDpart();
    int new_n = (numerator * other.getDpart()) - (other.getNpart() * denominator);
    return Rational(new_n, new_d);
}

Rational Rational::operator*(const Rational &other) const
{
    int new_d = denominator * other.getDpart();
    int new_n = numerator * other.getNpart();
    return Rational(new_n, new_d);
}

Rational Rational::operator/(const Rational &other) const
{
    int new_d = denominator * other.getNpart();
    int new_n = numerator * other.getDpart();
    return Rational(new_n, new_d);
}

bool Rational::operator>(const Rational &other) const
{
    return (numerator * other.getDpart()) > (other.getNpart() * denominator);
}

void Rational::simplfy()
{
    int gcd = 1;
    int smaller = (abs(numerator) < denominator) ? abs(numerator) : denominator;

    for (int i = 1; i <= smaller; ++i)
    {
        if (numerator % i == 0 && denominator % i == 0)
        {
            gcd = i;
        }
    }

    numerator /= gcd;
    denominator /= gcd;
}

ostream &operator<<(std::ostream &os, const Rational &rational)
{
    os << rational.getNpart() << "/" << rational.getDpart();
    return os;
}

int main()
{
    Rational r1(1, 2);
    Rational r2(3, 4);

    std::cout << "Rational Number 1: " << r1.getNpart() << "/" << r1.getDpart() << std::endl;
    std::cout << "Rational Number 2: " << r2.getNpart() << "/" << r2.getDpart() << std::endl;
    // cout << (r2 > r1) << endl;

    Rational sum = r1 + r2;
    std::cout << "Sum: " << sum.getNpart() << "/" << sum.getDpart() << std::endl;

    Rational difference = r1 - r2;
    std::cout << "Difference: " << difference.getNpart() << "/" << difference.getDpart() << std::endl;

    Rational product = r1 * r2;
    std::cout << "Product: " << product.getNpart() << "/" << product.getDpart() << std::endl;

    Rational quotient = r1 / r2;
    std::cout << "Quotient: " << quotient.getNpart() << "/" << quotient.getDpart() << std::endl;

    return 0;
}