//Hello World
/* By Nick Paxton */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
const int MAX_CHIPS = 100;
const float MAX_TURN = .5;
void example();
void game();
void write();
void structs();
void classes();
void pointers();
void linkedLists();

class BankAccount
{
	private:
		float balance;

	public:
		BankAccount();
		void Deposit(float);
		void Withdraw();
		float getBalance();
};

BankAccount::BankAccount()
{
	balance = 0;
}

float BankAccount::getBalance()
{
	return balance;
}

void BankAccount::Deposit(float dep)
{
	balance += dep;
}

struct student
{
	string name;
	float GPA;
};


int main()
{
	
}

void linkedLists()
{

}

void pointers()
{
	int v1 = 0;
	int* p1;
	p1 = &v1;
	cout << v1 << " and pointer is " << *p1 << endl;
	*p1 = 42;
	cout << v1 << " and pointer is " << *p1 << endl;
}

void classes()
{
	BankAccount checking;
	BankAccount savings;
	cout << "Checking balance is: " << checking.getBalance() << endl;
	cout << "Savings balance is: " << savings.getBalance() << endl;

	checking.Deposit(100);
	savings.Deposit(500);

	cout << "Checking balance is: " << checking.getBalance() << endl;
	cout << "Savings balance is: " << savings.getBalance() << endl;
}

void structs()
{
	student teacher;
	teacher.name = "Dr. Colvin";
	student firstPeriod[10];
	firstPeriod[0].name = "Tom";
	firstPeriod[0].GPA = 4.0;
	cout << firstPeriod[0].name << endl;
}

void example()
{
	ifstream inStream;
	ofstream outStream;
	outStream.open("NewPassPhrase.txt", ios::app); // ios::app means to append in the file instead of rewriting the entire thing
	inStream.open("passphrase.txt");
	int userGuess = 0;
	string passPhrase;

	if (!inStream.fail())
	{
		while (inStream >> passPhrase)
		{
			cout << "The pass phrase is: " << passPhrase << endl;
			cout << "What is your answer?\n";
			cin >> userGuess;
			if (userGuess == passPhrase.length())
			{
				cout << "Congrats\n";
			}
			else
			{
				cout << "Sorry try again later\n";
				outStream << passPhrase << endl;
			}
		}
	}
	outStream.close();
	inStream.close();
}

void write()
{
	ofstream testStream;
	testStream.open("passphrase.txt");
	testStream << "TWENTY" << endl;
	testStream.close();
}

void game()
{
	bool player1Turn = true;
	bool gameOver = false;
	int maxPerTurn = 0;
	int chipsInPile = 0;
	int chipsTaken = 0;
	string playerName[2];

	//seed the random number generator
	srand(time(0));

	cout << "Player 1, please enter your name: \n";
	cin >> playerName[0];
	cout << "Player 2, please enter your name: \n";
	cin >> playerName[1];


	chipsInPile = (rand() % MAX_CHIPS) + 1;
	maxPerTurn = (chipsInPile * MAX_TURN);
	cout << "This round will start with " << chipsInPile << " chips in the pile\n";
	if (player1Turn) {
		cout << playerName[0] << " how many chips would you like?\n";
	}
	else {
		cout << playerName[1] << " how many chips would you like?\n";
	}
	cout << "You can only take " << maxPerTurn << endl;
	cin >> chipsTaken;
	chipsTaken = (rand() % maxPerTurn) + 1;

	cout << "Number taken: " << chipsTaken << endl;
}













//example code
/*
int main()
{
	int dice = 0;

	srand(time(0));

	dice = (rand() % 6) + 1;
	cout << "You rolled a " << dice << endl;


	return 0;
}
*/