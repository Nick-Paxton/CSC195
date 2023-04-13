#pragma once
class Employee
{
	// put properties at the top
public:
	const float TAX = 0.1f;
	char name[32];
	float hoursPerDay[7];
	short shDaysWorked = 0;
	float fWage = 0;
	float fGrossPay = 0;
	float fTotalTaxes = 0;
	float fNetPay = 0;

protected:

private:


	// Put methods in the middle
public:
	Employee();
	~Employee();
	void Read();
	void Write();

protected:

private:
};

