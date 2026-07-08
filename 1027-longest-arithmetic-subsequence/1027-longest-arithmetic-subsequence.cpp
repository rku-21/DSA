class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(1005,0));
        int ans=2;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int d=nums[i]-nums[j]+501;
                dp[i][d]=max(dp[i][d],dp[j][d]>0?dp[j][d]+1:2);
                ans=max(ans,dp[i][d]);
            }
        }
        return ans;
        
    }
};