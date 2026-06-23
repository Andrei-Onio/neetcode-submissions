class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, x, y;
        for (i  = 0; i < 9; i++){
            for( j = 0; j < 8; j++){
                for( k = j+1; k < 9; k++){
                    if(board[i][j] == board[i][k] && board[i][j] != '.'){
                        return false;
                    }
                    if(board[j][i] == board[k][i] && board[j][i] != '.'){
                        return false;
                    }
                }                
            }

            for( j = 0; j < 9 ; j++){
                int startrow = i - i%3;
                int startcol = j - j%3;

                for(x = 0; x < 3; x++){
                    for(y = 0; y < 3; y++){
                        if(board[i][j] != '.'){
                            if( i != startrow + x && j!= startcol + y){
                                if(board[startrow+x][startcol+y] == board[i][j]){
                                    return false;
                                }
                            }
                        }
                    }
                }
                    
            }
        }
        return true;
    }
};
