class Solution {
public:
    bool solve(int i, int j, auto&nums,int score1,int score2,bool turn){
        if(i>j) {
            return score1>=score2;
        }
        bool ans1=false;
        bool ans2=false;
        if(turn){
            ans1=solve(i+1, j, nums,score1+nums[i],score2,false);
            ans2=solve(i,j-1,nums,score1+nums[j],score2,false);
            return ans1 || ans2;
            
        }
     
            ans1=solve(i+1, j, nums,score1,score2+nums[i],true);
            ans2=solve(i,j-1,nums,score1,score2+nums[j],true);

        
        return ans1 && ans2;
    }
    bool predictTheWinner(vector<int>& nums) {

        int n=nums.size();
        return solve(0,n-1,nums,0,0,true);
        
    }
};