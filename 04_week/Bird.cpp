#include "Bird.h"
// ///////////////////////////
void Bird::Read(std::ostream& ostr, std::istream& istr) {
	
	Animal::Read(ostr, istr);
	// Get Bird Details
	ostr << "\n Enter wingspan (cm): ";
	istr >> this->_wingspan;
	ostr << "\n Enter Number of Eggs: ";
	istr >> this->_numEggs;
}

void Bird::Write(std::ostream& ostr) {
	Animal::Write(ostr);

	ostr << "\n Wingspan: " << _wingspan;
	ostr << "\n Number of Eggs: " << _numEggs;
}