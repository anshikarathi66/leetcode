class Solution {
public:
    int countDigits(int num) {
        int countofdigit=0;
        int digit=0;
        int val=num;
        while(val){
            digit=val%10;
            if(num%digit == 0){
                countofdigit++;
            }
            val/=10;
        }
        
        return countofdigit;
    }
};