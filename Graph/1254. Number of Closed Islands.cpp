class Solution {
public:
    int row, col;
    void vis(int row1, int col1, vector<vector<int>>& grid){
      if(row1>=row || col1>=col || row1<0 || col1<0)
        return;
      if(grid[row1][col1]==1 || grid[row1][col1]==2)
        return;
      grid[row1][col1]=2;
      vis(row1+1, col1, grid);
      vis(row1, col1+1, grid);
      vis(row1-1, col1, grid);
      vis(row1, col1-1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
      row = grid.size();
      col=grid[0].size();  
      for(int i=0; i<col; i++){
        if(grid[0][i]==0)
          vis(0, i, grid);
      }
        
      for(int i=0; i<col; i++){
        if(grid[row-1][i]==0)
          vis(row-1, i, grid);
      }
      
      for(int i=0; i<row; i++){
        if(grid[i][0]==0)
          vis(i, 0, grid);
      }
      
      for(int i=0; i<row; i++){
        if(grid[i][col-1]==0)
          vis(i, col-1, grid);
      }
      int ans=0;
      for(int i=1; i<row-1; i++){
        for(int j=1; j<col-1; j++){
          if(grid[i][j]==0){
            vis(i, j, grid);
            ans+=1;
          }
        }
      }
      return ans;
    }
};
