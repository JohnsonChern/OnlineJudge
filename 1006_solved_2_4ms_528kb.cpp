#include <cstdio>
#include <iostream>
using namespace std;

int main() {
 
 	int is_selfnum;
 	int i, j;
 	for (i = 1; i < 10000; i++) {
 		is_selfnum = 1;
 		
 		for (j = i - 36; j < i; j++) {
 			if (j > 0) {
 				if ((j + j / 1000 + (j / 100) % 10 + (j / 10) % 10 + j % 10) == i) {
 					is_selfnum = 0;
 					break;
 				}
 			}
 		}

 		if (is_selfnum == 1) cout << i << endl;

 	}

 	return 0;

}