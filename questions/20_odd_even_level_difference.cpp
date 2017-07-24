/*
http://practice.geeksforgeeks.org/problems/odd-even-level-difference/1
*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this function*/

int levelDiff(Node *node, int k = 1) {
    int diff = 0;
    
    if(node == NULL)
        return 0;
    
    int left = levelDiff(node -> left, k + 1);
    int right = levelDiff(node -> right, k + 1);
    int total = left + right;
    
    if (k % 2 == 0)
        diff = total - node -> data;
    else
        diff = total + node -> data;
        
    return diff;
}

int getLevelDiff(Node *node)
{
   return levelDiff(node);
}

// optimal cool answer found in solutions
// The main function that return difference between odd and even level
// nodes
int getLevelDiff(struct node *root)
{
   // Base case
   if (root == NULL)
         return 0;
 
   // Difference for root is root's data - difference for
   // left subtree - difference for right subtree
   return root->data - getLevelDiff(root->left) - 
                                         getLevelDiff(root->right);
}
