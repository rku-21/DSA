class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){
                // left part is sorted 
                if(target>nums[mid] || target<nums[l]){
                    l=mid+1;
                }
                else r=mid-1;
            }
            else {
                // right part is sorted 
                if(target>nums[r] || target<nums[mid]){
                    r=mid-1;
                }
                else l=mid+1;
            }

        }

        return -1;


        
    }
};