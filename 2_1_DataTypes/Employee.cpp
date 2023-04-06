#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee() {

}

void Employee::Read() {
    const short unsigned MAX_DAYS = 7;

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
        cin >> hoursPerDay[iCount];
        // Calc running totals here
        fGrossPay += (hoursPerDay[iCount] * fWage);
    }

    fTotalTaxes = fGrossPay * TAX;
    fNetPay = fGrossPay - fTotalTaxes;
}

void Employee::Write() {
    cout << "\n Gross pay is: $" << fGrossPay;
    cout << "\n Total taxes is: $" << fTotalTaxes;
    cout << "\n Net pay is: $" << fNetPay;
    cout << "\n Pay to: " << name << "\n";
}