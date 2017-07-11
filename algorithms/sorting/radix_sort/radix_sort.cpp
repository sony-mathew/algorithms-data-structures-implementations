#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

int get_digit(int num, int pos)
{
  string c = to_string(num);
  if (pos >= c.length()) return 0;
  else {
    int new_pos = c.length() -1 + pos * -1;
    return (c[new_pos] - '0');
  }
}

void counting_sort(int *a, int size, int max, int pos)
{

  int *c = new int[max + 1];
  int *b = new int[size];

  REP(i, max + 1) c[i] = 0;
  REP(j, size) {
    int digit = get_digit(a[j], pos);
    ++c[digit];
  }
  
  for(int i = 0; i <= max; ++i)
    c[i] = c[i] + c[i - 1];

  for(int j = size - 1; j >= 0; --j) {
    int digit = get_digit(a[j], pos);
    b[ c[digit] - 1] = a[j];
    --c[digit];
  }

  REP(i, size) a[i] = b[i];
  delete [] c;
  delete [] b;
}

int get_max(int *a, int size)
{
  int largest = a[0];
  REP(i, size) {
    if (a[i] > largest)
      largest = a[i];
  }
  return largest;
}

void radix_sort(int *a, int size)
{
  int max = get_max(a, size);
  string c = to_string(max);

  REP(i, c.length()) {
    counting_sort(a, size, 9, i);
  }
}

int main()
{
  int a[] = { 1811, 76, 92, 43, 890, 567, 7, 289 };

  radix_sort(a, 8);

  REP(i, 8) cout << a[i] << "  ";
  cout << endl;

  return 0;
}