class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(auto w:word) freq[w-'a']++;

        sort(rbegin(freq),rend(freq));

        int ans=0;
        for(int i=0; i<26; i++){
            if(freq[i]==0) break;
            int presses=(i/8)+1;
            ans+=freq[i]*presses;


        }
        return ans;
    }
      
};