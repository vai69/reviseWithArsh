//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
//Input:
//r = 4, c = 4
//matrix[][] = {{1, 2, 3, 4},
//           {5, 6, 7, 8},
//           {9, 10, 11, 12},
//           {13, 14, 15,16}}
//Output: 
//1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        // code here 
        vector<int>v;
        int rs=0,re=r;
        int cs=0,ce=c;
        while(rs<re&&cs<ce)
        {
            for(int i=cs;i<ce;i++)
            {
                v.push_back(m[rs][i]);
            }
            rs++;
                for(int i=rs;i<re;i++)
                {
                    v.push_back(m[i][ce-1]);
                }
                ce--;
                if(rs<re)
                {for(int i=ce-1;i>=cs;i--)
                    v.push_back(m[re-1][i]);
                    re--;
                }
                if(cs<ce)
                {for(int i=re-1;i>=rs;i--)
                {
                    v.push_back(m[i][cs]);
                }
                    cs++;
                }
                
        }
        
        return v;
    }
