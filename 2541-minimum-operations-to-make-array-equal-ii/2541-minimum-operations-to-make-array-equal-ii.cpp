class Solution {
public:
    typedef long long ll;
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();

        ll ans=0;
        ll num1Sum=0,num2Sum=0;

        for(int i=0; i<n; i++){
            num1Sum+=nums1[i];
            num2Sum+=nums2[i];

            if(k!=0 && abs(nums2[i]-nums1[i])%k!=0) return -1;

            if(k!=0 && nums2[i]-nums1[i]>=0){
                ans+=(nums2[i]-nums1[i])/k;

            }
            else if(k==0){
                if(nums2[i]-nums1[i]!=0) return -1;
            }



        }

        if(num1Sum!=num2Sum) return -1;
        return ans;





        
    }
};