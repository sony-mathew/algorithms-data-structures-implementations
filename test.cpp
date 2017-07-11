#include <iostream>

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

  return 0;
}