//https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
//n = 3
//contact[] = {"geeikistest", "geeksforgeeks", 
//"geeksfortest"}
//s = "geeips"
//Output:
//geeikistest geeksforgeeks geeksfortest
//geeikistest geeksforgeeks geeksfortest
//geeikistest geeksforgeeks geeksfortest
//geeikistest
//0
//0

struct T{
    T* child[26];
    bool isEnd;
    T(){
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;   
        }
        isEnd=false;
    }
};

class Solution{
public:
    void insert(T *root,string key)
    {
        T* tmp=root;
        for(int i=0;i<key.length();i++)
        {
            int ind=key[i]-'a';
            if(!tmp->child[ind])
                tmp->child[ind]=new T();
            tmp=tmp->child[ind];
        }
        tmp->isEnd=true;
    }
    
    void display(T* root,string pre,vector<string>&k)
    {
        if(!root) return;
        if(root->isEnd)
        {
            k.push_back(pre);
        }
        T* tmp=root;
        for(int i=0;i<26;i++)
        {
            char ch=i+'a';
            if(tmp->child[i])
                display(tmp->child[i],pre+ch,k);
        }
        return;
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        T *root=new T();
        //cout<<root->isEnd;
        vector<vector<string>>ans;
    //     vector<string>k;
    //     for(int i=0;i<s.length();i++)
    //   { k.push_back("0");
    //     ans.push_back(k);}
        for(int i=0;i<n;i++)
            insert(root,contact[i]);
        T* tmp=root;
        int flg=0;
        for(int i=0;i<s.length();i++)
        {
            vector<string>k;
            int ind=s[i]-'a';
            if(flg==0&&tmp->child[ind])
            {
                string str=s.substr(0,i+1);
                tmp=tmp->child[ind];
                display(tmp,str,k);
                
            }
            else
            {
                flg=1;
                k.push_back("0");
            }
            
             ans.push_back(k);
            
            
        }
        return ans;
    }
