class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        vector<string>ans;
        int l=0;
         for(int r=0; r<n; r++){
             if(r-l+1>10) l++;

             if(r-l+1==10) {
                string temp=s.substr(l,10);
                if(mp[temp]==-1) continue;
                 mp[temp]++;
                if(mp[temp]>1) {
                    ans.push_back(temp);
                    mp[temp]=-1;
                }
             }




         }

         return ans;
        
    }
};