class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m<n) return "";

        vector<int>t_freq(128,0),s_freq(128,0);

        for(auto ch: t){
            t_freq[ch]++;
        }
        int required_matches=0;
        for(int i=0; i<128; i++){
            if(t_freq[i]>0) required_matches++;
        }

        int l=0,minlen=INT_MAX,start=-1;
        int formed_matches=0;

        for(int r=0; r<m; r++){
            char ch=s[r];
            s_freq[ch]++;

            if(t_freq[ch]>0 && t_freq[ch]==s_freq[ch]) formed_matches++;

            while(formed_matches==required_matches){
                if(minlen>r-l+1){
                    minlen=r-l+1;
                    start=l;
                }
                char ch=s[l];
                s_freq[ch]--;
                if(t_freq[ch]>0 && s_freq[ch]<t_freq[ch]) formed_matches--;

                l++;

            }




        }
       return start==-1?"":s.substr(start,minlen);
        
    }
};