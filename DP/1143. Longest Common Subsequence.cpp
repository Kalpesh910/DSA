class Solution {
public:
  
      // MEMORIZATION
//     int fun(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>&dp){
//       if(ind1<0 || ind2<0)
//         return 0;
//       if(dp[ind1][ind2]!=-1)
//         return dp[ind1][ind2];
//       if(s1[ind1]==s2[ind2]){
//         return dp[ind1][ind2]=1+fun(ind1-1, ind2-1, s1, s2, dp);
//       }
//       return dp[ind1][ind2]=max(0+fun(ind1-1, ind2, s1, s2, dp), 0+fun(ind1, ind2-1, s1, s2, dp));
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//       vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
//       return fun(text1.size()-1, text2.size()-1, text1, text2, dp);
//     }
  
  
  
  
  
    // int longestCommonSubsequence(string text1, string text2) {
    //   string s1, s2; 
    //   if(text1.size()>text2.size()){
    //      s1=text1;
    //      s2=text2;
    //    }
    //   else{
    //     s1=text2;
    //     s2=text1;
    //   }
    //   vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1));
    //   bool flag=false;
    //   for(int i=0; i<s2.size(); i++){
    //     if(s1[0]==s2[i]){
    //       dp[0][i]=1;
    //       while(i<s2.size()){
    //         dp[0][i]=1;
    //         i++;
    //       }
    //     }
    //   }
    //   for(int i=0; i<s1.size(); i++){
    //     if(s2[0]==s1[i]){
    //       dp[i][0]=1;
    //       while(i<s1.size()){
    //         dp[i][0]=1;
    //         i++;
    //       }
    //     }
    //   }
    //   for(int i=1; i<s1.size(); i++){
    //     for(int j=1; j<s2.size(); j++){
    //       if(s1[i]==s2[j]){
    //         dp[i][j] = dp[i-1][j-1]+1;
    //       }
    //       else{
    //         dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    //       }
    //     }
    //   }
    //   return dp[s1.size()-1][s2.size()-1];
    // }
};
