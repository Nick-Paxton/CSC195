#include "Database.h"

// //////////////////////////////////
std::unique_ptr<Animal> Database::Create(Animal::eType type) {
	Animal* animal = nullptr;

	switch (type) {
	case Animal::eType::Bird:
		animal = new Bird();
		break;
	case Animal::eType::Fish:
		animal = new Fish();
		break;
	} // End Switch

	return std::unique_ptr<Animal>{animal}; // this is casting
}
// ////////////////////////////////////
void Database::Add(std::unique_ptr<Animal>& animal) {
	_animals.push_back(std::move(animal));
	cout << "\n ********* List Size = " << _animals.size() << " *********";
}
// ////////////////////////////////////
void Database::DisplayAll(std::ostream& ostr) {
	for (std::unique_ptr<Animal>& animal : this->_animals) {
		animal->Write(ostr);
	}
}
// ////////////////////////////////////
void Database::Display(std::ostream& ostr, const std::string& name) {
	for (std::unique_ptr<Animal>& animal : this->_animals) {
		bool p = false;
		if (animal->GetName().compare(name) == 0) {
			animal->Write(ostr);
			p = true;
		}
		if (!p) {
			ostr << "\n No Animals found with that name.";
		}
	}
}
// ////////////////////////////////////
void Database::Display(std::ostream& ostr, Animal::eType type) {
	for (std::unique_ptr<Animal>& animal : this->_animals) {
		bool p = false;
		if (animal->GetType() == type) {
			animal->Write(ostr);
			p = true;
		}
		if (!p) {
			ostr << "\n No Animals found with that type.";
		}
	}
}