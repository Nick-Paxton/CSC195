#include "MyInput.h"

// /////////////////////////////////
int MyInput::GetUserInt(string prompt, unsigned short low, unsigned short high) {
	int iTemp = low - 1;
	do {
		cout << "\n " << prompt << "\n";
		cout << "\n Enter a number between " << low << " and " << high << ": \n";
		cin >> iTemp;

		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << "\n Inproper input !!!! ";
			iTemp = low - 1;  //Continue loop
		}
	} while ((iTemp < low) || (iTemp > high));
	return iTemp;
}
// ///////////////////////////////////
int MyInput::GetUserInt(unsigned short low, unsigned short high) {
	return GetUserInt("", low, high);
}