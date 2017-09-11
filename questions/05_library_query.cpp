/*
https://www.hackerrank.com/challenges/library-query
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define MAXN 100100

int main()
{
  int t, n, q, k, x, y, u_f;
  int a[10001];

  cin >> t;

  while(t--) {
    cin >> n;

    REP(i, n)
      cin >> a[i];
    
    cin >> q;

    REP(m, q) {
      
      cin >> u_f;

      if (u_f == 0) {
        cin >> x >> y >> k;
        
        vector<int> sub_shelf;
        bool done_heapify = false;

        for(int z = x - 1, j = 0; z <= y - 1; ++z) {
          if (j < k) {
            sub_shelf.push_back(a[z]);
            ++j;
          }
          else {
            if (!done_heapify) {
              make_heap(sub_shelf.begin(), sub_shelf.end());
              done_heapify = true;
            }

            if (a[z] <= sub_shelf.front()) {
              pop_heap(sub_shelf.begin(), sub_shelf.end());
              sub_shelf.push_back(a[z]);
              push_heap(sub_shelf.begin(), sub_shelf.end());
            }
          }
        }

        if (!done_heapify)
          make_heap(sub_shelf.begin(), sub_shelf.end());

        cout << sub_shelf.front() << endl;
      }
      else {
        cin >> x >> k;
        a[x - 1] = k;
      }
    }
  }
  return 0;
}