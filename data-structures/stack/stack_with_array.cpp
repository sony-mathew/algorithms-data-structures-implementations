#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int MAX_SIZE = 100;

class Stack
{
  public:
    int a[100], size;

    Stack()
    {
      size = 0;
    }

    int push(int item)
    {
      if (size == MAX_SIZE) {
        cout << "Stack Overflow.";
        return MAX_SIZE;
      }

      a[size] = item;
      ++size;
      return size - 1;
    }

    int pop()
    {
      if (size == 0) {
        cout << "Underflow. Stack is empty.";
        return -1;
      }

      --size;

      return a[size];
    }

};

void display_array(int *a, int size)
{
  REP(i, size) cout << a[i] << "   ";
  cout << endl;
}

int main()
{
  Stack s;

  s.push(23);
  s.push(834);
  s.push(-23);
  s.push(89);
  s.push(7);

  display_array(s.a, s.size);

  s.pop();
  display_array(s.a, s.size);
  s.pop();
  display_array(s.a, s.size);

  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();

  return 0;
}