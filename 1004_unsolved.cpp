#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

void whereis(int **bw, int n, int a, int &row, int &col);

int main() {
  int n, a, b;
  int **bw;
  string s1, s2;
  
  cin >> n;
  bw = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < 5; i++)
    bw[i] = (int *)malloc(n * sizeof(int));
  
  for (int i = 0; i < n; i++) {
    bw[i][0] = i;
    for (int j = 1; j < n; j++) {
      bw[i][j] = -1;
    }
  }
  
  while (1) {
    cin >> s1;
    if (s1 == "quit") break;
    cin >> a >. s2 >> b;
    if (a == b) continue;
  
    int a_row, a_col;
    int b_row, b_col;
    whereis(bw, n, a, a_row, a_col);
    whereis(bw, n, b, b_row, b_col);
    if (a_row == b_row) continue;
    
    if (s1 == "move") {
      
      if (s2 == "onto") { // move a onto b
        
      }
      
      else {              // move a over b
        
      }
      
    }
    else {   
      
      if (s2 == "onto") { // pile a onto b
        
      }
      
      else {              // pile a over b
        
      }
      
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << i << ':';
    if (bw[i][0] != -1) {
      cout << ' ';
    }
    for (int j = 0; bw[i][j] != -1; j++) {
      cout << " " << bw[i][j];
    }
    cout << endl;
  }
  
  return 0;
}

void whereis(int **bw, int n, int a, int &row, int &col) {
  row = 0;
  col = 0;
  while (row < n)
}
