class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;

        for(auto num:nums){
            if(maxi1<num){
                maxi2=maxi1;
                maxi1=num;
            }
            else if(num>maxi2){
                maxi2=num;
            }
        }
        return (maxi1-1)*(maxi2-1);
        
    }
};