class Solution {
public:
    typedef long long ll;
    string solve(ll num , int len){
        string str;
        for(int d=9; d>=2; d--){
            while(num % d==0){
                str.push_back(d+'0');
                num/=d;
            }
        }
        while(str.size() < len){
            str.push_back('1');
        }

        reverse(begin(str),end(str));
        return str;

    }
    string smallestNumber(string num, long long t) {
        int n=num.size();

        ll temp=t;

        vector<int>primeFactors={2,3,5,7};
        for(int i=0; i<4; i++){
            while(temp % primeFactors[i]==0){
                temp/=primeFactors[i];
            }
            
        }

        if(temp != 1) return "-1";

        vector<ll>remainingFactors(n+1,t);
        for(int i=0; i<n; i++){
            int digit=num[i]-'0';

            if(digit == 0) break;

            remainingFactors[i+1]= remainingFactors[i]/(__gcd(remainingFactors[i],(ll)digit));
        }

        if(remainingFactors[n] == 1) {
            return num;
        }

        int zeroPos=num.find('0');
        int zeroIdx=n-1;
        if(zeroPos !=-1){
            zeroIdx=zeroPos;
        }

        for(int i=zeroIdx; i>=0; i--){
            ll required=remainingFactors[i];

             int freeSlots=n-i-1;


             for(int d=(num[i]-'0')+1; d<=9; d++){
               ll Nextrequired=required/(__gcd(required,(ll)d));
                string requiredNumber=solve(Nextrequired, freeSlots);

                if(requiredNumber.size() == freeSlots) {
                    return num.substr(0,i)+to_string(d)+requiredNumber;
                }
             }



        }
          return solve(t,n+1);
    }
};