//https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/

//There are N stairs, and a person standing at the bottom wants to reach the top.
// The person can climb either 1 stair or 2 stairs at a time. Count the number of ways,
//  the person can reach the top (order does not matter).
//Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.
long long countWays(int m)
    {
        long long ans=m/2+1;
        return ans;
    }
