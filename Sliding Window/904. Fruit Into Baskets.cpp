class Solution {
public:
    int totalFruit(vector<int>& a) {
        int first=a[0], ans=0, second=-1, lastF=0, lastS=-1, startF=0, temp2;
        int i=0, j=0, n=a.size();
        int temp;
        while(j<n && a[j]==first){
            lastF=j;
            j++;
        }
        if(j==n)    return n;
        second = a[j];
        lastS=j;
        while(j<n && (a[j]==first || a[j]==second)){
            if(a[j]==first) lastF=j;
            else    lastS=j;
            j++;
        }
        if(j==n)    return n;
        temp2 = max(lastS, lastF);
        ans = temp2-startF+1;
        while(j<n){
            lastF = min(lastF, lastS) + 1;
            startF = lastF;
            first=a[lastF];
            second=a[j];
            lastS = j;
            int tLastF=j-1;
            while(tLastF>=startF){
                if(a[tLastF]==first){
                    lastF=tLastF;
                    break;
                }
                tLastF-=1;
            }
            while(j<n && (a[j]==first || a[j]==second)){
                if(a[j]==first)
                    lastF=j;
                else
                    lastS=j;
                j++;
            }
            temp2=max(lastS, lastF);
            temp = temp2-startF+1;
            ans = max(ans, temp);
        }
        return ans;
    }
};
