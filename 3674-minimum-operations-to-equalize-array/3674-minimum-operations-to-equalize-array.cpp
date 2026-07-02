class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool allequal=true;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]) allequal=false; 
        }
        if(allequal) return 0;
        return 1;
        
    }
};