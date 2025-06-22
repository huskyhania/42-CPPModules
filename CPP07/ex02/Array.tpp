#include "Array.hpp"

//creates an empty array
template <class T>
Array<T>::Array() : _size(0), _array(nullptr) {}

//creates an array of size n or nullptr array
template <class T>
Array<T>::Array(unsigned int n) : _size(n), _array(nullptr)
{
	const unsigned int MAX_SIZE = 1000000000;
	if (n > MAX_SIZE)
		throw std::length_error("Array size too large/ attempt to initialize with negative numbers");
	_array = new T[n];
}

template <class T>
Array<T>::Array(const Array &original) : _size(original._size),
	_array(original._size > 0 ? new T[original._size] : nullptr)
{
	for (size_t i = 0; i < _size; ++i)
		_array[i] = original._array[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array &original)
{
	delete [] _array;
	_size = original._size;
	_array = _size > 0 ? new T[_size] : nullptr;
	for (size_t i = 0; i < _size; ++i)
		_array[i] = original._array[i];
	return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw(std::runtime_error("Index out of bounds"));
	return _array[index];
}

template <class T>
size_t Array<T>::size() const
{
	return _size;
}

template <class T>
Array<T>::~Array()
{
	delete[] _array;
}
