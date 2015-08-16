#include <cstdio>
#include <iostream>
using namespace std;

char puzzle[3][3];
string path = "";
int x_row, x_col;

void FindA(char A, int &row, int &col);
void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();
void MoveA2XY(char A. int X, int Y);
void ReturnA(char A);
int IsReturned(char A);

int main() {

	for(unsigned i = 0; i < 3; ++i) {
		for(unsigned j = 0; j < 3; ++i) {
			cin >> puzzle[i][j];
		}
	}
	FindA('x', x_row, x_col);

	for(unsigned i = 0; i < 5; ++i) {
		ReturnA(i + '1');
	}

	// Decide whether the puzzle is solvable.
	if (x_row == 1) {
		if (puzzle[2][2] == 6) {
			path.append('d');
		}
		else {
			cout << "unsolvable" << endl;
		}
	}
	else {
		switch (x_col) {

			case 0: {
				if (puzzle[2][1] == '7' && puzzle[2][2] == '8') {
					path.append("rr");
					break;
				}
				else {
					cout << "unsolvable" << endl;
					return;
				}
			}

			case 1: {
				if(puzzle[2][0] == '7' && puzzle[2][2] == '8') {
					path.append("r");
					break;
				}
				else {
					cout << "unsolvable" << endl;
				}
			}

			case 2: {
				if (IsReturned('7') && IsReturned('8')) {
					break;
				}
				else {
					cout << "unsolvable" << endl;
					return;
				}
			}
		}

	}


	cout << path << endl;

	return 0;

}

void FindA(char A, int &row, int &col) {

	for(unsigned i = 0; i < 3; ++i) {
		for(unsigned j = 0; j < 3; ++i) {
			if(puzzle[i][j] == A) {
				row = i;
				col = j;
				return;
			}
		}
	}

}

void MoveUp() {

	puzzle[x_row][x_col] = puzzle[x_row - 1][x_col];
	puzzle[x_row - 1][x_col] = 'x';
	x_row--;
	path.append('u');

}

void MoveDown() {

	puzzle[x_row][x_col] = puzzle[x_row + 1][x_col];
	puzzle[x_row + 1][x_col] = 'x';
	x_row++;
	path.append('d');

}

void MoveLeft() {

	puzzle[x_row][x_col] = puzzle[x_row][x_col - 1];
	puzzle[x_row][x_col - 1] = 'x';
	x_col--;
	path.append('l');

}

void MoveRight() {

	puzzle[x_row][x_col] = puzzle[x_row][x_col + 1];
	puzzle[x_row][x_col + 1] = 'x';
	x_col++;
	path.append('r');

}

void ReturnA(char A) {



}

int IsReturned(char A) {

	int row, col;
	FindA(A, row, col);
	
	if ((3*row + col) == (A - '1')) {
		return 1;
	}
	else {
		return 0;
	}

}