class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1, ind2, i, j;
        for(ind1=nums.size()-2; ind1>=0; ind1--){
            if(nums[ind1]<nums[ind1+1]){
                break;
            }
        }
        if(ind1<0){
            // reverse the array
            i=0, j=nums.size()-1;
            while(i<=j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            return;
        }
        
        for(ind2=nums.size()-1; ind2>=0; ind2--){
            if(nums[ind2]>nums[ind1]){
                break;
            }
        }
        
        swap(nums[ind1], nums[ind2]);
        i=ind1+1, j=nums.size()-1;
        // reverse from i+1 to last element
        while(i<=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
