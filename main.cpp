#include <iostream>
using namespace std;


void displayBoard() {

	char array[3][3] = {
			{' ', ' ', ' '},
			{' ', ' ',' '},
			{' ', ' ', ' '}
	};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "||" << array[i][j];
		}
		cout << endl;
	}

}

int main()

{	
	displayBoard();




}
