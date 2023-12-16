#include <iostream>
using namespace std;

char playerSymbol;
void displayBoard(char array[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout <<"  " << "|" << array[i][j];
		}
		cout << endl;
	}

}

void instructions() {
	cout << "Welcome to tic toe land" << endl;
	cout << "The board is a 3x3 grid and each cell represented by its row and column number" << endl;
	cout << "To make a move, enter the row and column where you want to place symbol" << endl;
	cout << "Hint: Place you symbol in the left corner of the board by entering '0 0'" << endl;
}

bool playerMove(char setArray[3][3]) {
	int row, col;
	cout << "Enter a row and column position to place your marker on the board." << endl << " e.g(0 0 or 1 3) ";
	cin >> row  >> col;
	while (setArray[row][col] != ' ')
	{
		cout << "Invalid, position has been taken"<<endl;
		cin >> row >> col;
	}
	setArray[row][col] = playerSymbol;
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
	char array[3][3] = {
			{' ', ' ', ' '},
			{' ', ' ',' '},
			{' ', ' ', ' '}
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
		playerMove(array);
		displayBoard(array);
	}
	




}
