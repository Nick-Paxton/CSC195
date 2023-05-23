#pragma once
#include <iostream>
using namespace std;
class myInput
{
public:
	char GetUserChar();
	int GetUserInt(string prompt, unsigned short low, unsigned short high);
	int GetUserInt(unsigned short low, unsigned short high);
};