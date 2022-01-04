//https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1
//M items are to be delivered in a circle of size N. 
//Find the position where the M-th item will be delivered if we start from a given position K.
int findPosition(int N , int M , int K) {
        int k=N-K+1;
        if(k>M)
        {
            return K+M-1;
        }
        M-=k;
        if(M%N==0) return N;
        else return M%N;
    }
