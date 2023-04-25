#include "Fish.h"
// ///////////////////////////
void Fish::Read(std::ostream& ostr, std::istream& istr) {

	Animal::Read(ostr, istr);
	// Get Bird Details
	ostr << "\n Enter the fish's habitat: ";
	istr >> this->_habitat;
	ostr << "\n Enter the number of teeth: ";
	istr >> this->_numTeeth;
	ostr << "\n Enter the number of fins: ";
	istr >> this->_numFins;
}

void Fish::Write(std::ostream& ostr) {
	Animal::Write(ostr);

	ostr << "\n Habitat: " << _habitat;
	ostr << "\n Number of Teeth: " << _numTeeth;
	ostr << "\n Number of Fins: " << _numFins;
}