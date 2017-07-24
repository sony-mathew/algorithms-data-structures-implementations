#include <iostream>
#include <limits>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

void display_array(int *a, int size) {
  cout << "The array is : " << endl;
  REP(i, size)
    cout << a[i] << "  ";
  cout << endl;
}

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

  int A[26] = {0};
  display_array(A, 26);

  cout << "Find max : " << max(25, 30) << endl;

  return 0;
}