class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>s(words.begin(), words.end());
        vector<string>ans;
        for(auto w:words){
            int n=w.size();
            vector<int>dp(n+1,0);
            dp[0]=1;
            for(int i=0; i<=n; i++){
                if(dp[i]==0) continue;
                for(int j=i+1; j<=n; j++){
                    if(j-i<n && s.count(w.substr(i,j-i))) dp[j]=1;
                }
                if(dp[n]){
                    ans.push_back(w);
                    break;
                }
            }
        }

        return ans;
        
    }
};