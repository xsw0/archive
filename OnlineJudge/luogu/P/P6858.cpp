#include <bits/stdc++.h>

using namespace std;

class Integer
{
public:
    static constexpr uint64_t mod = 998244353;
    uint64_t n;
    Integer(uint64_t n = 0) : n(n % mod){};
    Integer operator+(const Integer &other) const
    {
        return n + other.n;
    }
    Integer operator-(const Integer &other) const
    {
        return n - other.n;
    }
    Integer operator*(const Integer &other) const
    {
        return n * other.n;
    }
    Integer operator^(uint64_t pow) const
    {
        Integer result(1);
        Integer x = *this;
        while (pow)
        {
            if (pow % 2 != 0)
            {
                result = result * x;
            }
            x = x * x;
            pow /= 2;
        }
        return result;
    }
    Integer operator/(const Integer &other) const
    {
        return *this * (other ^ (mod - 2));
    }
};

class Rational
{
public:
    Integer numerator;
    Integer denominator;
    Rational(const Integer &numerator = 0, Integer denominator = 1)
        : numerator(numerator), denominator(denominator){};
    Rational operator+(const Rational &other) const
    {
        return Rational(numerator * other.denominator +
                            denominator * other.numerator,
                        denominator * other.denominator);
    }
    Rational operator-(const Rational &other) const
    {
        return Rational(numerator * other.denominator -
                            denominator * other.numerator,
                        denominator * other.denominator);
    }
    Rational operator*(const Rational &other) const
    {
        return Rational(numerator * other.numerator,
                        denominator * other.denominator);
    }
    Rational operator/(const Rational &other) const
    {
        return Rational(numerator * other.denominator,
                        denominator * other.numerator);
    }

    operator Integer() const
    {
        return numerator / denominator;
    }
};

istream &operator>>(istream &is, Integer &n)
{
    cin >> n.n;
    n.n %= Integer::mod;
    return is;
}

Rational f(const Integer &n, const Integer &m)
{
    if (m.n == 0)
    {
        return Rational(n * (n + 3), 2);
    }
    else
    {
        auto f_1 = f(n, m - 1);
        auto nm = n + m;
        auto m2 = m * 2;
        auto nm_3 = nm + 3;
        return Rational(f_1.denominator * (n * nm * nm_3 + m2) + f_1.numerator * m2,
                        f_1.denominator * nm * 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Integer n, m;
    cin >> n >> m;
    cout << static_cast<Integer>(f(n, m)).n << '\n';

    return 0;
}
