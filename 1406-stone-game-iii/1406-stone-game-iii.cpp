class Solution {
public:
    int dp[50001];
    int solve(int i, auto&nums,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int oneTake=INT_MIN;
         if(i+1<n){
             oneTake=nums[i]-(dp[i+1]!=-1?dp[i+1]:solve(i+1,nums,n));
         }
         else oneTake=nums[i]-solve(i+1,nums,n);
        int twoTake=INT_MIN;
        int threeTake=INT_MIN;
        if(i+1<n){
            if(i+2<n){
                twoTake=nums[i]+nums[i+1]-(dp[i+2]!=-1?dp[i+2]:solve(i+2,nums,n));
            }
            else twoTake=nums[i]+nums[i+1]-solve(i+2,nums,n);

        }
        if(i+2<n){
           if(i+3<n){
              threeTake=nums[i]+nums[i+1]+nums[i+2]-(dp[i+3]!=-1?dp[i+3]:solve(i+3,nums,n));
           }
           else  threeTake=nums[i]+nums[i+1]+nums[i+2]-solve(i+3,nums,n);
        }

        return dp[i]=max({oneTake,twoTake,threeTake});


        
    }
    string stoneGameIII(vector<int>&nums) {
        
        int n=nums.size();
        vector<int>dp(n+1,0);


        dp[n]=0;

        for(int i=n-1; i>=0; i--){
            int oneTake=INT_MIN;
            int twoTake=INT_MIN;
            int threeTake=INT_MIN;

            oneTake=nums[i]-dp[i+1];

        if(i+1<n){
            if(i+2<n){
                twoTake=nums[i]+nums[i+1]-dp[i+2];
            }
            else twoTake=nums[i]+nums[i+1]-0;
        }

        if(i+2<n){
            if(i+3<n){
                threeTake=nums[i]+nums[i+1]+nums[i+2]-dp[i+3];

            }
            else  threeTake=nums[i]+nums[i+1]+nums[i+2];
        }
        dp[i]=max({oneTake,twoTake,threeTake});
    }
        if(dp[0]<0) return "Bob";
        if(dp[0]==0) return "Tie";
        return "Alice";

        
    }
};