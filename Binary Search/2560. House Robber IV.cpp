class Solution {
public:
    
    bool check(int n, int k, vector<int>&nums){
        int lastInd=-10, count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>n)   continue;
            if(i==lastInd+1)    continue;
            lastInd = i;
            count+=1;
            if(count >= k)  return true;
        }
        return false;
    }
    int minCapability(vector<int>&nums, int k){
        int left=1, right=1e9+1;
        //********* Binary Search *********
        while(left < right){
            int mid = (left+right)/2;
            if(check(mid, k, nums)) right=mid;
            else    left=mid+1;
        }
        return right;
    }
};
