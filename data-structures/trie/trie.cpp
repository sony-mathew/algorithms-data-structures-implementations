#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define ALPHABET_SIZE 26
#define TO_INDEX(c) (c - 'a')

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

    bool is_free_node(TrieNode *ptr)
    {
      if (ptr == NULL) return true;

      REP(i, ALPHABET_SIZE)
        if (ptr -> children[i] != NULL)
          return false;

      return true;
    }

    bool recursive_remove(TrieNode *ptr, string key, int level)
    {
      if (ptr) {
        if (level == key.length()) {

          if (ptr -> is_leaf) {

            ptr -> is_leaf = false;
            
            if (is_free_node(ptr))
              return true;
            
            return false; 
          }
        }
        else {

          int index = TO_INDEX(key[level]);

          if (recursive_remove(ptr -> children[index], key, level + 1)) {
            
            delete ptr -> children[index];
            ptr -> children[index] = NULL;

            return (!(ptr -> is_leaf) && is_free_node(ptr));
          }

        }
      }
      return false;
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

        index = TO_INDEX(key[i]);

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

        index = TO_INDEX(q[i]);

        if (ptr -> children[index] == NULL)
          return false;
        
        ptr = ptr -> children[index];
      }
      return ptr -> is_leaf;
    }

    void remove(string key)
    {
      if (key.length() > 0)
        recursive_remove(root, key, 0);
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

  cout << "Removing 'the' from Trie." << endl;
  T.remove("the");
  printf("%s --- %s\n", "the", (T.search("the") ? output[1] : output[0]) );
  printf("%s --- %s\n", "these", (T.search("these") ? output[1] : output[0]) );
  printf("%s --- %s\n", "their", (T.search("their") ? output[1] : output[0]) );
  printf("%s --- %s\n", "thaw", (T.search("thaw") ? output[1] : output[0]) );

  return 0;
}