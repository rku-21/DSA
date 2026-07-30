class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int times=1;
        int pressedCnt=0;
        while(n){
            int key=min(8,n);
            n-=key;
            pressedCnt+=times*key;
            times++;
        }
        return pressedCnt;
        
    }
};