#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList
{
  private:

    void remove_single_node(Node *current, Node *prev)
    {
      if (head == current && tail == current)
        head = tail = NULL;
      else if (head == current)
        head = head -> next;
      else if (tail == current) {
        prev -> next = NULL;
        tail = prev;
      } else
        prev -> next = current -> next;

      delete current;
    }

  public:
    Node *head, *tail;

    LinkedList()
    {
      head = NULL;
      tail = NULL;
    }

    Node *new_node(int key)
    {
      Node *n = new Node;
      n -> data = key;
      n -> next = NULL;
      return n;
    }

    void insert_at_start(int key)
    { 
      Node *ptr = new_node(key);
      if (head == NULL && tail == NULL) {
        head = tail = ptr;
      }
      else {
        ptr -> next = head;
        head = ptr;
      }
    }

    void insert_at_end(int key)
    {
      Node *ptr = new_node(key);
      if (head == NULL && tail == NULL) {
        head = tail = ptr;
      }
      else {
        tail -> next = ptr;
        tail = ptr;
      }
    }

    void remove(int key)
    {
      if (head == NULL) {
        cout << "Sorry. LinkedList is empty." << endl;
        return;
      }

      Node *np = head, *prev = head;
      int match = 0;

      while(np != NULL) {
        if (np -> data == key) {
          match = true;
          remove_single_node(np, prev);
        }
        prev = np;
        np = np -> next;
      }

      if (match > 0)
        cout << "The " << match << " number of nodes with key " << key << " removed." << endl;
      else
        cout << "Sorry no nodes have the key " << key << "." << endl;
    }

    void show()
    {
      Node *np = head;
      while(np != NULL) {
        cout << np -> data << "  ";
        np = np -> next;
      }
      cout << endl;
    }
};

int main()
{
  LinkedList l;
  l.insert_at_start(1);
  l.insert_at_start(2);
  l.insert_at_end(3);
  l.insert_at_start(5);
  l.insert_at_end(5);
  l.insert_at_end(78);

  l.show();

  l.remove(67);
  l.remove(3);

  l.show();
  l.remove(5);
  l.show();

  l.remove(2);
  l.show();
}