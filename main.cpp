#include <iostream>
using namespace std;

char playerSymbol;
void displayBoard(char setArray[9]) {
	for (int i = 0; i < 9; i++) {
		cout << " | " << setArray[i];
		if ((i + 1) % 3 == 0) {
			// if reached the final column, begin a new row
			cout << endl;
		}
	}
}

void instructions() {
	cout << "Welcome to tic toe land" << endl;
	cout << "The board is a 3x3 grid and each cell represented by its row and column number" << endl;
	cout << "To make a move, enter the row and column where you want to place symbol" << endl;
	cout << "Hint: Place you symbol in the left corner of the board by entering '0 0'" << endl;
}

void guide(char setArray[9]) {
	for (int i = 0; i < 9; i++) {
		cout << i + 1 << " | " << setArray[i];
		if ((i + 1) % 3 == 0) {
			cout << endl;
		}
	}
}

bool playerMove(char setArray[9]) {
	int row;
	cout << "Enter a number based on board position " << endl;
	cin >> row ;
	while (setArray[row]!= ' ')
	{
		cout << "Invalid, position has been taken"<<endl;
		cin >> row;
	}
	setArray[row] = playerSymbol;
	return true;

} 

char askPlayer() {
	char question;
	do {
		cout << "Do you want to go first? (y / no) ";
		cin >> question;
	} while (question != 'y' && question != 'n');

	return question;
}
int main()
{	
	char array[9] = {
			' ', ' ', ' ',
			' ', ' ',' ',
			' ', ' ', ' '
	};
	instructions();
	char askUser = askPlayer();
	if (askUser == 'y') {
		cout << "Great! You go first"<<endl;
		playerSymbol = 'X';
	}
	else {
		cout << "Sure, i'll go first"<<endl;
		playerSymbol = 'O';
	}

	for (int i = 0; i <= 9; i++) {
		guide(array);
		playerMove(array);
		displayBoard(array);	
	}
	




}
