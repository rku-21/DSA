class Solution {
public:
    vector<int>At,at,As,as;

    bool valid(){
        for(int i=0; i<26; i++){
            if(At[i]!=0 && At[i]>As[i]) return false;
            if(at[i]!=0 && at[i]>as[i]) return false;
        }
        return true;
       
    }
    string minWindow(string s, string t) {
        int n=t.size();
        int m=s.size();
        At.resize(26,0);
        As.resize(26,0);
        as.resize(26,0);
        at.resize(26,0);
        

        for(int i=0; i<n; i++){
            char ch=t[i];
            if(ch>='A' && ch<='Z') At[ch-'A']++;
            else at[ch-'a']++;
        }
        int start=-1;
        int ans=INT_MAX;
        int l=0;

        for(int r=0; r<m; r++){
            char ch=s[r];
            if(ch>='A' && ch<='Z') As[ch-'A']++;
            else as[ch-'a']++;

            while(valid()){
              if(ans>r-l+1){
                ans=r-l+1;
                start=l;
              }
            char ch=s[l];
            if(ch>='A' && ch<='Z') As[ch-'A']--;
            else as[ch-'a']--;
            l++;
        }


    }

    if(start==-1) return "";
    return s.substr(start,ans);


        


        
    }
};