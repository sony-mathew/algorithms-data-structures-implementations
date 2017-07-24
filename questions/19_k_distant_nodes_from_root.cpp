/*
http://practice.geeksforgeeks.org/problems/k-distance-from-root/1
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
// Recursive function to print right view of a binary tree.
void printKdistance(Node *node, int k)
{
    if (node == NULL)
        return;
    
    if (k == 0)
        cout << node -> data << " ";
  // Your code here
    
    printKdistance(node -> left, k - 1);
    printKdistance(node -> right, k - 1);
}