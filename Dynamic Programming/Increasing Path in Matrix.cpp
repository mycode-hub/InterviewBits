/* 
Problem Description

Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.


Problem Constraints
1 <= N, M <= 103

1 <= A[i][j] <= 108



Input Format
First and only argument is an 2D integer matrix A of size N x M.



Output Format
Return a single integer denoting the length of longest path in the matrix if no such path exists return -1.



Example Input
Input 1:

 A = [  [1, 2]
        [3, 4]
     ]
Input 2:

 A = [  [1, 2, 3, 4]
        [2, 2, 3, 4]
        [3, 2, 3, 4]
        [4, 5, 6, 7]
     ]


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 Longest path is either 1 2 4 or 1 3 4.
Explanation 2:

 Longest path is 1 2 3 4 5 6 7. */
 
 int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m =A[0].size();
    vector< vector<int> > dp ( n, vector<int> (m,0));
    
    dp[n-1][m-1] =1;
    for(int i=n-2;i>=0 ;i--)
    {
        if(A[i][m-1] < A[i+1][m-1] )
            dp[i][m-1] = dp[i+1][m-1] ;
    }
    for(int i=m-2;i>=0 ;i--)
    {
        if(A[n-1][i+1] > A[n-1][i] )
            dp[n-1][i] = dp[n-1][i+1] ;
    }
    
    for(int i=n-2;i>=0 ;i--)
    {
         for(int j=m-2;j>=0 ;j--)
        {
            if(A[i][j] < A[i+1][j])
                dp[i][j] = dp[i][j] | dp[i+1][j];
                
            if(A[i][j] < A[i][j+1])
                dp[i][j] = dp[i][j] | dp[i][j+1];
          //  cout<<dp[i][j]<<" ";
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
    if(dp[0][0] != 1)
        return -1;
    return (n+m-1);
}
