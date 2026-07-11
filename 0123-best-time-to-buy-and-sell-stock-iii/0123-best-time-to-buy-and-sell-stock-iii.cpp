class Solution {
public:
    //  (Jay Shree Ram)
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int p1=0;
        int p2=0;
        int b1=INT_MAX;
        int b2=INT_MAX;

        for(auto price: prices){
            b1=min(b1,price);
            p1=max(p1,price-b1);

            // we can invest the profit from first in second buy
            b2=min(b2,price-p1);
            p2=max(p2,price-b2);


        }

        return p2;
        
    }
};