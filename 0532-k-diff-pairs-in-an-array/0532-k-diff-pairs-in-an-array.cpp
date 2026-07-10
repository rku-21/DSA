class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int ans=0,i=0,j=1;

        while(j<n){
            if(j<=i){
                j=i+1;
                continue;
            }


            if(nums[j]-nums[i]==k){  
                ans++;
                i++;
                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
                while(i<n && nums[i]==nums[i-1]) i++;
            }
            else if(nums[j]-nums[i]<k){
                j++;
            }
            else {
                i++;

            }
        }
        return ans;
        
    }
};