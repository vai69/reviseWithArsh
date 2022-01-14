//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/
//       10                       10 ------> NULL
//      / \                       /      \
//     3   5       =>     3 ------> 5 --------> NULL
//    / \     \               /  \           \
//   4   1   2          4 --> 1 -----> 2 -------> NULL
class Solution
{
    public:
   void connect(Node *root)
    {
        queue <Node*> q;
        q.push(root);
        Node* prev=NULL;
        Node* end = root, *nextend;
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left) 
            { 
                q.push(temp->left);
                nextend = temp->left;
            }
            if(temp->right)
            { 
                q.push(temp->right);
                nextend = temp->right;
            }
            if(prev) 
            prev->nextRight = temp;
            
            if(temp == end)
            {
                temp->nextRight = NULL;
                prev = NULL;
                end = nextend;
            }
            else 
            prev = temp;
        }
    }
    

      
};
