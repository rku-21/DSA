class Solution {
public:
    // jay Shree Ram 
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i]<=0 || nums[i]>n) continue;

            while(nums[i]>=1 && nums[i]<=n && nums[i]!=i+1){ // clyclic sort 
                int correct_idx=nums[i]-1;
                if(nums[i]==nums[correct_idx]) break;
                swap(nums[i],nums[correct_idx]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};

// Tc As there can be at most n successful swaps and each one place one val to its correct idx , so total work is  o(n)+n+o(n) == >> o(n) 