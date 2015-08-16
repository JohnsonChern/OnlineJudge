#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string dict[100];
int dict_length;
int is_detected;

void Unscramble(string scr_word, string unscr_word);

int main() {

	string scr_word, temp_word;
	string unscr_word = "";

	cin >> temp_word;
	for (dict_length = 0; temp_word != "XXXXXX"; dict_length++) {
		dict[dict_length] = temp_word;
		cin >> temp_word;
	}

	for (int i = 0; i < dict_length; i++) {
		int k = 0;
		for (int j = 0; j < dict_length - i - 1; j++) {
			if (dict[j] > dict[j + 1]) {
				string temp = dict[j + 1];
				dict[j + 1] = dict[j];
				dict[j] = temp;
				k++;
			}
		}
		if (k == 0) 
			break;
	}

	cin >> scr_word;
	while (scr_word != "XXXXXX") {
		is_detected = 0;
		Unscramble(scr_word, unscr_word);
		if (is_detected == 0)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
		cin >> scr_word;
	}

	return 0;

}

void Unscramble(string scr_word, string unscr_word) {

	/* 
	* If only one letter left, add this letter to the end of unscr_word.
	* Then compare the unscr_word with every word in the dictionary.
	* If comparation is OK, print the unscr_word.
	*/
	if (scr_word.length() == 1) {
		unscr_word = unscr_word + scr_word;
		for (int i = 0; i < dict_length; i++) {
			if (unscr_word == dict[i]) {
				cout << unscr_word << endl;
				is_detected = 1;
				break;
			}
		}
	}

	/*
	* If there are more than one letter in scr_word
	*/
	else {
		for (int i = 0; i < scr_word.length(); i++) {
			Unscramble(scr_word.substr(0, i).append(scr_word, i + 1, scr_word.length()), unscr_word.substr().append(scr_word.substr(i, 1)));
		}
	}

}