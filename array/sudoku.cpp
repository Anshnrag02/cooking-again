class Solution {
public:

    int val(char c){
        return (int)c-'0';
    };

    bool isValidBox (int x, int y,vector<vector<char>>& board ) {
        vector<bool> v(9,false);
        x = 3*x;
        y = 3*y;
        for(int i = 0 ; i < 3; ++i){
            for(int j=0; j<3; ++j){
                if ((board[i+x][j+y])=='.'){
                    continue;
                }
                if(v[val(board[i+x][j+y])-1]) return false;
                v[val(board[i+x][j+y])-1]=true;
            }
            
        }
        return true;
    };

    bool isValidLine(int offset, bool column, vector<vector<char>>& board){
        vector<bool> v(9,false);
        for(int i = 0 ; i<9; ++i){
            if(column){
                if ((board[offset][i])=='.'){
                    continue;
                }
                if(v[val(board[offset][i])-1]){
                    return false;
                }
                v[val(board[offset][i])-1]=true;
            }
            else {
                if ((board[i][offset])=='.'){
                    continue;
                }
                if(v[val(board[i][offset])-1]){
                    return false;
                } 
                v[val(board[i][offset])-1]=true;
            }
        }
        return true;
    };


    bool isValidSudoku(vector<vector<char>>& board) {

        bool ans=true;
        for(int i = 0 ; i < 9 ; ++i){
            ans = ans && isValidLine (i,false,board) && isValidLine(i, true, board);
        }
        for (int i = 0 ; i < 3 ; ++i){
            for(int j = 0 ; j < 3 ; ++j) {
                ans = ans && isValidBox(i,j,board);
            }
        }
        return ans;
    }
};
