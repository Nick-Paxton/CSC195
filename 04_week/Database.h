#pragma once
#include <list>

#include "Animal.h"
#include "Bird.h"
#include "Fish.h"

class Database
{
private:
	std::list<std::unique_ptr<Animal>> _animals;

public:
	std::unique_ptr<Animal> Create(Animal::eType);
	void Add(std::unique_ptr<Animal>& animal);
	
	void DisplayAll(std::ostream& ostr);
	void Display(std::ostream& ostr, const std::string& name);
	void Display(std::ostream& ostr, Animal::eType type);
};