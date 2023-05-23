#include "myInput.h"


char myInput::GetUserChar() {
	char high = 'z';
	char low = 'a';
	int iTemp = (int)low - 1;
	char cTemp = (char)iTemp;
	do {
		cout << "\n " << "Enter a character to guess" << "\n";
		cout << "\n Enter a character between " << 'a' << " and " << 'z' << ": \n";
		cin >> cTemp;

		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << "\n Inproper input !!!! ";
			cTemp = (char)iTemp;  //Continue loop
		}
	} while (((int)cTemp < (int)low) || ((int)cTemp > (int)high));
	return cTemp;
}
// /////////////////////////////////
int myInput::GetUserInt(string prompt, unsigned short low, unsigned short high) {
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
int myInput::GetUserInt(unsigned short low, unsigned short high) {
	return GetUserInt("", low, high);
}