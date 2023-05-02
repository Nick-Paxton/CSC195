#pragma once
#include "Animal.h"
#include <iostream>
#include <fstream>

using namespace std;

class Fish: 
	public Animal 
{
public:
	eType GetType() override { return eType::Fish; }
	void Read(std::ostream& ostr, std::istream& istr) override;
	void Write(std::ostream& ostr) override;
	void Read(std::ifstream& iftr) override;
	void Write(std::ofstream& oftr) override;

protected:
	string _habitat;
	unsigned int _numTeeth;
	unsigned int _numFins;
};

