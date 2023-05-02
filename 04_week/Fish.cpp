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
// ///////////////////////////
void Fish::Write(std::ostream& ostr) {
	Animal::Write(ostr);

	ostr << "\n Habitat: " << _habitat;
	ostr << "\n Number of Teeth: " << _numTeeth;
	ostr << "\n Number of Fins: " << _numFins;
}
// ///////////////////////////
void Fish::Read(std::ifstream& iftr) {
	Animal::Read(iftr);

	iftr >> this->_habitat;
	iftr >> this->_numTeeth;
	iftr >> this->_numFins;
}
// ///////////////////////////
void Fish::Write(std::ofstream& oftr) {
	Animal::Write(oftr);

	oftr << this->_habitat << std::endl;
	oftr << this->_numTeeth << std::endl;
	oftr << this->_numFins << std::endl;
}