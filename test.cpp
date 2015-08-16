#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {

	string text = "text";
	text = text.substr(0, 1).append(text, 2, text.length());
	cout << text << text.length() << endl;

	return 0;

}