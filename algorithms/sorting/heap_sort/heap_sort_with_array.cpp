#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

class Heap
{
  private:
    void swap(int *a, int *b)
    {
      int temp = *a;
      *a = *b;
      *b = temp;
    }

    void max_heapify(int *a, int heapsize, int i)
    {
      int l = (2*i + 1),
          r = (2*i + 2),
          largest = i;

      if (l < heapsize && a[l] > a[largest])
        largest = l;

      if (r < heapsize && a[r] > a[largest])
        largest = r;

      if (largest != i) {
        swap(&a[largest], &a[i]);
        max_heapify(a, heapsize, largest);
      }
    }

    void build_max_heap(int *a, int heapsize)
    {
      for(int i = heapsize/2 - 1; i >= 0; --i)
        max_heapify(a, heapsize, i);
    }

  public:

    Heap(int *a, int size)
    {
      build_max_heap(a, size);
    }

    void sort(int *a, int heapsize)
    {
      int temp;

      for(int i = heapsize - 1; i >= 0; --i) {
        swap(&a[0], &a[i]);

        max_heapify(a, i, 0);
      }
    }
};


void display_array(int *a, int size)
{
  REP(i, size) cout << a[i] << "  ";
  cout << endl;
}

int main()
{
  int *a, size;

  cout << "What size array do you want? ";
  cin >> size;

  a = new int[size];
  cout << "Enter array elements : ";
  REP(i, size) cin >> a[i];

  cout << "Current array : ";
  display_array(a, size);

  Heap arr_heap = Heap(a, size);
  cout << "Array Heap : ";
  display_array(a, size);
  arr_heap.sort(a, size);

  cout << "Sorted array : ";
  display_array(a, size);

  return 0;
}
