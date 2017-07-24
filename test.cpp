#include <iostream>
#include <limits>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int main()
{
  int a[5] = {0};
  REP(i, 5) cout << a[i] << "  ";

  char c[] = "Sony mathew";
  cout << endl << "Size of string : " << sizeof(c) << endl;

  cout << endl << "Size of a : " << sizeof(a)/sizeof(int) << endl;

  string d = "something else";
  cout << endl << "Size of d : " << d.length() << endl;

  cout << "Max of long long : " << numeric_limits<long long>::max() << endl;
  cout << "Min of long long : " << numeric_limits<long long>::min() << endl;

  cout << "Int min : " << INT_MIN << endl;

  return 0;
}