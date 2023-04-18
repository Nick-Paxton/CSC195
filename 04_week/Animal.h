#pragma once
#include <iostream>
using namespace std;

class Animal
{
public:
	enum class eType { Fish = 1, Bird = 2 };

protected:
	string _name;
	string _color;
	unsigned int _lifespan;

public:
	virtual eType GetType() = 0; // Pure virtual function
	virtual void Read(std::ostream& ostr, std::istream& istr);

};
