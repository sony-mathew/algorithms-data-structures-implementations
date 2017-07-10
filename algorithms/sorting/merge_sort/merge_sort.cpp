#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

void merge(int *a, int p, int q, int r)
{
  int n1 = (q - p + 1), n2 = (r - q);

  int L[n1], M[n2];

  REP(i, n1) L[i] = a[p + i];
  REP(j, n2) M[j] = a[q + j + 1];

  int i = 0, j = 0;

  for(int k = p; k <= r; k++) {
    if ((i < n1) && ((j >= n2) || (L[i] <=  M[j]))) {
      a[k] = L[i];
      ++i;
    }
    else {
      a[k] = M[j];
      j++;
    }
  }
}

void merge_sort(int *a, int p, int r)
{
  if (p < r) {
    int q = (p + r)/2 ;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}

void display_array(int *a, int size)
{
  cout << endl;
  REP(i, size) cout << a[i] << "  ";
  cout << endl;
}

int main()
{
  int *a;
  int size;

  cout << "What size of array do you want? ";
  cin >> size;

  a = new int[size];
  cout << "Enter elements of the array : ";
  REP(i, size) cin >> a[i];

  cout << "Current array : " << endl;
  display_array(a, size);
  
  merge_sort(a, 0, size - 1);

  cout << "Sorted array : " << endl;
  display_array(a, size);
}