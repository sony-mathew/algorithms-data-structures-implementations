/*
https://www.hackerrank.com/challenges/contacts
*/

#include <iostream>
#include <cstring>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define ALPHABET_SIZE 26
#define TO_INDEX(c) int(c - 'a')

struct Node {
  bool is_leaf;
  int count;
  Node *children[ALPHABET_SIZE];
};

class Trie {
  private:
    Node * new_node()
    {
      Node *n = new Node;
      
      REP(i, ALPHABET_SIZE)
        n -> children[i] = NULL;

      n -> is_leaf = false;
      n -> count = 0;

      return n;
    }

    bool is_free_node(Node *ptr)
    {
      REP(i, ALPHABET_SIZE)
        if (ptr -> children[i])
          return false;
      return true;
    }

    Node * prefix_node(Node *ptr, char *str, int level, int length)
    {
      if (ptr) {
        if (level == length)
          return ptr;
        else {
          int index = TO_INDEX(str[level]);
          return prefix_node(ptr -> children[index], str, level + 1, length);
        }
      }
      return NULL;
    }

    int count_children(Node *ptr, int count)
    {
      if (!ptr) return 0;

      if (ptr -> is_leaf) ++count;

      REP(i, ALPHABET_SIZE)
        count += count_children(ptr -> children[i], 0);

      return count;
    }

  public:

    Node *root;

    Trie()
    {
      root = new_node();
    }

    void insert(char *key, int length)
    {
      int index;
      Node *ptr = root;
      REP(i, length) {
        index = TO_INDEX(key[i]);

        if (ptr -> children [index] == NULL)
          ptr -> children [index] = new_node();

        ptr = ptr -> children[index];
        ++(ptr -> count);
      }
      ptr -> is_leaf = true;
    }

    int prefix_search(char *str, int length)
    {
      Node *prefix_match_node = prefix_node(root, str, 0, length);
      if (prefix_match_node)
        return prefix_match_node -> count;
      else
        return 0;
    }

};

int main()
{
  int n, length;
  char str[5], key[500];
  Trie T;

  cin >> n;

  REP(i, n) {
    cin >> str;
    cin >> key;

    length = strlen(key);

    if (str[0] == 'a')
      T.insert(key, length);
    else
      cout << T.prefix_search(key, length) << endl;
  }

  return 0;
}