class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        int odd=-1;
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(freq[i]&1){
                odd=i;
                break;
            }
        }
       
        if(odd!=-1){
            freq[odd]-=1;
        }

        string ans="",temp="";

        for(int i=0; i<26; i++){
            if(freq[i]>0){
                temp.append(freq[i]/2,i+'a');
            }
        }
        string rev=temp;
        reverse(temp.begin(), temp.end());
        string middle="";
        if(odd!=-1){
            middle.push_back(odd+'a');
        }

        return rev+middle+temp;
        








        
    }
};