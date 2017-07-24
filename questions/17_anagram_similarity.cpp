/*
https://www.hackerrank.com/challenges/ctci-making-anagrams
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int deletions_needed(string a, string b) {

  int A[26] = {0};
  int index;

  REP(i, a.length()) {
    index = a[i] - 'a';
    ++A[index];
  }

  int count = 0;
  REP(i, b.length()) {
    index = b[i] - 'a';
    if (A[index] > 0)
      --A[index];
    else
      ++count;
  }

  REP(i, 26)
    count += A[i];

  return count;
}

int main() {
  string a, b;

  cin >> a >> b;
  cout << deletions_needed(a, b) << endl;

  return 0;
}