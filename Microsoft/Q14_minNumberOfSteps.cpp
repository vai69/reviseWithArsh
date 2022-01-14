//https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
//Given an infinite number line. You start at 0 and can go either to the left or to the right. 
//The condition is that in the ith move, you must take i steps. Given a destination D ,
// find the minimum number of steps required to reach that destination.
//Input: D = 2
//Output: 3
//Explaination: The steps takn are +1, -2 and +3.
int minSteps(int D){
        int k=D*2;
        int sq=sqrt(k);
        if(D==2) return 3;
        while(1)
        {
            int p=(sq*(sq-1))/2;
            if(p>=D&&(p-D)%2==0)
                break;
            sq++;
        }
        return sq-1;
    }
