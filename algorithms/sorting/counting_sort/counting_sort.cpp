#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

void counting_sort(int *a, int *b, int k, int size)
{
  int *c;
  c = new int[k + 1];

  REP(i, k + 1) c[i] = 0;
  REP(i, size) ++c[a[i]];

  for(int i = 1; i <= k; i++)
    c[i] = c[i] + c[i - 1];

  for(int j = size - 1; j >= 0; --j) {
    b[c[a[j]] - 1] = a[j];
    --c[a[j]];
  }

  delete [] c;
}

int main()
{
  int a[] = { 23, 120, 54, 11, 8, 67, 3, 1, 48, 77 };
  int b[10];

  counting_sort(a, b, 120, 10);

  REP(i, 10) cout << b[i] << "  ";
  cout << endl;

  return 0;
}