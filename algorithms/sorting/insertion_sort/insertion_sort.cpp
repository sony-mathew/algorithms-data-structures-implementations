#include <iostream>

using namespace std;

#define REP(i, start, n) for(int i = start; i < n; i++)

void insertion_sort(int *ar, int size)
{
  int key, ptr;
  REP(i, 1, size) {
    key = ar[i];
    ptr = i - 1;
    while(ptr >= 0 && key < ar[ptr]) {
      ar[ptr + 1] = ar[ptr];
      --ptr;
    }
    ar[ptr + 1] = key;
  }
}

void display_array(int *ar, int size)
{
  REP(i, 0, size) cout << ar[i] << "  ";
  cout << endl;
}

int main()
{
  int *ar, size;

  cout << "What size of array do you want? ";
  cin >> size;

  ar = new int[size];
  cout << "Enter the array : ";
  REP(i, 0, size) cin >> ar[i];

  cout << "Current array : " << endl;
  display_array(ar, size);

  insertion_sort(ar, size);

  cout << "Sorted array : " << endl;
  display_array(ar, size);

  return 0;
}