#include <cstdio>
#include <iostream>
using namespace std;

int main() {

	int key;
	scanf("%d", &key);

	while (key != 0) {
		
		string ciphertext, plaintext;
		cin >> ciphertext;

		int n = ciphertext.length();
		int *plaincode, *ciphercode;
		plaincode  = new int[n];
		ciphercode = new int[n];

		// translate ciphertext into ciphercode
		for (int i = 0; i < n; i++) {
			if (ciphertext.at(i) == '_') {
				ciphercode[i] = 0;
			}
			else if (ciphertext.at(i) == '.') {
				ciphercode[i] = 27;
			}
			else {
				ciphercode[i] = ciphertext.at(i) - 'a' + 1;
			}
		}

		// untwist ciphercode to plaincode
		for (int i = 0; i < n; i++) {
			int plaintext_num = (key * i) % n;
			for (int j = 0, temp;; j++) {
				temp = (ciphercode[i] - j * 28) + i;
				if (temp >= 0 && temp <= 27) {
					plaincode[plaintext_num] = temp;
					break;
				}
			}
		}

		// translate plaincode to plaintext
		for (int i = 0; i < n; ++i) {
			if (plaincode[i] == 0) {
				plaintext.insert(plaintext.end(), '_');
			}
			else if (plaincode[i] == 27) {
				plaintext.insert(plaintext.end(), '.');
			}
			else {
				plaintext.insert(plaintext.end(), plaincode[i] + 'a' - 1);
			}
		}

		// print the plaintext
		cout << plaintext << endl;

		scanf("%d", &key);

	}


	return 0;

}