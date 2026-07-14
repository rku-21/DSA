class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        vector<int>pref(2*n+1,0);
        pref[0]=0;
        for(int i=1; i<=2*n; i++){
            pref[i]=pref[i-1]+nums[i-1];
        }

        deque<int>dq;

        int ans=INT_MIN;
        for(int i=0; i<=2*n; i++) {
            if(!dq.empty() &&  dq.front()<i-n){
                dq.pop_front();
            }
            if(!dq.empty()){
                ans=max(ans,pref[i]-pref[dq.front()]);
            }
            while(!dq.empty() && pref[dq.back()]>=pref[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return ans;






        
    }
};