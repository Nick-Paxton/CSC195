#pragma once
#include <fstream>
#include <initializer_list>
#include <limits>
namespace nc
{
	template<typename T>
	class vector
	{
	public:
		// Constructor
		vector() {}
		vector(size_t capacity);
		vector(const std::initializer_list<T>& ilist);
		vector(const vector& other);
		//// Destructor
		~vector();
		//// Operators
		vector& operator = (const vector& other);
		T& operator [] (size_t position) { return _elements[position]; };
		const T& operator [] (size_t position) const { return _elements[position]; };
		//// Methods
		T& at(size_t position) { return _elements[position]; };
		const T& at(size_t position) const { return _elements[position]; };
		T& front() { return _elements[0]; };
		T& back() { return _elements[_size - 1]; };
		T* data() { return _elements; };
		void push_back(const T& value);
		void pop_back() { if (_size > 0) _size = _size - 1; };
		void reserve(size_t capacity);  // Make Larger
		void resize(size_t new_size, const T& value = T{});
		void clear() { _size = 0; };
		void swap(vector& other);
		bool empty() const { return (_size == 0); };
		size_t size() const { return _size; };
		size_t capacity() const { return _capacity; };
		size_t max_size() const { return std::numeric_limits<size_t>::max() / sizeof(T); }
	private:
		// Properties
		T* _elements{ nullptr };
		size_t _size{};
		size_t _capacity{};
	};
	// ////////////////////////////////
	template<typename T>
	vector<T>::~vector() {
		delete[] _elements;
	}
	// ////////////////////////////////
	template<typename T>
	vector<T>::vector(size_t capacity) {
		_elements = new T[capacity];
		_capacity = capacity;
		_size = 0;
	}
	// ////////////////////////////////
	template<typename T>
	vector<T>::vector(const std::initializer_list<T>& ilist) {
		_size = ilist.size();
		_capacity = _size;
		_elements = new T[_size];

		// Copy Elements
		size_t iCount = 0;
		for (auto iter = ilist.begin(); iter != ilist.end(); iter++) {
			_elements[iCount] = *iter;
			iCount++;
		}
	}
	// ////////////////////////////////
	template<typename T>
	vector<T>::vector(const vector& other) {
		if (this == &other) return *this;
		// if there is data 
		if (_size) {
			delete[] _elements;
		}
		_size = other._size;
		_capacity = other._capacity;
		_elements = new T[_capacity];

		// Copy Data
		for (size_t count = 0; count << other.size(); count++) {
			_elements[count] = other[count];
		}
	}
	// ////////////////////////////////
	template<typename T>
	void vector<T>::push_back(const T& value) {
		if (_size >= _capacity) {
			reserve(_capacity + 5);
		}
		_elements[_size] = value;
		_size++;
	}
	// ////////////////////////////////
	template<typename T>
	void vector<T>::reserve(size_t capacity) {
		if (capacity <= _capacity) return;

		T* new_elements = new T[capacity];
		for (size_t count = 0; count < _size; count++) {
			new_elements[count] = _elements[count];
		}
		delete[] _elements;
		_elements = new_elements;
		_capacity = capacity;

	}
	// ////////////////////////////////
	template<typename T>
	vector<T>& vector<T>::operator = (const vector& other) {
		if (this == &other) return *this;

		// Copy all the data to this one
		if (_size)
			delete[] _elements;

		_size = other._size;
		_capacity = other._capacity;
		_elements = new T[_capacity];
		// Copy Data
		for (size_t count = 0; count < other._size; count++) {
			_elements[count] = other[count];
		}
		return *this;
	}
	// ////////////////////////////////
	template<typename T>
	void vector<T>::resize(size_t new_size, const T& value) {
		if (new_size > _capacity) {
			reserve(new_size);
		}
		for (size_t i = _size; i < new_size; i++)
		{
			_elements[i] = value;
		}
		_size = new_size;
	}
	// ////////////////////////////////
	template<typename T>
	void vector<T>::swap(vector& other) {
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
		std::swap(_elements, other._elements);
		/*nc::vector<int> copy; attempt 1
		copy = other;
		other = this;
		this = copy;*/
		/*if (other._size > _size) { attempt 2
			T* new_elements = new T[other.size()];
			for (size_t iCount = 0; iCount < other.size(); iCount++) {
				new_elements[iCount] = other[iCount];
				if (iCount < _size) {
					other[iCount] = _elements[iCount];
				}
			}
			reserve(other.size());
			size_t holderSize = other.size();
			other.resize(size());
			resize(holderSize);
			for (size_t iCount = 0; iCount < other.size(); iCount++) {
				_elements[iCount] = new_elements[iCount];
			}
			delete[] new_elements;
		}
		else if (_size > other._size) {
			T* new_elements = new T[size()];
			for (size_t iCount = 0; iCount < size(); iCount++) {
				new_elements[iCount] = _elements[iCount];
				if (iCount < other.size()) {
					_elements[iCount] = other[iCount];
				}
			}
			other.reserve(size());
			size_t holderSize = size();
			resize(other.size());
			other.resize(holderSize);
			for (size_t iCount = 0; iCount < size(); iCount++) {
				other._elements[iCount] = new_elements[iCount];
			}
			delete[] new_elements;
		}*/
	}
}