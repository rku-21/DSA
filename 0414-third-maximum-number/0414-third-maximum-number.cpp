class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        
        
        long long  f1=LONG_MIN/2,f2=LONG_MIN/2,f3=LONG_MIN/2;

        for(int i=0; i<n; i++){
            int val=nums[i];
           

            
            if(f1==-1 || val>f1){
                f3=f2;
                f2=f1;
                f1=val;
            }
            else if(val<f1 && (f2==-1 || val>f2)){
              
                f3=f2;
                f2=val;
            }
            else if(val<f2 && (f3==-1 || val>f3)) {
                f3=val;
            }

        }
        if(f3==LONG_MIN/2) return f1;
        return f3;
        
    }
};