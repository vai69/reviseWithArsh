//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
//N = 9, K = 3
//arr[] = 1 2 3 1 4 5 2 3 6
//Output: 
//3 3 4 5 5 5 6 

int height(AVL* root)
    {
        if(!root) return 0;
        return root->height;
    }
    int isBalance(AVL* r)
    {
        
        if (r == NULL)
            return 0;
        int a=height(r->left);
        int b=height(r->right);
        return a-b;
    }
    
    AVL* leftRotate(AVL* root)
    {
        if(root->right==NULL) return rightRotate(root);
        AVL* x=root->right;
        AVL* t=x->left;
        
        x->left=root;
        root->right=t;
        
        root->height=1+max(height(root->left),height(root->right));
        x->height=1+max(height(x->right),height(x->left));
        
        return x;
    }
    AVL* rightRotate(AVL* root)
    {
        if(root->left==NULL)
             return leftRotate(root);
        AVL* x=root->left;
        AVL* t=x->right;
        
        x->right=root;
        root->left=t;
        
        root->height=1+max(height(root->left),height(root->right));
        x->height=1+max(height(x->right),height(x->left));
        
        return x;
    }
    
    AVL* insert(AVL* root,int key)
    {
        if(!root)
        {
            AVL* node=new AVL(key);
            return node;
        }
        if(key<root->key)
        {
            root->left=insert(root->left,key);
        }
        else
        {
            root->right=insert(root->right,key);
        }
        if (root == NULL)
                return root;
        
        root->height=1+max(height(root->right),height(root->left));
        
        int balance=isBalance(root);
        
       if (balance > 1 && key < root->left->key)
        return rightRotate(root);
 
        // Right Right Case
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);
     
        // Left Right Case
        if (balance > 1 && key > root->left->key)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
     
        // Right Left Case
        if (balance < -1 && key < root->right->key)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    
    AVL* getMIN(AVL *root)
    {
        if(root->left==NULL) return root;
        else return getMIN(root->left);
    }
    int getmax(AVL *root)
    {
        if(root->right==NULL) return root->key;
        else return getmax(root->right);
    }
    
   AVL* del(AVL* root,int key)
   {
       if(root==NULL) return root;
       
       if(key<root->key)
       {
           root->left=del(root->left,key);
       }
       else if(key>root->key)
       {
           root->right=del(root->right,key);
       }
       else
       {
           if(root->left==NULL||root->right==NULL)
           {
               AVL* t=(root->left) ? root->left :root->right;
               if(t==NULL)
               {
                   t=root;
                   root=NULL;
               }
               else
                    *root=*t;
                
                delete(t);
           }
           else
           {
               AVL* t=getMIN(root->right);
               root->key=t->key;
               root->right=del(root->right,t->key);
           }
       }
        if (root == NULL)
                return root;
       
       root->height=1+max(height(root->right),height(root->left));
        
        int balance=isBalance(root);
        
       if (balance > 1 && isBalance(root->left)>=0)
        return rightRotate(root);
 
        // Right Right Case
        if (balance < -1 && isBalance(root->right)<=0)
            return leftRotate(root);
     
        // Left Right Case
        if (balance > 1 && isBalance(root->left)<0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
     
        // Right Left Case
        if (balance < -1 && isBalance(root->right)>0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
   }
    
    vector<int> max_of_subarrays(int* arr,int n,int k)
    {
        AVL* root=NULL;
        for(int i=0;i<k;i++)
        {
            root=insert(root,arr[i]);
        }
        vector<int>ans;
        ans.push_back(getmax(root));
        for(int i=k;i<n;i++)
        {
            root=del(root,arr[i-k]);
            root=insert(root,arr[i]);
            ans.push_back(getmax(root));
        }
        return ans;
    }
