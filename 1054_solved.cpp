#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  long fi[41], num;
  fi[0] = 0;
  fi[1] = 1;
  for (int i = 2; i < 41; i++) {
    fi[i] = fi[i-1] + fi[i-2];
  }
  while (scanf("%ld", &num) != EOF) {
    cout << "The Fibonacci number for " << num << " is " << fi[num] << endl;
  }
  return 0;
}