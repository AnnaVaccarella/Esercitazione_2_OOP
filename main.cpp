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
	//Overload dell'operatore <<
friend std::ostream& operator<<(std::ostream& os, const complex_number& c)}
	if (c.imag >= 0)
		os << c.real << "+" << c.imag << "i" ;
	else
		os << c.real << "-" << -c.imag << "i" ;
	return os;
}
//Overload dell'operatore +
complex_number operator+(const complex_number& other) other const {
	return complex_number(real + other.real, imag + other.imag);
}
//Overload sull'operatore *
complex_number operator*(const complex_number& other) const {
	return complex_number(
	real * other.real - imag * other.imag,
	real * other.imag + imag * other.real
	);
}
//Overload per l'operatore ==
bool operator==(const complex_number& other) const {
	return real == other.real && imag ==other.imag;
}
};
//Funzione main per il test 
int main() {
	complex_number<double> n1(1.0, 2.0); //Numero complesso 1+2i
	complex_number<double> n2(5.0, 3.0); //Numero complesso 5+3i
	
	std::cout << "Numero complesso 1: " << n1 << std::endl;
	std::cout << "Numero complesso 2: " << n2 << std::endl;
	
//Somma
complex_number<double> somma = n1 + n2;
std::cout << "Somma: " << somma << std::endl;
//Moltiplicazione
complex_number<double> prodotto = n1 * n2;
std::cout << "Prodotto: " << prodotto << std::endl;
//Coniugato di n1
complex_number<double> coniugato = n1.conjugate();
std::cout << "Coniugato di n1: " << coniugato << std::endl;

return 0;
}