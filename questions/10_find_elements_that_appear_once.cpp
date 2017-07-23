/*
1. http://practice.geeksforgeeks.org/problems/alone-in-couple/0
2. http://www.geeksforgeeks.org/find-the-element-that-appears-once/
*/

#include <iostream>
#include <stack>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

// cout << bitset< 16 >(num);

int main()
{
  /*
  Answer for Q1
  int t, n, a, b = 0;

  cin >> t;

  while(t--){
    cin >> n;

    REP(i, n){
      cin >> a;
      b = b ^ a;
    }

    cout << b << endl;
  }
  */

  int t, n, a, ones = 0, twos = 0, common_bit_mask;

  cin >> t;

  while(t--) {
    cin >> n;

    REP(i, n){
      cin >> a;
      
      twos = twos | (a & ones);
      ones = ones ^ a;

      common_bit_mask = ~(ones & twos);

      ones &= common_bit_mask;
      twos &= common_bit_mask;
    }

    cout << ones << endl;
  }

  return 0;
}