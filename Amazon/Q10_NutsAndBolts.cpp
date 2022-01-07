//https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
//The elements should follow the following order ! # $ % & * @ ^ ~ .
//N = 5
//nuts[] = {@, %, $, #, ^}
//bolts[] = {%, @, #, $ ^}
//Output: 
//# $ % @ ^
//# $ % @ ^

int val(char ch)
    {
        switch(ch)
        {
            case '!':
                return 1;
            case '#':
                return 2;
            case '$':
                return 3;
            case '%':
                return 4;
            case '&':
                return 5;
            case '*':
                return 6;
            case '@':
                return 7;
            case '^':
                return 8;
            case '~':
                return 9;
        }
    }
    void quicksort(char* arr,int i,int j)
    {
        if(i>=j)
            return;
        int k=i;
        for(int p=i;p<j;p++)
        {
            if(val(arr[p])<val(arr[j]))
            {
                char ch=arr[k];
                arr[k]=arr[p];
                arr[p]=ch;
                k++;
            }
        }
        char ch=arr[j];
        arr[j]=arr[k];
        arr[k]=ch;
        quicksort(arr,i,k-1);
        quicksort(arr,k+1,j);
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    quicksort(nuts,0,n-1);
	    quicksort(bolts,0,n-1);
	}
	
