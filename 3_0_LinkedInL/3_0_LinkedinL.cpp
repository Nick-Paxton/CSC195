//Hello World
/* By Nick Paxton */
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int MAX_CHIPS = 100;
const float MAX_TURN = .5;
int main()
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

	return 0;
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