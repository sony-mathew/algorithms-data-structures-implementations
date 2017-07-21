/*
https://www.hackerrank.com/challenges/library-query
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int main()
{
  int t, n, q, k, x, y, u_f, count;

  cin >> t;

  REP(i, t) {
    vector<int> shelf;
    cin >> n;
    REP(j, n) {
      cin >> q;
      shelf.push_back(q);
    }
    cin >> q;

    REP(m, q) {
      cin >> u_f;
      if (u_f == 0) {
        cin >> x >> y >> k;
        
        vector<int> sub_shelf;

        for(int z = x - 1; z <= y - 1; ++z)
          sub_shelf.push_back(shelf.at(z));

        sort(sub_shelf.begin(), sub_shelf.end());
        cout << sub_shelf.at(k - 1) << endl;
      }
      else {
        cin >> x >> k;
        shelf[x - 1] = k;
      }
    }
  }
  return 0;
}