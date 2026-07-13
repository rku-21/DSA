class Solution {
public:
    int solve(auto& num1, auto& num2, int val1,int val2){
        int ops=0;
        int n=num1.size();
        for(int i=0; i<n-1; i++){
            if(num1[i]>val1 && num1[i]>val2) return -1;
            if(num2[i]>val1 && num2[i]>val2) return -1;

            if(num1[i]>val1){
                if(num2[i]>val1) return -1;
                ops++;
            }
            else if(num2[i]>val2){
                if(num1[i]>val2) return -1;
                ops++;
            }

           


        }

        return ops;

       


    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int maxi1=nums1[0];
        int maxi2=nums2[0];
        int maxi1_idx=0,maxi2_idx=0;
        for(int i=1; i<n; i++){
            if(maxi1<=nums1[i]) {
                maxi1=nums1[i];
                maxi1_idx=i;

            }
            if(maxi2<=nums2[i]){
                maxi2=nums2[i];
                maxi2_idx=i;
            }
        }

        if(maxi1_idx==n-1 && maxi2_idx==n-1) return 0;
        if(maxi1_idx<n-1 && maxi2_idx<n-1) return -1;

        int ans1=solve(nums1,nums2, nums1[n-1],nums2[n-1]); // no swap 
        int ans2=solve(nums1,nums2,nums2[n-1],nums1[n-1]); // swapeed 
        if(ans1==-1 && ans2==-1) return -1;
        ans2+=1;
        return ans1==-1?ans2:min(ans1,ans2);
        

      

       
        
        
        
    }
};