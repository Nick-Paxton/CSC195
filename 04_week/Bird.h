#pragma once
#include "Animal.h"
#include <iostream>
#include <fstream>
using namespace std;

class Bird: public Animal {
public:
	eType GetType() override { return eType::Bird; }
	void Read(std::ostream& ostr, std::istream & istr) override;
	void Write(std::ostream& ostr) override;
	void Read(std::ifstream& iftr) override;
	void Write(std::ofstream& oftr) override;

protected:
	unsigned int _wingspan;
	unsigned int _numEggs;

};

