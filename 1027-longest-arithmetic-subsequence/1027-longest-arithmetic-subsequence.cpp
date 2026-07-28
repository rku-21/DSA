class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(1002,0));

        int ans=2;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int diff=nums[i]-nums[j]+501;
                dp[i][diff]=dp[j][diff]>0?dp[j][diff]+1:2;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
        
    }
};