#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;

class Fish: 
	public Animal 
{
public:
	eType GetType() override { return eType::Fish; }
	void Read(std::ostream& ostr, std::istream& istr) override;
	void Write(std::ostream& ostr) override;

protected:
	string _habitat;
	unsigned int _numTeeth;
	unsigned int _numFins;
};

