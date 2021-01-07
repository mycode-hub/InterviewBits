    /* Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B. */
    
    
    int m= A.length(),n=B.length();
    if( m+ n != C.length()) 
        return false;
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    //Your code here
    for(int i=0; i<=m ; i++ )
    {
        for(int j=0; j <=n ; j++)
        {
            if( i == 0 && j== 0 )
                dp[i][j] = 1;
            else if( i == 0 )
            {
                if( B[j-1] == C[j-1])
                    dp[i][j] = dp[i][j-1];
            }
            else if ( j == 0 )
            {
                if( A[i-1] == C[i-1])
                    dp[i][j] = dp[i-1][j];
            }
            else if( A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1] ) 
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else if( A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1] ) 
            {
                dp[i][j] = dp[i-1][j]; //|| dp[i][j-1];
            }
            else if( A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1] ) 
            {
                dp[i][j] =  dp[i][j-1];
            }
        }
    }
    return dp[m][n];
