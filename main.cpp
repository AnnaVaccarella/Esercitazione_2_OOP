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
//Test della classe
int main() {
    complex_number<double> n1(1, 2);
    complex_number<double> n2(3, -4);

    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;

    complex_number<double> n3 = n1 + n2;
    std::cout << "n1 + n2: " << n3 << std::endl;

    n1 += n2;
    std::cout << "Dopo n1 += n2: " << n1 << std::endl;

    complex_number<double> n4 = n1 * n2;
    std::cout << "n1 * n2: " << n4 << std::endl;

    n1 *= n2;
    std::cout << "Dopo n1 *= n2: " << n1 << std::endl;

    return 0;
}