//https://practice.geeksforgeeks.org/problems/burning-tree/1/
//Given a binary tree and a node called target. Find the minimum time required 
//to burn the complete binary tree if the target is set on fire.
// It is known that in 1 second all nodes connected to a given node get burned. 
// That is its left child, right child, and parent.

unordered_map<Node*,Node*>mp;
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* trgt=NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            if(t->data==target)
            {
                trgt=t;
            }
            if(t->left)
            {
                mp[t->left]=t;
                q.push(t->left);
            }
            if(t->right)
            {
                mp[t->right]=t;
                q.push(t->right);
            }
        }
        q.push(trgt);
        vector<bool>vis(10007,false);
        int ans=0;
        vis[target]=true;
        while(!q.empty())
        {
            ans++;
            int sz=q.size();
            while(sz--)
            {
                Node* t=q.front();
                q.pop();
                if(mp[t]&&!vis[mp[t]->data])
                {
                    vis[mp[t]->data]=true;
                    q.push(mp[t]);
                }
                if(t->left && !vis[t->left->data])
                {
                    vis[t->left->data]=true;
                    q.push(t->left);
                }
                if(t->right && !vis[t->right->data])
                {
                    vis[t->right->data]=true;
                    q.push(t->right);
                }
            }
        }
        return ans-1;
    }
