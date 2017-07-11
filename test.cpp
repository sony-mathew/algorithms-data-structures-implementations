#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int main()
{
  int a[5] = {0};

  REP(i, 5) cout << a[i] << "  ";
  return 0;
}