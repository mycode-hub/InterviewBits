/*Asked in:  
Qualcomm
Amazon
Microsoft
Goldman Sachs
Problem Description

Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
The only argument given is integer array A.



Output Format
Return the total water it is able to trap after raining.



Example Input
Input 1:

 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2:

 A = [1, 2]


Example Output
Output 1:

 6
Output 2:

 0


Example Explanation
Explanation 1:

 
 In this case, 6 units of rain water (blue section) are being trapped.
Explanation 2:

 No water is trapped.*/
 
 int Solution::trap(const vector<int> &A) {
    int  *maxl =new int [A.size()];
    int *maxr =new int [A.size()];
    int n=A.size();
    maxl[0]=A[0];
    maxr[n-1]=A[n-1];
    for(int i=1;i<n;i++)
    {
        maxl[i] = max(A[i],maxl[i-1]);
        maxr[n-1-i] = max(A[n-1-i], maxr[n-i]);
        
    }
    cout<<"maxr" << maxr[0]<<" ";
    int x=0,sum=0;
    for(int i=0;i<n;i++)
    {
        int x = min(maxl[i] ,maxr[i] ) -A[i];
        cout<<x<<" ";
        if(x>0)
            sum+=x;
    }    
    return sum;
}
