class Solution {
public:
    int findMin(vector<int>& nums) {

        int n=nums.size();
        int ans=INT_MAX;
        
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(nums[l]<=nums[mid]){
                //left part is sorted 
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else {
                //right part is sorted 
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
        }
        return ans;
        
    }
};