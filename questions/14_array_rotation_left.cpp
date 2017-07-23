/*
https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int A[100000];

int main()
{
  int n, d, index;

  cin >> n >> d;

  REP(i, n) {
    index = ((i - d >= 0) ? (i - d) : n + (i - d));
    cin >> A[index];
  }
  REP(i, n)
    cout << A[i] << " ";
}