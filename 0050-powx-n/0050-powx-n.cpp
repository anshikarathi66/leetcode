class Solution {
public:
    double myPow(double x, int n) {       
        n>=0? x=x : x=1/x;
        n= abs(n);
        //base case
        if(n == 0)
            return 1;
        
        //recursive call
        if(n%2 == 0){ 
            return myPow(x*x , n/2);
        }
        else{
            return x*myPow(x*x , n/2);
        }
        
    }
};