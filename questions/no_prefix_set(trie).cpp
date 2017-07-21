/*
https://www.hackerrank.com/challenges/no-prefix-set
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define ALPHA_COUNT 10
#define TO_INDEX(c) (c - 'a')

struct Node {
  int count;
  bool leaf;
  Node *children[ALPHA_COUNT];
};

class Trie {
  private:
    Node * new_node()
    {
      Node * n = new Node;

      REP(i, ALPHA_COUNT) n -> children[i] = NULL;
      n -> count = 0;
      n -> leaf = false;

      return n;
    }

  public:
    Node *root;

    Trie()
    {
      root = new_node();
    }

    bool insert(string key)
    {
      int index;
      Node *ptr = root;

      REP(i, key.length()) {
        index = TO_INDEX(key[i]);
        
        if (ptr -> leaf)
          return false;

        if (ptr -> children[index] == NULL)
          ptr -> children[index] = new_node();

        ptr = ptr -> children[index];
        ++ (ptr -> count);
      }
      ptr -> leaf = true;
      if (ptr -> count > 1) return false;
      return true;
    }
};


int main()
{
  int n;
  string key;
  bool check = true;
  Trie T;

  cin >> n;

  REP(i, n) {
    cin >> key;
    check = T.insert(key);

    if (!check) {
      cout << "BAD SET" << endl << key << endl;
      return 0;
    }
  }

  cout << "GOOD SET" << endl;
  return 0;
}