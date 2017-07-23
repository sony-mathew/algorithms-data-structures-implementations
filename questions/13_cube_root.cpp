/*
http://www.geeksforgeeks.org/find-cubic-root-of-a-number/
*/

#include <iostream>

using namespace std;


double diff(double x, double y)
{
  if (x > y)
    return x - y;
  else
    return y - x;
}

double cube_root(int n)
{
  double start = 0, end = n;

  // set precision
  double e = 0.0000001;
  
  while(true) {
    
    double mid = (start + end)/2;
    double cube = mid*mid*mid;

    if( diff(n, cube) <= e)
      return mid;

    if (cube > n)
      end = mid;
    else
      start = mid;
  }
}

int main()
{
  int t, n;

  cin >> t;

  while (t--) {
    cin >> n;
    cout << (int)(cube_root(n)) << endl;
  }

  return 0;
}

