#include "complex.h"
#include <math.h>

Complex::Complex()
    : m_r(0), m_i(0)
{

}

Complex::Complex(long double r, long double i)
    : m_i(i), m_r(r)
{

}

Complex::Complex(const Complex &copy)
    :m_i(copy.m_i), m_r(copy.m_r)
{

}

long double Complex::abs() const {
    return sqrt(m_i*m_i + m_r*m_r);
}

bool Complex::operator==(const Complex &other) const {
    return (m_r == other.m_r && m_i == other.m_i);
}

bool Complex::operator!=(const Complex &other) const {
    return !operator==(other);
}

bool Complex::operator<(const Complex &other) const {
    return (abs() < other.abs());
}

long double Complex::r() const {
    return m_r;
}

long double Complex::i() const {
    return m_i;
}

bool Complex::operator>(const Complex &other) const {
    return (abs() > other.abs());
}

bool Complex::operator<=(const Complex &other) const {
    return (abs() <= other.abs());
}

bool Complex::operator>=(const Complex &other) const {
    return (abs() >= other.abs());
}

Complex Complex::operator+(const Complex &other) const {
    Complex n = *this;
    n += other;
    return n;
}

Complex Complex::operator-(const Complex &other) const {
    Complex n = *this;
    n -= other;
    return n;
}

Complex Complex::operator*(const Complex &other) const {
    Complex n = *this;
    n *= other;
    return n;
}

const Complex &Complex::operator+=(const Complex &other) {
    m_r += other.m_r;
    m_i += other.m_i;
    return *this;
}

const Complex &Complex::operator-=(const Complex &other) {
    m_r -= other.m_r;
    m_i -= other.m_i;
    return *this;
}

const Complex &Complex::operator*=(const Complex &other) {
    // (8 + i) * (1 + 8i) = 8 + 8i2 + i + 64i = 8 - 8 + 65i
    long double r = m_r * other.m_r - m_i * other.m_i;
    long double i = 2 * m_i * other.m_r;
    m_r = r;
    m_i = i;
    return *this;
}

void Complex::pow(int i) {
    Complex c = *this;
    for(int j=0; j<i-1; j++){
        operator*=(c);
    }
}
