/*
https://www.hackerrank.com/challenges/library-query
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define MAXN 100100

class BIT {

  public:
    int a[1000], bit[1001];
    int size;

    BIT()
    {
      REP(i, 1001)
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

    int cumulative(int x, int y)
    {
      return prefix_sum(y) - prefix_sum(x);
    }

    int kth_item(int x, int y, int k)
    {
      
    }
};

int main()
{
  int t, n, q, k, x, y, u_f;

  cin >> t;

  while(t--) {
    cin >> n;

    BIT B;
    REP(x, n) {
      cin >> q;
      B.a[x] = q;
      B.update(x + 1, B.a[x]);
    }
    B.size = n;
    cin >> q;

    REP(m, q) {
      cin >> u_f;
      if (u_f == 0) {
        cin >> x >> y >> k;
        cout << B.kth_item(x, y, k) << endl;
      }
      else {
        cin >> x >> k;
        B.update(x, -B.a[x - 1]);
        B.a[x - 1] = k;
        B.update(x, B.a[x - 1]);
      }
    }
  }
  return 0;
}