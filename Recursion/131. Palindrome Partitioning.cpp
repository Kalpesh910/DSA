class Solution {
public:
    // TC: O( (2^n) *k*(n/2) )
            // O(2^n) to generate every substring
            // O(n/2)  to check if the substring generated is a palindrome. 
            // O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.
    // SC: O(k * x)
    // ASC: O(n);
    bool check(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    void fun(int ind, int n, string s, vector<string>&ds, vector<vector<string>>&ans){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<n; i++){
            if(check(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                fun(i+1, n, s, ds, ans);
                ds.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        fun(0, s.length(), s, ds, ans);
        return ans;
    }
};
