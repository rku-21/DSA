class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();

        if(n==1 || n==2) return n;
        int ans=n+1;
        while(true){
            if((ans&(ans-1))==0) return ans;
            ans++;
        }
        return ans;


        
    }
};