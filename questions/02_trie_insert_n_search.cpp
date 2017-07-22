/*
http://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define ALPHABET_SIZE 26

struct TrieNode {
  TrieNode *children[ALPHABET_SIZE];
  bool is_leaf;
} temp_node;

class Trie {

  private:
    TrieNode * new_node()
    {
      TrieNode *n = new TrieNode;

      REP(i, ALPHABET_SIZE) n -> children[i] = NULL;
      n -> is_leaf = false;

      return n;
    }

    int char_to_index(char b)
    {
      return (int)(b - 'a');
    }

  public:
    TrieNode *root;

    Trie()
    {
      root = new_node();
    }

    void insert(string key)
    {
      TrieNode * ptr = root;
      int index;

      REP(i, key.length()) {

        index = char_to_index(key[i]);

        if (ptr -> children[index] == NULL)
          ptr -> children[index] = new_node();
        
        ptr = ptr -> children[index];
      }
      ptr -> is_leaf = true;
    }

    bool search(string q)
    {

      TrieNode * ptr = root;
      int index;

      REP(i, q.length()) {

        index = char_to_index(q[i]);

        if (ptr -> children[index] == NULL)
          return false;
        
        ptr = ptr -> children[index];
      }
      return ptr -> is_leaf;
    }
};

int main()
{
  int t, n;
  string str;
  Trie T;

  cin >> t;

  REP(i, t) {
    cin >> n;

    REP(i, n) {
      cin >> str;
      T.insert(str);
    }

    cin >> str;

    cout << (T.search(str) ? 1 : 0) << endl;
  }

  return 0;
}