class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int ze=0,on=0,tw=0;
        // for(auto it: nums){
        //     if(it==2)   tw++;
        //     else if(it==1)  on++;
        //     else    ze++;
        // }
        // int n=nums.size();
        // int i=0;
        // while(ze--){
        //     nums[i]=0; i++;
        // }
        // while(on--){
        //     nums[i]=1;  i++;
        // }
        // while(tw--){
        //     nums[i]=2;  i++;
        // }
      
        // Solution 2 optimezed
        int n=nums.size();
        int high=n-1, low=0, mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid++], nums[low++]);
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
