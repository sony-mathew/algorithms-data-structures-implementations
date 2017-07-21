/*
Ref :
1. https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/
2. https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

class BIT {

  public:
    int *a, *bit;
    int size;

    BIT(int n)
    {
      size = n;
      a = new int[size];
      bit = new int[size + 1];

      REP(i, size + 1)
        bit[i] = 0;
    }

    void update(int x, int delta)
    {
      for(; x <= size; x += (x & -x) )
        bit[x] += delta;
    }

    int prefix_sum(int x)
    {
      int sum = 0;

      for(; x > 0 ; x -= (x & -x))
        sum += bit[x];

      return sum;
    }

    void show()
    {
      cout << "Current array is : " << endl;
      for(int i = 1; i <= size; ++i)
        cout << bit[i] << "  ";
      cout << endl;
    }
};

int main()
{ 
  int n = 10;
  BIT B(n);

  REP(i, 10) {
    B.a[i] = i + 1;
    B.update(i + 1, B.a[i]);
  }

  B.show();

  cout << "Prefix sum of 5 : " << B.prefix_sum(5) << endl;
  cout << "Prefix sum of 9 : " << B.prefix_sum(9) << endl;

  B.a[1] = 100;
  B.update(2, B.a[1]);

  cout << "Prefix sum of 2 : " << B.prefix_sum(2) << endl;
  B.show();

  cout << "Range sum from 2 - 5 : " << B.prefix_sum(5) - B.prefix_sum(2) << endl;

  return 0;
}