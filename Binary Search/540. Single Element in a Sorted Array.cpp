class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int n=nums.size();
      if(nums.size()==1)  return nums[0];
      if(nums[0]!=nums[1])  return nums[0];
      if(nums[n-1]!=nums[n-2])  return nums[n-1];
      int start=0, end=nums.size()-1;
      while(start<=end){
        int mid = (start+end)/2;
        if(mid%2==1){
          if(nums[mid-1]==nums[mid])
            start=mid+1;
          else if(nums[mid+1]==nums[mid])
            end=mid-1;
          else
            return nums[mid];
        }
        else{
          if(nums[mid+1]==nums[mid])
            start=mid+2;
          else if(nums[mid-1]==nums[mid])
            end=mid-2;
          else
            return nums[mid];
        }
      }
      return -1;
    }
};
