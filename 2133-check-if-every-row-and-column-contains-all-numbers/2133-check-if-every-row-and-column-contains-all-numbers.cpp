class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_map<int,bool> checkRow;
        unordered_map<int,bool> checkCol;
        
        for(int i = 0;i<matrix.size();i++){
            for(int j =0;j<matrix.size();j++){
                if(matrix[i][j] < 1 || matrix[i][j] > matrix.size() || matrix[j][i] < 1 || matrix[j][i] > matrix.size()){
                    return false;
                }
                else if(checkRow[matrix[i][j]] == true || checkCol[matrix[j][i]] == true){
                    return false;
                }
                else{
                    checkRow[matrix[i][j]] = true;
                    checkCol[matrix[j][i]] = true;
                }
            }
            if(checkRow.size() != matrix.size() || checkCol.size() != matrix.size()){
                return false;
            }
            checkRow.clear();
            checkCol.clear();
        }
        
        return true;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int rowSum=0;
//         int n = matrix.size();
//         int idealSum = (n * (n+1))/2;
        
//         for(int i =0;i<n;i++){
//             rowSum=0;
//             for(int j=0;j<n;j++){
//                 rowSum += matrix[i][j];
//             }
//             if(rowSum != idealSum){
//                 return false;
//             }
//         }
        
//         int colSum=0;
//         for(int i =0;i<n;i++){
//             colSum=0;
//             for(int j=0;j<n;j++){
//                 colSum+=matrix[j][i];
//             }
//             if(colSum != idealSum){
//                 return false;
//             }
//         }
//         return true;
    }
};