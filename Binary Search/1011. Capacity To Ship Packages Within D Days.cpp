class Solution {
public:
    bool check(int capacity, int days, vector<int>& weights){
      int day=0, total = 0;
      for(int i=0; i<weights.size(); i++){
        total += weights[i];
        if(total > capacity){
          day += 1;
          if(day>days)  return false;
          total = weights[i];
        }
      }
      day+=1;
      return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
      int mina=*max_element(weights.begin(), weights.end());
      int maxa=0;
      for(auto it: weights) maxa+=it;
      int start=mina, end=maxa;
      while(start<=end){
        if(start==end)  return start;
        
        int mid=(start+end)/2;
        if(check(mid, days, weights)){
          end=mid;
        }
        else{
          start=mid+1;
        }
      }
      return end;
    }
};
