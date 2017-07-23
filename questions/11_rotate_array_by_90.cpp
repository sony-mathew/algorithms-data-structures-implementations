/*
http://practice.geeksforgeeks.org/problems/rotate-by-90-degree/0
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n ; ++i)

int A[50][50];

void rotate_by_90(int n)
{
  int temp;

  for(int x = 0; x < n/2; ++x) {
    for(int y = x; y < n - x - 1; ++y) {
      temp = A[x][y];

      A[x][y] = A[y][n - x - 1];

      A[y][n - x - 1] = A[n - x - 1][n - y - 1];

      A[n - x - 1][n - y - 1] = A[n - y - 1][x];

      A[n - y - 1][x] = temp;
    }
  }
}

int main(int argc, char const *argv[])
{
  int t, n;

  cin >> t;

  while (t--) {
    cin >> n;

    REP(i, n)
      REP(j, n)
        cin >> A[i][j];

    rotate_by_90(n);


    REP(i, n)
      REP(j, n)
        cout << A[i][j] << " ";
    cout << endl;
  }
  return 0;
}