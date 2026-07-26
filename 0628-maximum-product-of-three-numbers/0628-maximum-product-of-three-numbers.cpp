class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi1,maxi2,maxi3;
        int mini1,mini2;
        maxi1=maxi2=maxi3=INT_MIN;
        mini1=mini2=INT_MAX;
        for(auto num:nums){
            if(num>maxi1){
                maxi3=maxi2;
                maxi2=maxi1;
                maxi1=num;
            }
            else if(num>maxi2){
                maxi3=maxi2;
                maxi2=num;
            }
            else if(num>maxi3){
                maxi3=num;
            }

            if(num<mini1){
                mini2=mini1;
                mini1=num;
            }
            else if(num<mini2){
                mini2=num;
            }


        }
        return max(maxi1*maxi2*maxi3,mini1*mini2*maxi1);


        
        
    }
};