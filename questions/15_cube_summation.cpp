/*
https://www.hackerrank.com/challenges/cube-summation/problem
*/

#include <iostream>

using namespace std;

#define REP(i, n, start) for(int i = start; i < n; ++i)

typedef long long ll;

ll A[101][101][101];

class BIT {

  public:
    ll BIT_3D[101][101][101], size;

    BIT(int n)
    {
      size = n;
      REP(i, size + 1, 0) {
        REP(j, size + 1, 0) {
          REP(k, size + 1, 0) {
            A[i][j][k] = 0;
            BIT_3D[i][j][k] = 0;
          }
        }
      }
    }

    ll cumulative_sum(int x, int y, int z)
    {
      ll sum = 0;

      for(; z > 0 ; z -= z & -z)
        sum += BIT_3D[x][y][z];

      return sum;
    }

    void update(int x, int y, int z, int delta)
    {
      for(; z <= size; z += z & -z)
        BIT_3D[x][y][z] += delta;
    }

    ll query(int x1, int y1, int z1, int x2, int y2, int z2)
    {
      ll sum = 0;
      for(int i = x1; i <= x2 ; ++i) {
        for(int j = y1; j <= y2; ++j) {
          sum += cumulative_sum(i, j, z2);
          if (z1 > 1) {
            sum -= cumulative_sum(i, j, z1 - 1);
          }
        }
      }

      return sum;
    }
};

void display_arrays(BIT *B, int size) {
  cout << "Array A is : " << endl;
  REP(i, size + 1, 1) {
    cout << i << ": [";
    REP(j, size + 1, 1) {
      cout << j << ": {";
      REP(k, size + 1, 1) {
        cout << A[i][j][k] << " ";
      }
      cout << "} ";
    }
    cout << "]";
  }

  cout << endl << "Array BIT is  : " << endl;
  REP(i, size + 1, 1) {
    cout << i << ": [";
    REP(j, size + 1, 1) {
      cout << j << ": {";
      REP(k, size + 1, 1) {
        cout << B -> BIT_3D[i][j][k] << " ";
      }
      cout << "} ";
    }
    cout << "] ";
  }
  cout << endl;
}

int main()
{
  int t, n, m;
  string query;

  cin >> t;

  while(t--) {
    cin >> n >> m;

    BIT B = BIT(n);

    REP(i, m, 0) {
      // display_arrays(&B, n);

      cin >> query;

      if(query[0] == 'U') {
        int x, y, z;
        
        cin >> x >> y >> z;
        ll delta = -1*A[x][y][z];
        // B.update(x, y, z, -1*A[x][y][z]);

        cin >> A[x][y][z];
        delta += A[x][y][z];

        B.update(x, y, z, delta);
      }
      else {
        int  x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        cout << B.query(x1, y1, z1, x2, y2, z2) << endl;
      }
    }

  }

  return 0;
}