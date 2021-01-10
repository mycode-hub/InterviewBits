/* sked in:  
Amazon
Problem Description

Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time.



Input Format
First and only argument is an 2D integer array A of size M x N.



Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).



Example Input
Input 1:

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]


Example Output
Output 1:

 9


Example Explanation
Explanation 1:

 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8  */
 
 int Solution::minPathSum(vector<vector<int> > &A) {
    int n=A.size();
    int m =A[0].size();
    vector< vector<int> > dp ( n, vector<int> (m,0));
    dp[n-1][m-1] = A[n-1][m-1];
    for(int i=n-2;i>=0 ;i--)
    {
            dp[i][m-1] = A[i][m-1] + dp[i+1][m-1] ;
    }
    for(int i=m-2;i>=0 ;i--)
    {
            dp[n-1][i] = A[n-1][i]  + dp[n-1][i+1] ;
    }
    for(int i=n-2;i>=0 ;i--)
    {
         for(int j=m-2;j>=0 ;j--)
        {
                dp[i][j] = A[i][j] + min( dp[i][j+1], dp[i+1][j] );
        }
        //cout<<"\t";
    }
    // for(int i=0;i<n ;i++)
    // {
    //     for(int j=0;j<m ;j++)
    //     {
            
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\t";
    // }
    return dp[0][0];
}

 
 
