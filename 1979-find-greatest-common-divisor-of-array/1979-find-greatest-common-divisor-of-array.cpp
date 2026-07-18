class Solution {
public:
    int mygcd(int a, int b){
        if(a==b) return a;
        if(a==0) return b;
        if(b==0) return a;
        if(a>b) return mygcd(a-b,b);
        return mygcd(a,b-a);
       
        
        
    }
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        for(int num:nums) {
            maxi=max(maxi,num);
            mini=min(mini,num);
        }
        return mygcd(maxi,mini);

        
    }
};