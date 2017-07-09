#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

void bubble_sort(int *arr, int size)
{
  int temp, j;
  REP(i, size) {
    for(j = 0; j < (size - 1) - i ; ++j) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void display_array(int *arr, int size)
{
  REP(i, size) {
    cout << *(arr + i) << "  ";
  }
}

int main()
{ 
  int *arr;
  int size;

  cout << "What size array do you want?" ;
  cin >> size;

  arr = new int[size];

  cout << "Enter the array elements : ";
  REP(i, size) {
    cin >> *(arr + i);
  }

  cout << "Current array is : " << endl;
  display_array(arr, size);

  bubble_sort(arr, size);

  cout << endl << "Sorted array is : " << endl;
  display_array(arr, size);

  return 0;
}