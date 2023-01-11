class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        set<int>a;
        set<int>b;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    a.insert(i);
                    b.insert(j);
                }
            }
        }
        for(auto it:a){
            for(int i=0; i<n; i++){
                matrix[it][i]=0;
            }
        }
        for(auto it:b){
            for(int i=0; i<m; i++){
                matrix[i][it]=0;
            }
        }
    }
};
