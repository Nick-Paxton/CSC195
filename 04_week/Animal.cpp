#include "Animal.h"
// ////////////////////////////////////
void Animal::Read(std::ostream& ostr, std::istream& istr) {
	ostr << "\n Enter Animal name: ";
	istr >> this->_name;
	ostr << "\n Enter Animal Lifespan: ";
	istr >> this->_lifespan;
}
// ////////////////////////////////////
string Animal::GetTypeName() {
	switch (this->GetType()) {
	case Animal::eType::Bird:
		return "Bird";
		break; // redundant not necessary - some compilers will complain
	case Animal::eType::Fish:
		return "Fish";
		break; // redundant not necessary - some compilers will complain
	}
	return "Undefined Animal";
}
// ////////////////////////////////////
void Animal::Write(std::ostream& ostr) {
	ostr << "\n -------------------------------------";
	ostr << "\n Name: " << this->_name;
	ostr << "\n Type: " << this->GetTypeName();
	ostr << "\n Lifespan: " << this->_lifespan;
}
// ////////////////////////////////////
string Animal::GetName() {
	return this->_name;
}