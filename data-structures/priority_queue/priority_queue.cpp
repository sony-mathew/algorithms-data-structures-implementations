#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

void display_array(int *a, int size);

class MaxHeap
{
  private:
    void swap(int p, int q)
    {
      int temp = a[p];
      a[p] = a[q];
      a[q] = temp;
    }

    void heapify(int i)
    {
      int l = (2*i + 1),
          r = (2*i + 2),
          largest = i;

      if (l < size && a[l] > a[largest]) largest = l;
      if (r < size && a[r] > a[largest]) largest = r;

      if (largest != i) {
        swap(i, largest);
        heapify(largest);
      }

    }

    void increase_key(int i, int key)
    {
      if (key < a[i]) {
        cout << "Key less than value.";
        return;
      }
      a[i] = key;
      int parent = i/2;
      while( i > 0 && a[parent] < a[i]) {
        swap(i, parent);
        i = parent;
        parent = i/2;
      }
    }

  public:
    int a[100], size;

    MaxHeap()
    {
      size = 0;
    }

    void build_heap(int *b, int n)
    {
      size = n;
      REP(i, size) a[i] = b[i];

      for(int i = size/2 - 1; i >= 0; --i)
        heapify(i);
    }

    int max()
    {
      if (size < 1) {
        cout << "Heap is empty.";
        return -1;
      }
      return a[0];
    }

    int extract_max()
    {
      if (size < 1) {
        cout << "Heap is empty.";
        return -1;
      }

      int max = a[0];
      
      a[0] = a[size - 1];
      --size;
      heapify(0);

      return max;
    }

    void insert(int key)
    {
      a[size] = key;
      ++size;
      increase_key(size - 1, key);
    }
};

void display_array(int *a, int size)
{
  REP(i, size) cout << a[i] << "   ";
  cout << endl;
}

int main()
{
  int a[] = { 21, 3, 34, 56, 78, 11, 6, 90, 19, 87};

  MaxHeap h;
  h.build_heap(a, 10);

  cout << "After heap building : " << endl;
  display_array(h.a, h.size);

  cout << "Insert 191 : " << endl;
  h.insert(191);
  display_array(h.a, h.size);

  cout << "Max : " << h.max() << endl;

  cout << "Insert 42 : " << endl;
  h.insert(42);
  display_array(h.a, h.size);

  cout << "Extract max : " << h.extract_max() << endl;
  display_array(h.a, h.size);

  return 0;
}