//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/
class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* root)
    {
        if(root==NULL)
            return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int t=root->data;
        root->data=l+r;
        return l+r+t;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        int s=solve(node);
    }
};
