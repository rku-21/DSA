class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        unordered_map<string,int>mp,compareMp;
        for(auto word:words){
            mp[word]++;
        }
        int wordlen=words[0].size();
        int totallen=words.size();
        vector<int>ans;

        for(int offset=0; offset<wordlen; offset++){
            int l=offset;
            int currWordcnt=0;
            for(int r=l; r<=n-wordlen; r+=wordlen){
                string temp=s.substr(r,wordlen);
                compareMp[temp]++;
                currWordcnt++;

                // invalid shrink
                while(compareMp[temp]>mp[temp]){
                  cout<<s.substr(l,wordlen)<<endl;
                  compareMp[s.substr(l,wordlen)]--;
               
                  currWordcnt--;
               

                  l+=wordlen;
                  
                } 

                if(currWordcnt==words.size()) ans.push_back(l);

            }
            compareMp.clear();
            
        }

        return ans;





        
    }
};