//https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
//Input:
//       5
//    /    \
//  -10     3
// /   \   /  \
// 9   8 -4    7
//X = 7
//Output: 2

int solve(Node* root, int &c,int x)
{
    if(root==NULL)
        return 0;
    int l=solve(root->left,c,x);
    int r=solve(root->right,c,x);
    
    if(l+r+root->data==x)
        c++;
    return l+r+root->data;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int c=0;
    int s=solve(root,c,X);
    
    return c;
}
