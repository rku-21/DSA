class Solution {
public:
    bool solve(int i, int j, string&s, string &p){
        if(j==p.size()) {
            return i==s.size();
        }
        bool fm=(i<s.size()  && ( s[i]==p[j] || p[j]=='.'));
        bool ans=false;
        if(j+1<p.size() && p[j+1]=='*'){
            ans= solve(i,j+2,s,p) || fm && solve(i+1,j,s,p);
        }
        else {
            ans= fm&&solve(i+1,j+1,s,p);
        }

        return ans;





    }
    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
        
    }
};