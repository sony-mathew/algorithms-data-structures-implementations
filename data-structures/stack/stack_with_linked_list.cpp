#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int MAX_SIZE = 100;

struct Node {
  int data;
  Node *next;
};

class Stack
{
  public:
    Node *top;

    Stack()
    {
      top = NULL;
    }

    int push(int item)
    {
      Node *n = new Node;

      n->data = item;
      n->next = NULL;

      if (top == NULL)
        top = n;
      else {
        Node *save = top;
        top = n;
        n->next = save;
      }

      return item;
    }

    int pop()
    {
      if (top == NULL) {
        cout << "Underflow. Stack is empty." << endl;
        return -1;
      }

      Node *ptr = top;
      int top_item = ptr->data;
      top = top->next;

      delete ptr;

      return top_item;
    }

};

void display_stack(Node *np)
{ 
  while(np != NULL) {
    cout << (np -> data) << "  ";
    np = np -> next;
  }
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

  display_stack(s.top);

  s.pop();
  display_stack(s.top);
  s.pop();
  display_stack(s.top);

  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();

  return 0;
}