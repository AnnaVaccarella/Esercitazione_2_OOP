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
