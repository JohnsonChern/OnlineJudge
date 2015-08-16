#include <cstdio>
#include <iostream>
using namespace std;

int main() {
 
 	int a[10000];
 	for (int i = 1; i < 10000; i++) {
 		a[i] = 0;
 	}

 	for (int i = 1; i < 10000; i++) {
 		int num = i + i / 1000 + (i / 100) % 10 + (i / 10) % 10 + i % 10;
 		if (num < 10000)
 			a[num] = 1;
 	}

 	for (int i = 1; i < 10000; i++) {
 		if (a[i] == 0)
 			cout << i << endl;
 	}

 	return 0;

}