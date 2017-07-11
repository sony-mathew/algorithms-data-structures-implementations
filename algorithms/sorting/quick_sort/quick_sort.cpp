#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *a, int p, int r)
{
  int x = a[r];
  int i = p - 1;

  for(int j = p; j < r; ++j) {
    if (a[j] <= x) {
      swap(&a[j], &a[++i]);
    }
  }

  swap(&a[++i], &a[r]);
  return i;
}

void quick_sort(int *a, int p, int r)
{
  if (p < r) {
    int q = partition(a, p, r);
    quick_sort(a, p, q - 1);
    quick_sort(a, q + 1, r);
  }
}

int main()
{
  int a[] = { 32, 45, 50, 1, -4, 67, 8, 49 };
  quick_sort(a, 0, 7);

  REP(i, 8) cout << a[i] << "  ";
  cout << endl;

  return 0;
}