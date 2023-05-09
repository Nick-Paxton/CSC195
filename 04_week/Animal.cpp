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
// ////////////////////////////////////
void Animal::Read(std::ifstream& iftr) {
	iftr >> this->_name;
	iftr >> this->_lifespan;
}
// ////////////////////////////////////
void Animal::Write(std::ofstream& oftr) {
	oftr << (int)this->GetType() << std::endl; // this must be first
	oftr << this->_name << std::endl;
	oftr << this->_lifespan << std::endl;
}
// ////////////////////////////////////
// Console
std::ostream& operator << (std::ostream& ostr, Animal& animal) {
	animal.Write(ostr);
	return ostr;
}
// ////////////////////////////////////
std::istream& operator >> (std::istream& istr, Animal& animal) {
	animal.Read(std::cout, istr);
	return istr;
}
// ////////////////////////////////////
// File
std::ofstream& operator << (std::ofstream& oftr, Animal& animal) {
	animal.Write(oftr);
	return oftr;
}
// ////////////////////////////////////
std::ifstream& operator >> (std::ifstream& iftr, Animal& animal) {
	animal.Read(std::cout, iftr);
	return iftr;
}