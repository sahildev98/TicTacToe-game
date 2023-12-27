#include <iostream>
using namespace std;


char playerSymbol;

class TicTacToe {
private:
	char array[9];
	char currentPlayer;
	char opponent;
	// char computer;
public:
	TicTacToe() : array{ ' ', ' ', ' ',' ', ' ',' ',' ', ' ', ' ' } {
		updateOpponent();
	}

	void SwitchPlayer() {
		if (currentPlayer == 'X') {
			currentPlayer = 'O';
		}
		else {
			currentPlayer = 'X';
		}
	}
	
	void instructions() {
		cout << "Welcome to tic toe land" << endl;
		cout << "The board is a 3x3 grid and each cell represented by its row number" << endl;
		cout << "To make a move, enter the row number based on the board to place symbol" << endl;
		cout << "Hint: Pick any numbers between 1 - 9 " << endl;
	}

	void guide() {
		for (int i = 0; i < 9; i++) {
			cout << i + 1 << " | " << array[i];
			if ((i + 1) % 3 == 0) {
				cout << endl;
			}
		}
	}

	char askPlayer(string question) {
		char response;
		do {
			cout << question;
			cin >> response;
		} while (response != 'y' && response != 'n');

		return response;
	}

	void startGame() {
	 currentPlayer = askPlayer("Do you want to go first? (y/n)") == 'y' ? 'X' : 'O';
	}

	void displayBoard(char setArray[9]) {
		for (int i = 0; i < 9; i++) {
			cout << setArray[i] << " | ";
			if ((i + 1) % 3 == 0) {
				// if reached the final column, begin a new row
				cout << endl;
			}
		}
	}
	bool playerMove(char *array) {
		int position;
		cout << "Enter a number based on board position " << endl;
		// this is probably the biggest changes
		// !(cin >> position) will ask the question as part of the loop and it must have an answer
		// to save on checking all positions, just validated numbers below or above 1
		// cin.peek() will check the next character after any numbers to confirm it is a new line, if it is a . for example for a decimal, it will register invalid
		// position != static_cast<int>(position) just makes sure it is a number
		while (!(cin >> position) || position < 1 || position > 9 || cin.peek() != '\n' || position != static_cast<int>(position))
		{
			cout << "Invalid, position has been taken" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		array[position - 1] = currentPlayer;
		return true;

	}

	bool computerMove(char *array) {
		int position;
		srand(time(0));

		while (true) {
			position = rand() % 9;
			if (array[position] == ' ') {
				array[position] = currentPlayer;
				return true;
				break;
			}
		}
	}

private:
 	void updateOpponent() {
		opponent = (currentPlayer== 'X') ? 'O' : 'X';
	}
	 


};
/*
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
*/
int main()
{
	TicTacToe game;
	game.instructions();
	game.guide();
	game.startGame();
	// char human = playerPiece();
	//char computer = opponentPiece(human);
	/*
	for (int i = 0; i <= 9; i++) {
		playerMove(array);
		computerMove(array);
		displayBoard(array);
	}
	*/

	



}
