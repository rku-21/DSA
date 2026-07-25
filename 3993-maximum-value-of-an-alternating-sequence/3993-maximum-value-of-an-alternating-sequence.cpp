class Solution {
public:
    long long maximumValue(int n, int s, int m) {

        if(n==1) return s;
        int peaks=n/2;

        return s+1LL*peaks*m-(peaks-1);
       
        
    }
};