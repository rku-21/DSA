class Solution {
public:
    int maxi1=0;
    int maxi2=0;
    void solve(int n){
        while(n){
            int rem=n%10;
            if(maxi1<rem){
               maxi2=maxi1;
               maxi1=rem;
               
            }
            else if(maxi2<rem){
                maxi2=rem;
            }
            n/=10;
        }
    }
    int maxProduct(int n) {
        solve(n);
        return maxi1*maxi2;
        
    }
};