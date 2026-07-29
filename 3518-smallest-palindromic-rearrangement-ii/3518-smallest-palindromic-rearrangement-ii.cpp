class Solution {
public:
   long long  findWays(int n, int r,int k){
       long long  result=1;
   
       
       for(int i = 1; i <= r; i++) {
            result = result * (n - r + i)/i; 

            if(result >= k) 
                return k;
        }
       if(result>=k) return k;
      
       return result;
   }
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        if(n==1 && k==1) return s;
        
        string mid="";
        if(n&1){
            mid.push_back(s[n/2]);
        }
        vector<int>freq(26,0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq[i]&1) freq[i]-=1;
            freq[i]/=2;
        }

        string halfres="";

        for(int i=0; i<n/2; i++){
            bool found=false;
             for(int j=0; j<26; j++){
                   if(freq[j]>0){
                        freq[j]-=1; // fix at i

                        int leftPos=n/2-(i+1);
                       
                        long long ways=1;

                        for(int idx=0; idx<26; idx++){
                            if(freq[idx]>0){
                                ways*=findWays(leftPos,freq[idx],k);
                             
                           
                                if(ways>=k) break;
                                leftPos-=freq[idx];
                            }
                        }

                        if(ways>=k) {
                            halfres.push_back(j+'a');
                            found=true;
                            break;
                        }
                        else {
                            freq[j]+=1;
                            cout<<k<<" "<<ways<<endl;
                            k-=ways;
                        }
                    }
             }
             if(!found) return "";
        }

        string rev=halfres;
        reverse(begin(rev),end(rev));

       return halfres+mid+rev;

       

    }
};