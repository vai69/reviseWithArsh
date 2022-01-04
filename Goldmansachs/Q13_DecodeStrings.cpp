//https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
//An encoded string (s) is given, the task is to decode it. 
//The pattern in which the strings were encoded were as follows
//original string: abbbababbbababbbab 
//encoded string : 3[a3[b]1[ab]]



string decodedString(string s){
        stack<char>st;
        string res="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==']')
            {
                string tmp="";
                while(!st.empty()&&st.top()!='[')
                {
                    tmp=st.top()+tmp;
                    st.pop();
                }
                if(!st.empty()&&st.top()=='[') st.pop();
                string n="";
                while(!st.empty()&&isdigit(st.top()))
                {
                    n=st.top()+n;
                    st.pop();
                }
                int rt=stoi(n);
                string k="";
                for(int j=0;j<rt;j++)
                {
                    k+=tmp;
                }
                for(auto x:k)
                    st.push(x);
                    
            }
            else
                st.push(s[i]);
        }
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
