#pragma once
#include <initializer_list>
#include <limits>
#include <iostream>

namespace nc
{
	template<typename T>
	class list
	{
		struct node_t
		{
			node_t(const T& value) : _value{ value } {}
			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};
	public:
		list() {}
		list(const std::initializer_list<T>& ilist);
		//list(const list& other);
		//~list();
		list& operator = (const list& other);
		//T& front();
		//const T& front() const;
		//T& back();
		//const T& back() const;
		//void push_front(const T& value);
		//void pop_front();
		void push_back(const T& value);
		//void pop_back();
		//void remove(const T& value);
		//void reverse(); // see references for implementation

		//void resize(size_t count, const T& value = T{});		// NOT REQUIRED ****************************************

		void clear(); // search online for implementation
		bool empty() { return (size() == 0); }
		//size_t size(); // see references for implementation

		//size_t max_size() { return std::numeric_limits<size_t>::max(); }	// NOT REQUIRED **********************************

		//std::ostream& write(std::ostream& stream); // Output list
	private:
		node_t* tail();
	private:
		node_t* _head{ nullptr };
	};
	// ////////////////////////////////
	template<typename T>
	list<T>& list<T>::operator = (const list& other) {
		
		clear();

		node_t* node = other._head; // Temp pointer
		while (node) {
			push_back(node->_value);
			node = node->_next;
		}

		return *this;
	}
	// ////////////////////////////////
	template<typename T>
	void list<T>::clear() {
		node_t* tempNode1 = this._head; // Temp pointer
		node_t* tempNode2 = nullptr;
		while (tempNode1) {
			tempNode2 = tempNode1->_next;
			delete tempNode1;
			tempNode1 = tempNode2;
		}
		_head = nullptr;
	}
	// ////////////////////////////////
	template<typename T>
	void list<T>::push_back(const T& value) {

	}
}