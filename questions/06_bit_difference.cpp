/*
http://practice.geeksforgeeks.org/problems/bit-difference/0
*/

#include <iostream>

using namespace std;

int bit_count(int n)
{
  int count = 0;
  while(n > 0) {
    if (n & 1) {
      ++count;
    }
    n = n >> 1;
  }
  return count;
}

int main()
{
  int t, a, b;
  
  cin >> t;

  while(t--) {
    cin >> a >> b;
    cout << bit_count(a ^ b) << endl;
  }

  return 0;
}