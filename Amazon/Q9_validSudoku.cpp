//https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1
//Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix(mat[][]) 
//the task to check if the current configuration is valid or not where a 0 represents an empty block.

int isValid(vector<vector<int>> mat){
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < 9; ++ i)
            for(int j = 0; j < 9; ++ j)
                if(mat[i][j] != 0)
                {
                    int num = mat[i][j]  - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
