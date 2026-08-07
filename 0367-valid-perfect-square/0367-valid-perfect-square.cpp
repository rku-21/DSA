class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i=1; 1LL*i*i<=num; i++){
            if(i*i==num) return true;
        }
        return false;
        
    }
};