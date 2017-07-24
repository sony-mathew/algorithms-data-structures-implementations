/*
https://www.hackerrank.com/challenges/ctci-is-binary-search-tree
Ref : http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*/

// it should be integer min & integer max, not hard coded values
bool checkBST(Node* node, int min = -2147483648, int max = 2147483647) {
  if (node == NULL)
    return true;
    
  if (node -> data < min || node -> data > max)
    return false;
   
  return 
    checkBST(node -> left, min, node -> data - 1) && 
    checkBST(node -> right, node -> data + 1, max);
}

//This implementation is also very cool
bool isBST(struct node* root)
{
    static struct node *prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}