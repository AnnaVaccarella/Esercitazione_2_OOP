#include <iostream>
#include <cmath> // per funzioni matematiche
#include <concepts>

template<typename T>
concept FloatingPoint = std ::is_floating_point<T>::value;

template <FloatingPoint T>
class complex_number {
private:
    T real;
    T imag;

public:
    //Costruttore di default che inizializza la parte reale e immaginaria a 0
    complex_nuber() : real(0), imag(0) {}
    //Costruttore user-defined che permette di specificare la parte reale e immaginaria al momento dell'istanza
    complex_number(T realPart, T imagPart) : real(realPart), imag(imagPart) {}
    //Modalità per ottenere la parte reale
    T getReal() const { return real; }
    //Modalità per ottenere la parte immaginaria
    T getImag() const {return imag; }
    //Modalità per ottenere il coniugato
    complex_number conjugate() const {
        return complex_number(real, -imag);
    }

	
