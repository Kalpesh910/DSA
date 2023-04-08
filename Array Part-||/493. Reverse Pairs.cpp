class Solution {
public:
    int merge(int low, int mid, int high, vector<int>& nums){
      int i=low, j=mid+1;
      int total=0;
      for(int i=low; i<=mid; i++){
        while(j<=high && nums[i]> (long long) 2*nums[j]){
          j++;
        }
        total += j-(mid+1);
      }
      vector<int>t;
      int left=low, right=mid+1;
      while(left<=mid && right<=high){
        if(nums[left]<nums[right]){
          t.push_back(nums[left++]);
        }
        else{
          t.push_back(nums[right++]);
        }
      }
      while(right<=high){
        t.push_back(nums[right++]);
      }
      while(left<=mid){
        t.push_back(nums[left++]);
      }
      j=0;
      for(int i=low; i<=high; i++){
        nums[i]=t[j++];
      }
      return total;
    }
    int mergeSort(int low, int high, vector<int>&nums){
      if(low>=high)
        return 0;
      int mid=(low+high)/2;
      int pair=mergeSort(low, mid, nums);
      pair+=mergeSort(mid+1, high, nums);
      pair+=merge(low, mid, high, nums);
      return pair;
    }
    int reversePairs(vector<int>& nums) {
      return mergeSort(0, nums.size()-1, nums);
    }
};
