#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	int page_num;
	scanf("%d", &page_num);

	while (page_num != 0) {
		
		int **book;
		int sheet_num;
		int remained_page;
		
		sheet_num     = (page_num + 3) / 4;
		remained_page = page_num % 4;
		cout << "Printing order for " << page_num << " pages:" << endl;

		book = (int **) malloc (sheet_num * sizeof(int *));
		for (int i = 0; i < sheet_num; i++) {
			book[i] = (int *) malloc (4 * sizeof(int));
		}
		
		if (sheet_num == 1) {
			switch (page_num) {
				case 1: {
					book[0][0] = 1;
					book[0][1] = 0;
					book[0][2] = 0;
					book[0][3] = 0;
					break;
				}
				case 2: {
					book[0][0] = 1;
					book[0][1] = 2;
					book[0][2] = 0;
					book[0][3] = 0;
					break;
				}
				case 3: {
					book[0][0] = 1;
					book[0][1] = 2;
					book[0][2] = 3;
					book[0][3] = 0;
					break;
				}
				case 4: {
					book[0][0] = 1;
					book[0][1] = 2;
					book[0][2] = 3;
					book[0][3] = 4;
					break;
				}
			}
		}
		else {
			switch (remained_page) {
				case 0: {
					book[0][0] = 1;
					book[0][1] = 2;
					book[0][2] = 4 * sheet_num - 1;
					book[0][3] = 4 * sheet_num;
					book[1][0] = 3;
					book[1][1] = 4;
					book[1][2] = 4 * sheet_num - 3;
					book[1][3] = 4 * sheet_num - 2;
					break;
				}
				case 1: {
					book[0][0] = 1;
					book[0][1] = 2;
					book[0][2] = 0;
					book[0][3] = 0;
					book[1][0] = 3;
					book[1][1] = 4;
					book[1][2] = 4 * sheet_num - 3;
					book[1][3] = 0;
					break;
				}
				case 2: {
					book[0][0] = 1;
					book[0][1] = 2;
					book[0][2] = 0;
					book[0][3] = 0;
					book[1][0] = 3;
					book[1][1] = 4;
					book[1][2] = 4 * sheet_num - 3;
					book[1][3] = 4 * sheet_num - 2; 
					break;
				}
				case 3: {
					book[0][0] = 1;
					book[0][1] = 2;
					book[0][2] = 4 * sheet_num - 1;
					book[0][3] = 0;
					book[1][0] = 3;
					book[1][1] = 4;
					book[1][2] = 4 * sheet_num - 3;
					book[1][3] = 4 * sheet_num - 2;
					break;
				}
			}
		}
		
		for (int i = 2; i < sheet_num; i++) {
			book[i][0] = 2 * i + 1;
			book[i][1] = 2 * i + 2;
			book[i][2] = 4 * sheet_num - 2 * i - 1;
			book[i][3] = 4 * sheet_num - 2 * i;
		}

		for (int i = 0; i < sheet_num; i++) {
			if (book[i][3] == 0) 
				cout << "Sheet " << i + 1 << ", front: Blank, " << book[i][0] << endl;
			else
				cout << "Sheet " << i + 1 << ", front: " << book[i][3] << ", " << book[i][0] << endl;

			if (book[i][1] != 0) {
				if (book[i][2] == 0) {
					cout << "Sheet " << i + 1 << ", back : " << book[i][1] << ", Blank" << endl;
				}
				else {
					cout << "Sheet " << i + 1 << ", back : " << book[i][1] << ", " << book[i][2] << endl;
				}
			}
		}

		scanf("%d", &page_num);
	}

	return 0;

}