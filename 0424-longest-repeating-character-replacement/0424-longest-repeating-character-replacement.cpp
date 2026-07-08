class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>store(26,0);
        int maxi=0;
        int l=0;
        int best=0;
        int n=s.size();

        for(int i=0; i<n; i++){
            int ch=s[i]-'A';
            store[ch]++;

            maxi=max(maxi,store[ch]);

            if((i-l+1)-maxi>k){
                store[s[l]-'A']--;
                l++;

            }
            best=max(best,i-l+1);

        }

        return best;

        
    }
};