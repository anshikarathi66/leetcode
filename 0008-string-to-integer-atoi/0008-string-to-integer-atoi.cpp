class Solution {
public:
    int myAtoi(string s) {
        long long num=0;
        bool negative = false;
        int i=0;
        
        //ignore leading white spaces
        while(s[i] == ' ') 
            i++;
        
        //handle leading negative sign
        if(s[i] == '-'){
            negative = true;
            i++;
        }
        else if(s[i] == '+'){
            negative = false;
            i++;
        }
        
        //changing string to digit
        while(i<s.size()){
            if(s[i]>='0' && s[i]<='9'){
              if(num > INT_MAX/10 || (num == INT_MAX/10 && INT_MAX%10<(s[i] - '0'))){
                    
                  return negative ? INT_MIN : INT_MAX;
                }
                num=num*10+ (s[i] - '0');
            }
            else{
                break;
            }
            
            i++;
                
        }
        
        //using negative and returning answer
        if(negative == true)
            return -num;
        return num;
    }
};