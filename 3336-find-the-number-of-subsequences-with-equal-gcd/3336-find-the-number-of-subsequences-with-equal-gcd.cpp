class Solution {
public:
    int n;
    int MOD=1e9+7;
    int dp[201][201][201];
    int solve(int idx, int gcd1, int gcd2,auto&nums){
        if(idx>=n){
            if(gcd1==gcd2) return 1;
            return 0;
        }
        if(dp[idx][gcd1][gcd2]!=-1) return dp[idx][gcd1][gcd2];

        int ans=0;
        ans=(ans+solve(idx+1, __gcd(nums[idx],gcd1),gcd2,nums))%MOD;
        ans=(ans+solve(idx+1,gcd1,__gcd(nums[idx],gcd2),nums))%MOD;

        ans=(ans+solve(idx+1,gcd1,gcd2,nums))%MOD;;

        return dp[idx][gcd1][gcd2]= ans;


    }
    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return (solve(0,0,0,nums)-1+MOD)%MOD; // gcd(0,anynumber)=anynumber
        
    }
};