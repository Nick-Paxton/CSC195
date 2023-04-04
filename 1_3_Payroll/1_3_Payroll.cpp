// 1_3_Payroll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>

int main()
{
    const unsigned short MAX_DAYS = 7;
    const float TAX = 0.1f;

    cout << "1_3_Payroll Hello World!\n";
    
    string name; // Get from user
    unsigned short shDaysWorked = 0; // Get from user
    unsigned short hours[MAX_DAYS]; // Get from user
    float fGrossPay = 0; // Pay before taxes ** calc
    float fWage = 0; // Hourly pay rate ** Get from user
    float fNetPay = 0; // Gross pay minus taxes ** calc
    float fTotalTaxes = 0; // Gross pay times tax rate ** calc

    cout << "\n Enter your name: ";
    cin >> name;
    cout << "\n Enter days worked: ";
    cin >> shDaysWorked; //Normally would make a function to make sure that the user is entering the right data. Not doing this to save time
    cout << "\n Enter you hourly wage: ";
    cin >> fWage;
    
    if (shDaysWorked > MAX_DAYS)
        shDaysWorked = MAX_DAYS;

    for (int iCount = 0; iCount < shDaysWorked; iCount++) {
        cout << "\n Enter the hours worked on Day " << (iCount + 1) << ": ";
        cin >> hours[iCount];
        // Calc running totals here
        fGrossPay += (hours[iCount] * fWage);
    }

    fTotalTaxes = fGrossPay * TAX;
    fNetPay = fGrossPay - fTotalTaxes;


    // Somewhere above calc gross, net, tax, etc.
    cout << "\n Gross pay is: $" << fGrossPay;
    cout << "\n Total taxes is: $" << fTotalTaxes;
    cout << "\n Net pay is: $" << fNetPay;
    cout << "\n Pay to: $" << name;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
