class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        set<pair<int,int>>st;
         int ans=0;
        for(int i=0; i<n; i++){
            int aj=nums[i];
            if(mp.count(k+aj) && st.find({k+aj,aj})==st.end()){
                 ans++;
                 st.insert({k+aj,aj});
                 st.insert({aj,k+aj});
            }
            if(mp.count(aj-k) && st.find({aj-k,aj})==st.end()){
                ans++;
                st.insert({aj-k,aj});
                st.insert({aj,aj-k});
            }
            mp[aj]=1;

        }

        return ans;
        
    }
};