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
	bool p = false;
	for (std::unique_ptr<Animal>& animal : this->_animals) {
		if (animal->GetName().compare(name) == 0) {
			animal->Write(ostr);
			p = true;
		}
	}
	if (!p) {
		ostr << "\n No Animals found with that name.";
	}
}
// ////////////////////////////////////
void Database::Display(std::ostream& ostr, Animal::eType type) {
	bool p = false;
	for (std::unique_ptr<Animal>& animal : this->_animals) {
		if (animal->GetType() == type) {
			animal->Write(ostr);
			p = true;
		}
	}
	if (!p) {
		ostr << "\n No Animals found with that type.";
	}
}
// ///////////////////////////
void Database::Save(string filename) {
	std::ofstream output(filename, std::ostream::out | std::ofstream::app);

	if (output.is_open()) {
		for (std::unique_ptr<Animal>& animal : this->_animals) {
			animal->Write(output);
		}
	}
	else {
		cout << "\n *************** FILE OPEN ERROR ***************";
	}

	if (output.is_open()) {
		output.close();
	}
}
// ///////////////////////////
void Database::Load(string filename) {
	std::ifstream input(filename);
	int iType = 0;
	std::unique_ptr<Animal> animal;

	if (input.is_open()) {
		this->RemoveAll();
		while (!input.eof()) {
			iType = 0;
			input >> iType;

			if (iType != 0) {
				animal = this->Create(static_cast<Animal::eType>(iType));
				//animal = this->Create((Animal::eType)iType);

				//switch (iType) {
				//case 1:
				//	animal = Create(Animal::eType::Fish);
				//	break;
				//case 2:
				//	animal = Create(Animal::eType::Bird);
				//	break;
				//}//End Switch
				animal->Read(input);
				Add(animal);
			} // End Inner If
		} //End While

	} //End Outer If
	else {
		cout << "\n *************** FILE OPEN ERROR ***************";
	} //End else

	if (input.is_open()) {
		input.close();
	}
}
// ///////////////////////////
