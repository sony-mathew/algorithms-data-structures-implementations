#include <iostream>
#include <istream>

using namespace std;

bool uniqueCheck(char *s) 
{
  bool arr[128] = { false };
  for(int i = 0; *(s+i); i++) {
    int c = *(s+i);
    cout << c << " :: " << arr[c] << endl;
    if (arr[c]) return false;
    arr[c] = true;
  }
  return true;
}

int main(void)
{
  char *s;
  cin >> s;
  cout << (uniqueCheck(s) ? "Unique" : "Not unique");
  return 0;
}