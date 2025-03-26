#include <iostream>
#include <cmath>
#include <concepts>

template<typename T>
concept FloatingPoint = std ::is_floating_point<T>::value;

template <FloatingPoint T>
class complex_number {
	private:
	T real;
	T imag;

	