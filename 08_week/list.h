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
		list(const list& other);
		~list();
		list& operator = (const list& other);
		T& front() { return this->_head->_value; };
		const T& front() const { return this->front(); };
		T& back() { return this->tail()->_value; };
		const T& back() const { return this->back(); };
		void push_front(const T& value);
		void pop_front();
		void push_back(const T& value);
		void pop_back();
		void remove(const T& value);
		void reverse(); // see references for implementation

		//void resize(size_t count, const T& value = T{});		// NOT REQUIRED ****************************************

		void clear(); // search online for implementation
		bool empty() { return (size() == 0); }
		size_t size(); // see references for implementation

		//size_t max_size() { return std::numeric_limits<size_t>::max(); }	// NOT REQUIRED **********************************

		std::ostream& write(std::ostream& stream); // Output list
	private:
		node_t* tail() {
			node_t* node = this->_head;
			if (!node) return nullptr;

			while (node->_next) {
				node = node->_next;
			}

			return node;
		}
	private:
		node_t* _head{ nullptr };
	};
	// ////////////////////////////////
	template<typename T>
	list<T>::list(const std::initializer_list<T>& ilist) {
		for (const auto& current : ilist) {
			push_back(current);
		}
	}
	// ////////////////////////////////
	template<typename T>
	list<T>::list(const list& other) {
		this = other;
	}
	// ////////////////////////////////
	template<typename T>
	list<T>::~list() {
		this->clear();
	}
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
		node_t* tempNode1 = this->_head; // Temp pointer
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
		node_t* node = this->_head;
		node_t* newNode = new node_t(value);
		if (!node) {
			this->_head = newNode;
			return;
		}
		while (node->_next) {
			node = node->_next;
		}
		newNode->_prev = node;
		node->_next = newNode;
	}
	// ////////////////////////////////
	template<typename T>
	void list<T>::push_front(const T& value) {
		node_t* node = this->_head;
		node_t* newNode = new node_t(value);

		this->_head = newNode;
		newNode->_next = node;
		if (node) node->_prev = newNode;
	}
	// ////////////////////////////////
	template<typename T>
	void list<T>::pop_front() {
		node_t* node = this->_head;
		this->_head = node->_next;

		delete node;
		if (this->_head) this->_head->_prev = nullptr;
	}
	// ////////////////////////////////
	template<typename T>
	void list<T>::pop_back() {
		node_t* node = this->_head;

		while (node->_next) {
			node = node->_next;
		}

		node->_prev->_next = nullptr;
		delete node;
	}
	// ////////////////////////////////
	template<typename T>
	void list<T>::remove(const T& value) {
		node_t* node = this->_head;

		while (node) {
			node_t* nextNode = node->_next;
			node_t* prevNode = node->_prev;
			if (node->_value == value) {
				
				delete node;
				if (prevNode && nextNode) {
					prevNode->_next = nextNode;
					nextNode->_prev = prevNode;
				}
				else if (prevNode) {
					prevNode->_next = nullptr;
				}
				else if (nextNode) {
					nextNode->_prev = nullptr;
					this->_head = nextNode;
				}
				else {
					this->_head = nullptr;
				}
			}
			node = nextNode;
		}
	}
	// ////////////////////////////////
	template<typename T>
	std::ostream& list<T>::write(std::ostream& stream) {
		node_t* node = this->_head;

		while (node) {
			stream << " " << node->_value << "\n";
			node = node->_next;
		}

		return stream;
	}
	// ////////////////////////////////
	template<typename T>
	void list<T>::reverse() {
		node_t* node = this->_head;
		node_t* next = node->_next;

		while (next) {
			node->_next = node->_prev;
			node->_prev = next;
			node = next;
			next = node->_next;
		}
		node->_next = node->_prev;
		node->_prev = nullptr;

		this->_head = node;
	}
	// ////////////////////////////////
	template<typename T>
	size_t list<T>::size() {
		node_t* node = this->_head;
		size_t count = 0;

		while (node) {
			count++;
			node = node->_next;
		}

		return count;
	}
}