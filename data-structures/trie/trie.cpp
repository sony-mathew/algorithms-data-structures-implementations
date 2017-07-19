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
  // Input keys (use only 'a' through 'z' and lower case)
  char keys[][8] = {"the", "a", "there", "answer", "any",
                   "by", "bye", "their"};

  char output[][32] = {"Not present in trie", "Present in trie"};

  Trie T;

  // Construct trie
  int i;
  REP(i, 8)
    T.insert(keys[i]);

  // Search for different keys
  printf("%s --- %s\n", "the", (T.search("the") ? output[1] : output[0]) );
  printf("%s --- %s\n", "these", (T.search("these") ? output[1] : output[0]) );
  printf("%s --- %s\n", "their", (T.search("their") ? output[1] : output[0]) );
  printf("%s --- %s\n", "thaw", (T.search("thaw") ? output[1] : output[0]) );

  return 0;
}