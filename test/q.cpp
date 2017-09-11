#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

struct Node {
  bool is_socket;
  long n;
    
  Node(bool s, long d) {
      is_socket = s;
      n = d;
  }
};

long to_index(long x, long y, long n) {
    long d = 0;
    if (x == 0)
      d = y;
    else if (y == 0)
      d = n + x;
    else if (y == 5)
      d = 2*n + x;
    else if (x == 5)
      d = 3*n + y;
    
    return d;
}

int main() {
    long n;
    long m;
    long k;
    cin >> n >> m >> k;
    
    ++n;

    long *a = new long[4*n];
    
    for(long i = 0; i < 4*n ; ++i)
        a[i] = 0;
    
    for(long a0 = 0; a0 < m; a0++){
        long x;
        long y;
        cin >> x >> y;
        ++a[to_index(x, y, n)];
    }
    // Write Your Code Here

    vector<Node> actual;
    long seq = 0;
    for(long i = 0; i < 4*n; ++i) {
        if (seq == 0)
            ++seq;
        else {
            if(seq > 0)
                actual.push_back(Node(false, seq));
            actual.push_back(Node(true, a[i]));
            seq = 0;
        }
    }
    
    long min_time = long_MAX, actual_size = actual.size();
    for(long i = 0; i < actual_size; ++i) {
        if (!actual[i].is_socket)
            continue;
        
        long s_count = 0, time_count = 0;
        for(long j = i; j < actual_size + i; ++j) {
            
            if (actual[j % actual_size].is_socket)
              s_count += actual[j % actual_size].n;
            else
              time_count += actual[j % actual_size].n;
            
            if (s_count >= k)
              break;
        }

        if (time_count < min_time)
            min_time = time_count;
    }
    
    cout << min_time << endl;
    
    return 0;
}
