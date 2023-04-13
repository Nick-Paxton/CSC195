#include <iostream>
using namespace std;
struct Person
{
	char name[32];
	int id;
};
void Line() {
	cout << "\n\n-----------------------------------\n";
}

void Square(int iVal) {
	iVal = iVal * iVal;
}

void SquareRef(int& iVal) {
	iVal = iVal * iVal;
}

void Double(int* iVal) {
	*iVal = *iVal * 2;
}

int main()
{
	cout << "\n 03_week Hello World ";
	Line();

	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	int myInt = 5;

	// declare a int reference and set it to the int variable above
	int& iRef = myInt; //Create a reference type (alias)

	// output the int variable
	cout << "\n Init value of myInt = " << myInt;

	// set the int reference to some number
	iRef = 10;

	// output the int variable
	cout << "\n After ref update value of myInt = " << myInt;

	// what happened to the int variable when the reference was changed? (insert answer)

	cout << "\n The value was updated to what iRef was set to.";

	// output the address of the int variable
	// output the address of the int reference
	// are the addresses the same or different? (insert answer)

	Line();
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	// output the int variable to the console
	Square(myInt);
	cout << "\n After Square() myInt value = " << myInt;

	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	SquareRef(iRef); // Pass by ref (alias)
	cout << "\n After SquareRef() myInt value = " << myInt;

	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""

	// ** POINTER VARIABLE **
	//
	// declare an int pointer, set it to nullptr (it points to nothing)
	int* iPtr = nullptr;

	// set the int pointer to the address of the int variable created in the REFERENCE section
	iPtr = &myInt;

	// output the value of the pointer
	// what is this address that the pointer is pointing to? (insert answer)
	// output the value of the object the pointer is pointing to (dereference the pointer)
	Line();

	// ** POINTER PARAMETER **
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(iPtr);
	//Double(&myInt); does the exact same as the line above

	// output the dereference pointer
	cout << "\n After Double() *iPtr value = " << *iPtr;

	// output the int variable created in the REFERENCE section
	cout << "\n After Double() myInt value = " << myInt;

	// did the int variable's value change when using the pointer?
	cout << "\n Yes the value changed when using the pointer";

	Line();
	// ** ALLOCATION/DEALLOCATION **
	//
	// create an int pointer that points at an int allocated on the heap, set the allocated int value to some number
	int* iHeapPtr = new int;
	*iHeapPtr = 42;

	// output the pointer value, this should be the address of the int allocated on the heap
	cout << "\n Address of the heap int: " << iHeapPtr;
	// output the dereference pointer
	cout << "\n Value of the heap int: " << *iHeapPtr;
	// deallocate the int pointer to free up the memory
	delete iHeapPtr;
	// create an int pointer that points at an array of ints allocated on the heap, the array size should be 4 - 6
	int *iPtrA = new int[6];
	// use a for loop and set each int in the array to a random number (use => rand() % 10 to get a random number
	srand(time(0));
	for (int iCount = 0; iCount < 6; iCount++) {
		iPtrA[iCount] = rand() % 10;
	}
	// use a for loop and output each of the ints in the array
	for (int iCount = 0; iCount < 6; iCount++) {
		cout << "\n Value at index " << iCount << ": " << iPtrA[iCount];
	}
	// use a for loop and output the address of each of the ints in the array
	for (int iCount = 0; iCount < 6; iCount++) {
		cout << "\n Address at index " << iCount << ": " << &iPtrA[iCount];
	}
	// deallocate the int pointer to free up the memory block (remember it's an array)
	delete[] iPtrA;

	Line();
	// ** STRUCTURE **
	//
	// create a Person pointer that points at an array of Persons allocated on the heap, the array size should be 2
	Person* myPerson = new Person[2];

	// read in a name from the console and set it to the person name, do this for the id also, do this for both Persons
	cout << "\n Enter the first person's name: ";
	cin >> myPerson[0].name;
	cout << "\n Enter the first person's id: ";
	cin >> myPerson[0].id;
	cout << "\n Enter the second person's name: ";
	cin >> myPerson[1].name;
	cout << "\n Enter the second person's id: ";
	cin >> myPerson[1].id;
	// use a for loop and output the name and id of each person in the array
	for (int iCount = 0; iCount < 2; iCount++) {
		cout << "\n Person's name at index " << iCount << ": " << myPerson[iCount].name;
		cout << "\n Person's id at index " << iCount << ": " << myPerson[iCount].id;
	}
	// deallocate the person pointer to free up the memory block (remember it's an array)
	delete[] myPerson;

	Line();
}

