class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>suffMatch(n+1,0);
        int match=0;
        suffMatch[n]=0;
        int j=m-1;
        for(int i=n-1; i>=0; i--){
            if(j>=0 && word1[i]==word2[j]){
                match++;
                j--;
            }

            suffMatch[i]=match;
        }
        j=0;
        vector<int>ans;
        int startIdx=-1;
        for(int i=0; i<n; i++){
            if(j<m && word1[i]==word2[j]){
                ans.push_back(i);
                j++;
                if(j>=m) break;

            }
            else if(word1[i]!=word2[j]){
                int matchCnt=suffMatch[i+1];
                cout<<matchCnt<<endl;
                int leftCnt=m-j-1;
                if(matchCnt>=leftCnt){
                    ans.push_back(i);
                    startIdx=i+1;
                    j++;
                    break;
                }
            }
          



        }
        cout<<j<<endl;

  
         if(j>=m) return ans;
        if(startIdx==-1) return {};
        while(j<m) {
            if(word1[startIdx]==word2[j]){
                ans.push_back(startIdx);
                j++;
                startIdx++;
            }
            else {
                startIdx++;
            }
        }

        return ans;


        


        
    }
};