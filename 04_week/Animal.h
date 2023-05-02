#pragma once
#include <iostream>
#include <fstream>

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
	string GetTypeName();
	virtual void Read(std::ostream& ostr, std::istream& istr);
	virtual void Write(std::ostream& ostr);
	string GetName();

	virtual void Read(std::ifstream& iftr);
	virtual void Write(std::ofstream& oftr);
};

