#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

void selection_sort(int *ar, int size)
{
  int smallest, pos, j;
  REP(i, size - 1) {
    
    smallest = ar[i];
    pos = i;

    for(j = i + 1; j < size; j++) {
      if (smallest > ar[j]) {
        smallest = ar[j];
        pos = j;
      }
    }

    if (pos != i) {
      ar[pos] = ar[i];
      ar[i] = smallest;
    }
  }
}

void display_array(int *ar, int size)
{
  REP(i, size) {
    cout << ar[i] << "  ";
  }
}

int main()
{
  int *ar;
  int size;

  cout << "What size arrray do you want?";
  cin >> size;

  ar = new int[size];
  cout << "Enter the array elemnets : ";
  REP(i, size)
    cin >> ar[i];

  cout << "The current array is : " << endl;
  display_array(ar, size);

  selection_sort(ar, size);

  cout << endl << "The sorted array is : " << endl;
  display_array(ar, size);
}