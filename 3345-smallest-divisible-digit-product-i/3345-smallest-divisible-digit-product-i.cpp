class Solution {
public:
   bool solve(int n, int t){
        int product=1;
        while(n){
           int rem=n%10;
           product*=rem;
           n/=10;
        }
      
        return product%t==0;
   }
    int smallestNumber(int n, int t) {
         bool ok=false;

         while(true){
            ok=solve(n,t);
            if(ok) break;
            n++;

         }
         return n;


        
    }
};