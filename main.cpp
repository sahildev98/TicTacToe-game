#include <iostream>
using namespace std;


void displayBoard(){

	int row1[3] = {1, 2, 3};
	int row2[3] = {4, 5, 6};
	int row3[3] = { 7, 8, 9 };

	// int array[3][3]

	cout << "\n\t" << row1[0] << "|" << row1[1] << "|" << row1[2] << "|";
	cout << "\n\t" << row2[0] << "|" << row2[1] << "|" << row2[2] << "|";
	cout << "\n\t" << row3[0] << "|" << row3[1] << "|" << row3[2] << "|"<<endl;
}

int main()

{
	
	displayBoard();




}
