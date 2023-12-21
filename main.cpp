#include <iostream>
using namespace std;

char player = 'X';
char computer = 'O';
char playerSymbol;
void displayBoard(char setArray[9]) {
	for (int i = 0; i < 9; i++) {
		cout << setArray[i] << " | ";
		if ((i + 1) % 3 == 0) {
			// if reached the final column, begin a new row
			cout << endl;
		}
	}
}

void instructions() {
	cout << "Welcome to tic toe land" << endl;
	cout << "The board is a 3x3 grid and each cell represented by its row number" << endl;
	cout << "To make a move, enter the row number based on the board to place symbol" << endl;
	cout << "Hint: Pick any numbers between 1 - 9 " << endl;
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
	int position;
	cout << "Enter a number based on board position " << endl;
	// this is probably the biggest changes
	// !(cin >> position) will ask the question as part of the loop and it must have an answer
	// to save on checking all positions, just validated numbers below or above 1
	// cin.peek() will check the next character after any numbers to confirm it is a new line, if it is a . for example for a decimal, it will register invalid
	// position != static_cast<int>(position) just makes sure it is a number
	while (!(cin >> position) || position < 1 || position > 9 || cin.peek() != '\n' || position != static_cast<int>(position))
	{
		cout << "Invalid, position has been taken"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	setArray[position - 1] = player;
	return true;

} 

char askPlayer(string question) {
	char response;
	do {
		cout << question;
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}


char playerPiece() {
	char go_first = askPlayer("Do you want to go first? (y / no) ");
	if (go_first == 'y') {
		cout << "Great! You go first" << endl;
		 return player;
	}
	else {
		cout << "Sure, i'll go first" << endl;
		return computer;
	}
}

char opponentPiece(char symbol) {
	if (symbol == player) {
		return computer;
	}
	else {
		return player;
	}
}


// TODO: fix issue with plotting the opposite marker i.e O noughts
bool computerMove(char setArray[9]) {
	int position;
	srand(time(0));

	while (true) {
		position = rand() % 9;
		if (setArray[position] == ' ') {
			setArray[position] = opponentPiece(player);
			return true;
			break;
		}
	}

}
int main()
{	
	char array[9] = {
			' ', ' ', ' ',
			' ', ' ',' ',
			' ', ' ', ' '
	};
	instructions();
	guide(array);
	char human = playerPiece();
	char computer = opponentPiece(human);
	for (int i = 0; i <= 9; i++) {
		playerMove(array);
		computerMove(array);
		displayBoard(array);
	}
	




}
