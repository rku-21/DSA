class Solution {
public:
   vector<int>ans;
   int LOW;
   string s;
   void solve(int pos, bool tight, int prev,int num){
     if(pos==s.size()){
        if(num>=LOW) ans.push_back(num);
        return;
     }

     int limit=tight?s[pos]-'0':9;
      
     for(int d=0; d<=limit; d++){
         int newTight=tight && d==s[pos]-'0';
         if(prev==-1 || prev==0){
            solve(pos+1,newTight,d,d);
         }
         else if(d==prev+1){
            solve(pos+1,newTight,d,num*10+d);
         }
         
        
     }
   }
    vector<int> sequentialDigits(int low, int high) {
       LOW=low;
       s=to_string(high);
        solve(0,true,-1,0);
        return ans;

        
    }
};