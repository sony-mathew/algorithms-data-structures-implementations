#include <iostream>

using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

class BinarySearchTree
{
  private:
    Node *new_node(int key)
    {
      Node *n = new Node;
      
      n -> key = key;
      n -> parent = NULL;
      n -> left = NULL;
      n -> right = NULL;

      return n;
    }

    void transplant(u, v)
    {
      if (u -> parent == NULL)
        root = v;
      else if (u == u -> parent -> left)
        u -> parent -> left = v;
      else
        u -> parent -> right = v;

      if (v != NULL)
        v -> parent = u -> parent;
    }

  public:
    Node *root;

    BinarySearchTree()
    {
      root = NULL;
    }

    void insert(int key)
    {
      Node *z = new_node(key);

      Node *y = NULL;
      Node *x = root;

      while(x != NULL) {
        y = x;
        if (z -> key < x -> key )
          x = x -> left;
        else
          x = x -> right;
      }

      z -> parent = y;

      if (y == NULL)
        root = z;
      else if (z -> key < y -> key)
        y -> left = z;
      else
        y -> right = z;

    }

    void remove(int key)
    {
      Node *z  = search(key);

      if (z == NULL) {
        cout << "There is no node with the key " << key << ".";
        return
      }

      if (z -> left == NULL)
        transplant(z, z -> right);
      else if (z -> right == NULL)
        transplant(z, z -> left);
      else {
        y = min(z -> right)
        if (y -> parent != z) {
          transplant(y, y -> right);
          y -> right = z -> right;
          y -> right -> parent = y;
        }
        transplant(z, y);
        y -> left = z -> left;
        y -> left -> parent = y;
      }
    }

    Node * search(int key, Node *x = root)
    {
      if (x == NULL || x -> key == key)
        return x;

      if (key < x -> key)
        return search(key, x -> left);
      else
        return search(key, x -> right);
    }

    Node * min(Node *x = root)
    {
      while (x -> left != NULL)
        x = x -> left;

      return x;
    }

    Node * max(Node *x = root)
    {
      while ( x -> right != NULL)
        x = x -> right;

      return x;
    }

    Node * successor(Node *x)
    {
      if (x -> right != NULL)
        return min(x -> right);

      Node *y = x -> parent;

      while( y != NULL && x == y -> right) {
        x = y;
        y = y -> parent;
      }

      return y;
    }

    void inorder_walk(Node *n = root)
    {
      if (n != NULL) {
        inorder_tree_walk(n.left);
        cout << n.key << "  ";
        inorder_tree_walk(n.right);
      }
    }
};