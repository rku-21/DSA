class Solution {
public:
    int firstUniqChar(string s) {
        int mask1=0,mask2=0;

        for(int i=0; i<s.size(); i++){
            int idx=s[i]-'a';

            if((mask2 & (1<<idx)) && (mask1 & (1<<idx))){
                mask1=mask1 & ~(1<<idx);
            }
            else if((mask2 & (1<<idx))==0){
                mask1=mask1 | (1<<idx);
                mask2=mask2 | (1<<idx);
            }
        }
        for(int i=0; i<s.size(); i++){
            int idx=s[i]-'a';
            if((mask1 & (1<<idx))) return i;
        }
        return -1;


        
    }
};