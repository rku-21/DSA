class Solution {
public:
    bool valid(auto& req, int idx,auto & mp){
        for(int i=0; i<26; i++){
            if(req[i]==1 &&  (mp[idx] & (1<<i))==0){
                return false;
                
            }
        }
        return true;
         

    }
    string smallestSubsequence(string s) {
        vector<int>req(26,0);
        int n=s.size();
        for(auto ch:s){
          req[ch-'a']=1;
        }
        unordered_map<int,int>mp;
        int value=0;
        for(int i=n-1; i>=0; i--){
            int idx=s[i]-'a';
            value = value | (1<<idx);
            mp[i]=value;

        }

        string ans="";
        for(int i=0; i<n; i++){
            int ch=26;
            int idx=i;
            int min_idx;
            while(idx<n && valid(req, idx,mp)){
                if(ch>s[idx]-'a' && req[s[idx]-'a']==1) {
                    ch=s[idx]-'a';
                    min_idx=idx;
                }
                idx++;
               
            }
            if(ch<26){
                ans.push_back(ch+'a');
                req[ch]=0;
                i=min_idx;
            }
           
           
        }

        return ans;





        
    }
};