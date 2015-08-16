#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int i, t, num;
  float fl;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> num;
    fl = sqrt(num);
    printf("%100f\n", fl);
  }
  return 0;
}