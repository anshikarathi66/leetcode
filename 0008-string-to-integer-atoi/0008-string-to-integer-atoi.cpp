// class Solution {
// public:
//     int myAtoi(string s) {
//         long int num=0;
//         bool negative = false;
//         int i=0;
        
//         //ignore leading white spaces
//         while(s[i] == ' ') 
//             i++;
        
//         //handle leading negative sign
//         if(s[i] == '-'){
//             negative = true;
//             i++;
//         }
//         if(s[i] == '+'){
//             negative = false;
//             i++;
//         }
        
//         //changing string to digit
//         while(i<s.size()){
//             if(s[i]=='0' ||  s[i]=='1'||  s[i]=='2'|| s[i]=='3'||  s[i]=='4'||  s[i]=='5'||  s[i]=='6'||  s[i]=='7'||  s[i]=='8'||  s[i]=='9'){
//               if(num > LONG_MAX/10 || (num == LONG_MAX/10 && LONG_MAX%10<((int)s[i] - 48))){
//                     num = LONG_MAX;
//                     break;
//                 }
//                 num=num*10+ ((int)s[i] - '0');
//             }
//             else{
//                 break;
//             }
            
//             i++;
                
//         }
        
//         //using negative and returning answer
//         if(negative == true)
//             return -num;
//         return num;
//     }
// };



class Solution {
public:
  int myAtoi(string s) {
      
    const int len = s.size();

    if(len == 0){
        return 0;
    }

    int index = 0;

    // skipping white spaces
    while(index < len && s[index] == ' '){
        ++index;
    }

    // to handle sign cases
    bool isNegative = false;

    if(index < len){

      if(s[index] == '-'){
        isNegative = true;
        ++index;
      } else if (s[index] == '+'){
          ++index;
      }

    }

    int result = 0;

    // converting digit(in character form) to integer form
    // iterate until non-digit character is not found or we can say iterate till found character is a digit
    while(index < len && isDigit(s[index])){

      /* s[index] - '0' is to convert the char digit into int digit eg: '5' - '0' --> 5
      or else it will store the ASCII value of 5 i.e. 53,
      so we do 53(ASCII of 5) - 48(ASCII of 0(zero)) to get 5 as int*/
      int digit = s[index] - '0';

      // to avoid integer overflow
      if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){
          return isNegative ? INT_MIN : INT_MAX;
      }

      result = (result * 10) + digit; // adding digits at their desired place-value

      ++index;
    }
      
    return isNegative ? -result : result;
  }
    
private:
  bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
  }
};