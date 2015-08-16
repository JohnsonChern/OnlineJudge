#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int i, j, k, n, cl, max_cl;
  char ch;
  while (1) {
    scanf("%d%d", &i, &j);
    max_cl = 0;
    for (k = i; k <= j; k++) {
      cl = 1;
      n = k;
      while (n != 1) {
        if (n % 2 == 0) n = n / 2;
        else  n = 3 * n + 1;
        cl++;
      }
      if (cl > max_cl) max_cl = cl;
    }
    cout << i << ' ' << j << ' ' << max_cl << endl;
    if ((ch = getchar()) == EOF) break;
  }
  return 0;
}