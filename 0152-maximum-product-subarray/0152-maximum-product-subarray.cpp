class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int minProduct=nums[0];
        int maxProduct=nums[0];
        int ans=nums[0];

        for(int i=1; i<n; i++){
            int ans1=minProduct*nums[i];
            int ans2=maxProduct*nums[i];
            int ans3=nums[i];
            ans=max({ans,ans1,ans2,ans3});
            minProduct=min({ans1,ans2,ans3});
            maxProduct=max({ans1,ans2,ans3});

        }

        return ans;


        
    }
};