class Solution {
public:
    // bool isPossible(int i, int j, int k, vector<vector<char>>& board){
    //   for(int x=0; x<9; x++){
    //     if(board[i][x]==k+'0')
    //       return false;
    //     if(board[x][j]==k+'0')
    //       return false;
    //   }
    //   int x=i, y=j;
    //   if(x%3==0 && y%3==0){
    //     if(board[x+1][y+1]==k+'0')
    //       return false;
    //     if(board[x+2][y+2]==k+'0')
    //       return false;
    //     if(board[x+1][y+2]==k+'0')
    //       return false;
    //     if(board[x+2][y+1]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==0 && y%3==1){
    //     if(board[x+1][y-1]==k+'0')
    //       return false;
    //     if(board[x+1][y+1]==k+'0')
    //       return false;
    //     if(board[x+2][y-1]==k+'0')
    //       return false;
    //     if(board[x+2][y+1]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==0 && y%3==2){
    //     if(board[x+1][y-2]==k+'0')
    //       return false;
    //     if(board[x+1][y-1]==k+'0')
    //       return false;
    //     if(board[x+2][y-2]==k+'0')
    //       return false;
    //     if(board[x+2][y-1]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==1 && y%3==0){
    //     if(board[x-1][y+1]==k+'0')
    //       return false;
    //     if(board[x-1][y+2]==k+'0')
    //       return false;
    //     if(board[x+1][y+1]==k+'0')
    //       return false;
    //     if(board[x+1][y+2]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==1 && y%3==1){
    //     if(board[x-1][y-1]==k+'0')
    //       return false;
    //     if(board[x-1][y+1]==k+'0')
    //       return false;
    //     if(board[x+1][y-1]==k+'0')
    //       return false;
    //     if(board[x+1][y+1]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==1 && y%3==2){
    //     if(board[x-1][y-1]==k+'0')
    //       return false;
    //     if(board[x-1][y-2]==k+'0')
    //       return false;
    //     if(board[x+1][y-1]==k+'0')
    //       return false;
    //     if(board[x+1][y-2]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==2 && y%3==0){
    //     if(board[x-2][y+1]==k+'0')
    //       return false;
    //     if(board[x-1][y+1]==k+'0')
    //       return false;
    //     if(board[x-2][y+2]==k+'0')
    //       return false;
    //     if(board[x-1][y+2]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==2 && y%3==1){
    //     if(board[x-2][y-1]==k+'0')
    //       return false;
    //     if(board[x-2][y+1]==k+'0')
    //       return false;
    //     if(board[x-1][y-1]==k+'0')
    //       return false;
    //     if(board[x-1][y+1]==k+'0')
    //       return false;
    //   }
    //   else if(x%3==2 && y%3==2){
    //     if(board[x-2][y-2]==k+'0')
    //       return false;
    //     if(board[x-2][y-1]==k+'0')
    //       return false;
    //     if(board[x-1][y-2]==k+'0')
    //       return false;
    //     if(board[x-1][y-1]==k+'0')
    //       return false;
    //   }
    //   return true;
    // }
  
    bool isPossible(int i, int j, int k, vector<vector<char>>& board){
        for(int x=0; x<9; x++){
          if(board[i][x]==k+'0')
            return false;
          if(board[x][j]==k+'0')
            return false;
  *********************************************************
          if(board[3*(i/3)+x/3][3*(j/3)+x%3]==k+'0')
            return false;
  *********************************************************      
        }
      return true;
    }
    bool solve(vector<vector<char>>& board){
      for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
          if(board[i][j]=='.'){
            for(int k=1; k<=9; k++){
              if(isPossible(i, j, k, board)){
                board[i][j]=k+'0';
                if(solve(board))
                  return true;
                else{
                  board[i][j]='.';
                }
              }
            }
            if(board[i][j]=='.')
              return false;
          }
        }
      }
      return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
