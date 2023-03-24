class Solution {
public:
  
      ///////////MEMORIZARION/////////
    // int fun(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
    //   if(j<0){
    //     return i+1;
    //   }
    //   if(i<0){
    //     return j+1;
    //   }
    //   if(dp[i][j]!=-1)
    //     return dp[i][j];
    //   if(s1[i]==s2[j])
    //     return dp[i][j] = 0 + fun(i-1, j-1, s1, s2, dp);
    //   int ins=501, del=501, rep=501;
    //   ins = 1 + fun(i, j-1, s1, s2, dp);
    //   del = 1 + fun(i-1, j, s1, s2, dp);
    //   rep = 1 + fun(i-1, j-1, s1, s2, dp);
    //   return dp[i][j] = min(ins, min(del, rep));
    // }
    // int minDistance(string word1, string word2) {
    //   int n1=word1.size(), n2=word2.size();
    //   vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
    //   return fun(word1.size()-1, word2.size()-1, word1, word2, dp);
    // }
  
  
  ///////////Tabulaataion//////////////
  int minDistance(string word1, string word2) {
    int n1=word1.size(), n2=word2.size();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
    for(int i=0; i<=n1; i++){
      dp[i][0]=i;
    }
    for(int j=0; j<=n2; j++){
      dp[0][j]=j;
    }
    for(int i=1; i<=n1; i++){
      for(int j=1; j<=n2; j++){
        if(word1[i-1]==word2[j-1]){
          dp[i][j] = 0 + dp[i-1][j-1];
        }
        else{
          dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
      }
    }
    return dp[n1][n2];
  }
};
