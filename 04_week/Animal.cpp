#include "Animal.h"
// ////////////////////////////////////
void Animal::Read(std::ostream& ostr, std::istream& istr) {
	ostr << "\n Enter Animal name: ";
	istr >> this->_name;
	ostr << "\n Enter Animal Lifespan: ";
	istr >> this->_lifespan;
}