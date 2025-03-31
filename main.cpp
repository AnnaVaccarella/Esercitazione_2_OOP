#include <iostream>
#include <concepts>

template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

template <FloatingPoint T>
class complex_number {
private:
    T real, imag;

public:
    // Costruttore di default che inizializza la parte reale e immaginaria a 0
    complex_number() : real(0), imag(0) {}

    // Costruttore con parametri che permette di specificare la parte reale e immaginaria al momento dell'istanza 
    complex_number(T r, T i) : real(r), imag(i) {}

    // Metodi per ottenere parte reale, immaginaria e coniugato
    T get_real() const { return real; }
    T get_imag() const { return imag; }
    complex_number conjugate() const { return complex_number(real, -imag); }

   // Overload dell'operatore +=
    complex_number& operator+=(const complex_number& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Overload dell'operatore +
    complex_number operator+(const complex_number& other) const {
        return complex_number(real + other.real, imag + other.imag);
    }

    // Overload dell'operatore *=
    complex_number& operator*=(const complex_number& other) {
        T new_real = real * other.real - imag * other.imag;
        T new_imag = real * other.imag + imag * other.real;
        real = new_real;
        imag = new_imag;
        return *this;
    }

    // Overload dell'operatore *
    complex_number operator*(const complex_number& other) const {
        return complex_number(real * other.real - imag * other.imag,
                              real * other.imag + imag * other.real);
    }

    // Overload dell'operatore <<
    friend std::ostream& operator<<(std::ostream& os, const complex_number& c) {
        os << c.real;
        if (c.imag >= 0)
            os << "+" << c.imag << "i";
        else
            os << c.imag << "i";
        return os;
    }
};
