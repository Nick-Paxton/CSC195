#include "Vector.h"
#include <iostream>
template <typename T>

void Display(const nc::vector<T>& vec)
{
	for (size_t iCount = 0; iCount < vec.size(); iCount++)
	{
		std::cout << vec[iCount] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "vector\n";
	nc::vector<int> numbers{ 43, 23, 56, 7, 16 }; //numbers = {43, 23, 56, 7, 16}
	numbers[0] = 84; //numbers = {84, 23, 56, 7, 16}
	numbers.push_back(99); //numbers = {84, 23, 56, 7, 16, 99}
	Display(numbers);
	std::cout << "copy\n";
	nc::vector<int> copy;
	copy = numbers; //copy = {84, 23, 56, 7, 16, 99}
	copy.pop_back(); //copy = {84, 23, 56, 7, 16}
	copy.pop_back(); //copy = {84, 23, 56, 7}
	Display(copy);
	std::cout << "swap\n";
	numbers.swap(copy); //numbers = {84, 23, 56, 7} copy = {84, 23, 56, 7, 16, 99}
	Display(numbers);
	Display(copy);
	std::cout << "clear\n";
	copy.clear();
	Display(copy);
	////REFERENCES
	std::cout << "assignment\n";
	copy = numbers;
	Display(numbers);
	std::cout << "resize\n";
	numbers.resize(10, 5);
	numbers.reserve(20);
	Display(numbers);
	std::cout << "front: " << numbers.front() << std::endl;
	std::cout << "back: " << numbers.back() << std::endl;
	std::cout << "size: " << numbers.size() << std::endl;
	std::cout << "max size: " << numbers.max_size() << std::endl;
	std::cout << "capacity: " << numbers.capacity() << std::endl;
	std::cout << "empty: " << numbers.empty() << std::endl;
	std::cout << "data: " << numbers.data() << std::endl;
}