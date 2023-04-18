// 04_week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyInput.h"
using namespace std;

int main()
{
    MyInput input;
    cout << "\n 04_week Hello World!\n";

    int iMenu = 0;
    while (iMenu != 6) {
        cout << "\n Enter Menu option: ";

        cout << "\n 6. Quit\n";
        iMenu = input.GetUserInt("asdf", 1, 6);
    }
}