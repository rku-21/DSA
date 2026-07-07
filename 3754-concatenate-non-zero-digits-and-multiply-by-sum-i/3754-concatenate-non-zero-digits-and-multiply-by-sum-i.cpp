class Solution {
public:
    typedef long long ll;
    pair<int,int> solve(int n){
        ll x=0,sum=0;
        int power=0;
        while(n){
            int rem=n%10;
           if(rem!=0){
               x=rem*pow(10,power)+x;
            sum=(ll)sum+rem;
            power++;
           }
            n/=10;
            

        }

        return {x,sum};

    }
    long long sumAndMultiply(int n) {
      auto [x,sum]=solve(n);
    //   cout<<x<<" "<<sum<<endll;

      return 1LL*x*sum;
        
    }
};