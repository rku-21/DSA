class Solution {
public:
    int n;
    int dp[1001][1005];
    int solve(int j, int d, auto&nums){
        if(j>=n) return 0;
        if(dp[j][d+501]!=-1) return dp[j][d+501];

        int ans=0;
        for(int k=j+1; k<n; k++){
            if(nums[k]-nums[j]==d){
                ans=max(ans,1+solve(k,d,nums));
            }
        }

        return dp[j][d+501]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));

        if(n<=2) return n;

        int result=0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d=nums[j]-nums[i];

                result=max(result,2+solve(j,d,nums));


            }
        }

        return result;
    }
};