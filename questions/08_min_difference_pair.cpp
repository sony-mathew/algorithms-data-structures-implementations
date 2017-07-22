/*
http://practice.geeksforgeeks.org/problems/minimum-difference-pair/0
*/

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

// void display_array(int *a, int n)
// {
//   cout << "Current array is : " << endl;
//   REP(i, n)
//     cout << a[i] << "  ";
//   cout << endl;
// }

int min_pair(int *a, int size)
{
  int min = numeric_limits<int>::max(), diff;

  // display_array(a, size);
  sort(a, a + size);
  // display_array(a, size);

  REP(i, size - 1) {
    diff = a[i + 1] - a[i];
    if (diff == 0)
      return 0;
    if (diff < min)
      min = diff;
  }
  return min;
}

int main()
{
  int t, n, *a;

  cin >> t;

  while(t--) {
    cin >> n;
    a = new int[n];

    REP(i, n) 
      cin >> a[i];

    cout << min_pair(a, n) << endl;
    delete [] a;
  }

  return 0;
}