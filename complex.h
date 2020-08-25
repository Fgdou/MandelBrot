#pragma once

class Complex{
public:
    Complex();
    Complex(long double r, long double i);
    Complex(const Complex& copy);

    ~Complex() = default;

    long double abs() const;
    long double r() const;
    long double i() const;

    void pow(int i);


    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>=(const Complex& other) const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;

    const Complex& operator+=(const Complex& other);
    const Complex& operator-=(const Complex& other);
    const Complex& operator*=(const Complex& other);


private:
    long double m_i;
    long double m_r;
};