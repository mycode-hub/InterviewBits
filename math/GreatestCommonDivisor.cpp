 /* Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 
 NOTE : DO NOT USE LIBRARY FUNCTIONS */
 
 
 int Solution::gcd(int A, int B) {              // one solution   tc= O(log min(a,b))
    if(A==0)
        return B;
    if(B==0)
        return A;
    if(A==B)
        return A;
    if(A>B)
        return gcd(A-B,B);
     return gcd(A,B-A);
    
}

int Solution::gcd(int A, int B) {           // solution 2     
   
     if(A>B)
        swap(A,B);
     if(A==0)
        return B;
        return gcd(B%A,A);
}








