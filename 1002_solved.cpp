#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int i, j, bigger, minor, k, n, cl, max_cl;
  while (scanf("%d%d", &i, &j) != EOF) {
    max_cl = 0; 
    if (i > j) {
      bigger = i;
      minor = j;
    }
    else {
      bigger = j;
      minor = i;
    }
    for (k = minor; k <= bigger; k++) {
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
  }
  return 0;
}
