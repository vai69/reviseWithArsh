//https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
//N = 3
//matrix[][] = [[1 2 3],
//              [4 5 6],
//              [7 8 9]]
//Output:
//3 6 9 
//2 5 8 
//1 4 7
void rotate(vector<vector<int> >& mat)
{
    int N=mat.size();
    for (int x = 0; x < N / 2; x++) {
        for (int y = x; y < N - x - 1; y++) {
            int temp = mat[x][y];
            mat[x][y] = mat[y][N - 1 - x];
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
            mat[N - 1 - y][x] = temp;
        }
    }
}
