class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            while(nums[i]+1!=nums[i+1]){
                ans.push_back(nums[i]+1);
                nums[i]=nums[i]+1;
            }
        }
        return ans;

        
        
    }
};