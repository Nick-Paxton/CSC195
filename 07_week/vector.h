#pragma once
#include <initializer_list>
#include <limits>
namespace nc
{
	template<typename T>
	class vector
	{
	public:
		// Constructor
		//vector() {}
		vector(size_t capacity);
		vector(const std::initializer_list<T>& ilist);
		//vector(const vector& other);
		//// Destructor
		//~vector();
		//// Operators
		//vector& operator = (const vector& other);
		//T& operator [] (size_t position);
		//const T& operator [] (size_t position) const;
		//// Methods
		//T& at(size_t position);
		//const T& at(size_t position) const;
		T& front() { return _elements[0]; };
		T& back() { return _elements[_size-1]; };
		T* data() { return _elements; };
		//void push_back(const T& value);
		//void pop_back();
		//void reserve(size_t capacity);
		//void resize(size_t new_size, const T& value = T{});
		void clear() { _size = 0; };
		//void swap(vector& other);
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

	template<typename T>
	vector<T>::vector(size_t capacity) {
		_elements = new T[capacity];
		_capacity = capacity;
		_size = 0;
	}

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
}