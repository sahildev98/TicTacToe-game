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

bool playerMove(char setArray [3][3], int row, int col, char playerSymbol) {
	if (setArray[row][col] == ' ') {
		setArray[row][col] = playerSymbol;
		return true;
	}
	else {
		cout << "Invalid, position has been taken";
		return false;
	}
} 

void makeMove(char setArray[3][3]) {
	int row; 
	int col;
	do
	{
		cout << "Enter a row to place your marker on the board";
		cin >> col;
		cout << "Enter which column to place your marker on the board";
		cin >> row;
	} while (row < 0 || row >=3 || col < 0 || col>=3 );
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
	char askUser = askPlayer();
	if (askUser == 'y') {
		cout << "Great! You go first?";
	}
	else {
		cout << "Sure, i'll go first";
	}
	instructions();
	displayBoard(array);




}
