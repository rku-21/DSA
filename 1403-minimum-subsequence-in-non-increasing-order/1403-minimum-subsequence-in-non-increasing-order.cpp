class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        vector<int>ans;
        int sum=0;
        for(auto num:nums) sum+=num;
        int leftsum=0;
        for(int i=0; i<n; i++){
            if(leftsum>sum) return ans;
            ans.push_back(nums[i]);
            leftsum+=nums[i];
            sum-=nums[i];

        }

        return ans;



        
    }
};