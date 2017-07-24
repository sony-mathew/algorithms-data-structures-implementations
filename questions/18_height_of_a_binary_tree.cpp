/*
http://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the height of binary tree with given root.  */
int height(Node* node)
{
   // Your code here
    if (node == NULL)
        return 0;
    else
        return max(height(node -> left), height(node -> right)) + 1;
}