class Solution {
public:
    int smallestEvenMultiple(int n) {
        int num=2;
        for(;num<=1000;num++){
            if(num%2 == 0 && num%n == 0){
                return num;
            }
        }
        
        return -1;
    }
};