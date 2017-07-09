#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

int binary_search(int *ar, int size, int item)
{
  int start = 0, end = size - 1, mid, current_item;
  while(start <= end) {
    
    mid = (int)((start + end)/2);
    current_item = *(ar + mid);

    if (current_item == item) return mid;
    else if (item > current_item) start = mid + 1;
    else end = mid - 1;
  }
  return -1;
}

void bubble_sort(int *ar, int size)
{ 
  int i, j, temp;
  REP(i, size) {
    for(j = 1; j <= (size - 1) - i; j++) {
      if(ar[j-1] > ar[j]) {
        temp = ar[j];
        ar[j] = ar[j-1];
        ar[j-1] = temp;
      }
    }
  }
}

void display_array(int *ar)
{
  int i = 0;
  cout << endl << "The current array is : " << endl;
  while(*(ar + i)) {
    cout << *(ar+i) << "  ";
    i++;
  }
  cout << endl;
}

int main()
{
  int size, item, item_pos;
  int *ar;
  char ch;

  cout << "Size of array : ";
  cin >> size;
  ar = new int[size];

  cout << "Enter the array elements : " << endl;
  REP(i, size) {
    cin >> *(ar + i);
  }

  display_array(ar);
  bubble_sort(ar, size);
  display_array(ar);

  do {
    cout << "Enter the item to search : ";
    cin >> item;

    item_pos = binary_search(ar, size, item);
    if (item_pos == -1) cout << "Result not found" << endl;
    else cout << "Item found at : " << item_pos << endl;

    cout << "Do you want to search more? (y/n)";
    cin >> ch;
  } while(ch == 'y' || ch == 'Y');

  return 0;
}