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

	// [5-2]
	friend bool operator == (const std::unique_ptr<Animal>& animal, const std::string& name) {
		return (name == animal->GetName());
	}
	//
	friend bool operator == (const std::unique_ptr<Animal>& animal, const Animal::eType& type) {
		return (type == animal->GetType());
	}
	// Console
	friend std::ostream& operator << (std::ostream& ostr, Animal& animal);
	friend std::istream& operator >> (std::istream& istr, Animal& animal);
	// File
	friend std::ofstream& operator << (std::ofstream& oftr, Animal& animal);
	friend std::ifstream& operator >> (std::ifstream& iftr, Animal& animal);
};

