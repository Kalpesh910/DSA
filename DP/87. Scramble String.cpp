class Solution {
public:
    bool fun(string a, string b, unordered_map<string, bool>&dp){
      if(a == b)
        return true;
      if(a.length()<=1)
        return false;
      string key = a + " " + b;
      if(dp.find(key)!=dp.end())
        return dp[key];
      int n=a.length();
      for(int i=1; i<n; i++){
        if(fun(a.substr(0, i), b.substr(n-i, i), dp) && fun(a.substr(i, n-i), b.substr(0, n-i), dp))
          return dp[key] =  true;
        if(fun(a.substr(0, i), b.substr(0, i), dp) && fun(a.substr(i, n-i), b.substr(i, n-i), dp))
          return dp[key] = true;
      }
      return dp[key] = false;
    }
    bool isScramble(string s1, string s2) {
      if(s1.length()!=s2.length())
        return false;
      unordered_map<string, bool>dp;
      return fun(s1, s2, dp);
    }
    // int fun(string a, string b, map<pair<string, string>, int>& dp){
    //   if(a == b)
    //     return dp[{a, b}] = 1;
    //   if(a.length()<=1)
    //     return dp[{a, b}] = -1;
    //   if(dp[{a, b}]!=0)
    //     return dp[{a, b}];
    //   int n=a.length();
    //   for(int i=1; i<n; i++){
    //     int u = fun(a.substr(0, i), b.substr(n-i, i), dp);
    //     int v = fun(a.substr(i, n-i), b.substr(0, n-i), dp);
    //     if(u==1 && v==1)
    //       return 1;
    //     int x = fun(a.substr(0, i), b.substr(0, i), dp);
    //     int y = fun(a.substr(i, n-i), b.substr(i, n-i), dp);
    //     if(x==1 && y==1)
    //       return 1;
    //   }
    //   return dp[{a, b}] = -1;
    // }
    // bool isScramble(string s1, string s2) {
    //   if(s1.length()!=s2.length())
    //     return false;
    //   map<pair<string, string>, int>dp;
    //   if(fun(s1,s2,dp)==1)
    //     return true;
    //   return false;
    // }
};
