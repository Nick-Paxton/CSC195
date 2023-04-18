#pragma once
#include <iostream>
using namespace std;

class MyInput
{
public:
	int GetUserInt(string prompt, unsigned short low, unsigned short high);
	int GetUserInt(unsigned short low, unsigned short high);
};

