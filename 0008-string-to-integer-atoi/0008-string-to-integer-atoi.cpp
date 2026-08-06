class Solution {
public:
 
    int myAtoi(string s) {
        int n=s.size();

        int i=0;
        long long result=0;
        while(i<n && s[i]==' ') i++;
        bool isPositive=true;
        if(s[i]=='-') {
            isPositive=false;
            i++;
        }
        else if(s[i]=='+') i++;
        
     
        if(!(s[i]>='0' && s[i]<='9')) return 0;
        
       
        while(i<n && s[i]=='0') i++;
         cout<<i<<endl;

        while(i<n && s[i]>='0' && s[i]<='9'){
          
            if(result>=LLONG_MAX/10){
                result=LLONG_MAX;
            }
            else  result=min(result*10LL+s[i]-'0',LLONG_MAX);
          

           
            i++;
        }
     

        if(isPositive){
            return min(result,1LL*INT_MAX);
        }
      
        return max(-1LL*result,1LL*INT_MIN);






        
    }
};