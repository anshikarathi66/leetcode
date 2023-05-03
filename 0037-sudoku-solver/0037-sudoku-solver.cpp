class Solution {
public:
    bool isSafe(int row,int col, vector<vector<char>> &board,int val){
        for(int i=0;i<board[0].size();i++){
            //already in row
            if(board[row][i] == val){
                return false;
            }
            //already in col
            if(board[i][col] == val){
                return false;
            }
            //already in grid
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
                return false;
            }
        }
        return true;
    }

    
    bool solve(vector<vector<char>> &board){
        int n = board[0].size();
        
        for(int row = 0;row<n;row++){
            for(int col = 0 ; col<n;col++){
                //if empty cell
                if(board[row][col] == '.'){
                    for(int val = '1';val<='9';val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col] = val;
                            
                            //recursive call
                            bool solPossibleAhead = solve(board);
                            if(solPossibleAhead){
                                return true;
                            }
                            //backtrack
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    //means that no sol possible for any value between 1-9
                    return false;
                }
            }
        }
        //means we have got the solution somehow
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};