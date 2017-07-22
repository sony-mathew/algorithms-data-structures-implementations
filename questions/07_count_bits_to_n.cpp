/*
http://practice.geeksforgeeks.org/problems/count-total-set-bits/0
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

class BIT {
  private:

    int bit_count(int n)
    {
      int count = 0;

      while(n > 0) {
        if (n & 1) {
          ++count;
        }
        n = n >> 1;
      }

      return count;
    }

  public:
    int N[1000], bit[1001];

    BIT()
    {
      REP(i, 1002)
        bit[i] = 0;
    }

    void update(int x, int delta)
    {
      for(; x <= 1000; x += x & -x)
        bit[x] += delta;
    }

    int cumulative_sum(int x)
    {
      int sum = 0;

      for(; x > 0; x -= x & -x)
        sum += bit[x];

      return sum;
    }

    void init()
    {
      REP(i, 1000) {
        N[i] = bit_count(i + 1);
        update(i + 1, N[i]);
      }
    }
};

int main()
{
  int t, n;
  BIT B;

  B.init();

  cin >> t;
  while(t--) {
    cin >> n;
    cout << B.cumulative_sum(n) << endl;
  }
  return 0;
}