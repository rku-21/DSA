class Solution {
public:
    int n;
    int dp[100001][2];

    int solve(int idx, auto& nums1,auto&nums2, bool isSwap){
        if(idx>=n) return 0;
        if(dp[idx][isSwap]!=-1) return dp[idx][isSwap];

        int prevA=isSwap?nums2[idx-1]:nums1[idx-1];
        int prevB=isSwap?nums1[idx-1]:nums2[idx-1];

        int ans=INT_MAX/2;

        if(nums1[idx]>prevA && nums2[idx]>prevB){
            // agar main swap na kru tabhi array should be valid till index idx,
            ans=min(ans,solve(idx+1,nums1,nums2,false));
        }
         if(nums2[idx]>prevA && nums1[idx]>prevB){
            // agar maine is index ko swap kra (idx ko) tabhi array should be valid 
            ans=min(ans,1+solve(idx+1,nums1,nums2,true));
        }
        return  dp[idx][isSwap]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        memset(dp,-1,sizeof(dp));
        
        return min(solve(1,nums1,nums2,false),1+solve(1,nums1,nums2,true));
        
    }
};