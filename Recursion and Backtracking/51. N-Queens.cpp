class Solution {
public:
    // bool isSafe(int row, int col, int n, vector<string>ds){
    //     int r1=row, c1=col;
    //     if(leftRow[])
    //     while(c1>=0){
    //         if(ds[row][c1]=='Q')    return false;
    //         c1--;
    //     }
    //     c1=col;
    //     while(r1>=0 && c1>=0){
    //         if(ds[r1][c1]=='Q') return false;
    //         r1--;
    //         c1--;
    //     }
    //     r1=row;
    //     c1=col;
    //     while(r1<n && c1>=0){
    //         if(ds[r1][c1]=='Q') return false;
    //         r1++;
    //         c1--;
    //     }
    //     return true;
    // }
    void fun(int col, int n, vector<string>ds, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal){
        if(col==n){
            ans.push_back(ds);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                ds[row][col] = 'Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1 + col - row]=1;
                fun(col+1, n, ds, ans, leftRow, upperDiagonal, lowerDiagonal);
                ds[row][col] = '.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1 + col - row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0; i<n; i++)
            s+='.';
        
        vector<string>ds;
        for(int i=0; i<n; i++)
            ds.push_back(s);
        vector<vector<string>>ans;
        vector<int>leftRow(n);
        vector<int>upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1,0);
        fun(0, n, ds, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};
