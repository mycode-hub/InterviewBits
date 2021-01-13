/* Asked in:  
Facebook
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

 Note: m and n will be at most 100.  */
 
 int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n=A.size();
    int m =A[0].size();
    if( m == n && m ==1 && A[0][0] == 1)
        return 0;
    vector< vector<int> > dp ( n, vector<int> (m,0));
    dp[n-1][m-1] =  (!A[n-1][m-1]);
    for(int i=m-2;i>=0 ;i--)
    {
            if(A[n-1][i] != 1 )
            dp[n-1][i] = dp[n-1][i+1] ;
    }
    for(int i=n-2;i>=0 ;i--)
    {
            if(A[i][m-1] != 1 )
                dp[i][m-1] = dp[i+1][m-1] ;
    }
    for(int i=n-2;i>=0 ;i--)
    {
         for(int j=m-2;j>=0 ;j--)
        {
            if(A[i][j] != 1 )
            {
            
                dp[i][j] += dp[i+1][j] ;
                dp[i][j] += dp[i][j+1];
            }
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


