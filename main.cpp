#include <iostream>
using namespace std;


class TicTacToe {
private:
	// private variables for encapsulation
	char array[9];
	char currentPlayer;
	char opponent;
public:
	TicTacToe() : array{ ' ', ' ', ' ',' ', ' ',' ',' ', ' ', ' ' } {
		updateOpponent();
	}

	// instructions and guide provide infomation for the user. 
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

	// start of the game
	void startGame() {
		currentPlayer = askPlayer("Do you want to go first? (y/n) ") == 'y' ? 'X' : 'O';
		if (currentPlayer == 'X') {
			cout << "Smart choice? you have chosen X as your marker."<<endl;
		}
		if (currentPlayer == 'O') {
			cout << "Computer has started the game. GOOD LUCK!"<<endl;
			performComputer();
			displayBoard();
		}
	}

	void displayBoard() {
		for (int i = 0; i < 9; i++) {
			cout << array[i] << " | ";
			if ((i + 1) % 3 == 0) {
				// if reached the final column, begin a new row
				cout << endl;
			}
		}
	}

	// methods for abstraction  
	void performPlayer() {
		playerMove(array);

	}

	void performComputer() {
		computerMove(array);
	}

	bool verifyWinner() {
		return checkWinner(array, currentPlayer, opponent);
	}

private:
	// private methods for encapsulation
	char updateOpponent() {
		opponent = (currentPlayer == 'X') ? 'O' : 'X';
		return opponent;

	}

	bool playerMove(char* array) {
		int position;
		int* positionPtr = &position;
		cout << "Enter a number based on board position " << endl;
		// this is probably the biggest changes
		// !(cin >> position) will ask the question as part of the loop and it must have an answer
		// to save on checking all positions, just validated numbers below or above 1
		// cin.peek() will check the next character after any numbers to confirm it is a new line, if it is a . for example for a decimal, it will register invalid
		// position != static_cast<int>(position) just makes sure it is a number
		while (!(cin >> *positionPtr) || *positionPtr < 1 || *positionPtr > 9 || cin.peek() != '\n' || *positionPtr != static_cast<int>(*positionPtr))
		{
			cout << "Invalid, position has been taken" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		array[*positionPtr - 1] = currentPlayer;
		return true;

	}

	bool computerMove(char* array) {
		int position;
		int* positionPtr = &position;
		srand(time(0));

		while (true) {
			*positionPtr = rand() % 9;
			if (array[*positionPtr] == ' ') {
				array[*positionPtr] = updateOpponent();
				return true;
				break;
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

	bool checkWinner(char* array, char player, char computer) {
		// rows
		if ((array[0] != ' ') && (array[0] == array[1]) && array[1] == array[2])
		{
			array[0] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE "<<computer << " IS THE WINNER" << endl;
		}
		else if ((array[3] != ' ') && (array[3] == array[4]) && array[4] == array[5])
		{
			array[3] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER"<< endl;
		}
		else if ((array[6] != ' ') && (array[6] == array[7]) && array[7] == array[8])
		{
			array[6] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER" << endl;
		}
		// columns
		if ((array[0] != ' ') && (array[0] == array[3]) && array[3] == array[6])
		{
			array[0] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER" << endl;
		}
		else if ((array[1] != ' ') && (array[1] == array[4]) && array[4] == array[7])
		{
			array[1] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER" << endl;
		}
		else if ((array[2] != ' ') && (array[2] == array[5]) && array[5] == array[8])
		{
			array[0] == player ? cout << player << "IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER" << endl;
		}
		//diagonals
		else if ((array[0] != ' ') && (array[0] == array[4]) && array[4] == array[8])
		{
			array[0] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER"<< endl;
		}
		else if ((array[2] != ' ') && (array[2] == array[4]) && array[4] == array[6])
		{
			array[2] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER" << endl;
		}
		else if ((array[6] != ' ') && (array[6] == array[4]) && array[4] == array[2])
		{
			array[6] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER" << endl;
		}
		else if ((array[8] != ' ') && (array[8] == array[4]) && array[4] == array[0])
		{
			array[8] == player ? cout << player << " IS THE WINNER" << endl : cout << "YOU LOSE " << computer << " IS THE WINNER" << endl;
		}
		else {
			return false;
		}

		return true;

	}

};
int main()
{
	// game object
	TicTacToe game;
	bool running = true;
	// game begins in main 
	game.instructions();
	game.guide();
	game.startGame();
	
	// while loop to run the game whislt a winner has been declared. 
	// There is a bug in this functionality as certain game scenarios do not provide expected outcome.
	while (running) {
		game.performPlayer();
		game.performComputer();
		game.displayBoard();
		if (game.verifyWinner()) {
			break;
		}
	}
	
}
