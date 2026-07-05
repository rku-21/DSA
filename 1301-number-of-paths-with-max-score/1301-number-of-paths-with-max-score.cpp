class Solution {
public:
   int dpMaxScore[101][101]; // dp[i][j] ==> maxScore to reach (i,j)<<--(n-1,n-1) 
   int dpPath[101][101][2000]; // dp[i][j][score] =>number of path to reach (0,0)->>(i,j) with Score val of score
   typedef long long ll;
   int n;
   int MOD=1e9+7;
   
   int findMaxScore(int i, int j, auto&board){
      if(i<0 || j<0  || board[i][j]=='X') return INT_MIN/2;
      if(i==0 && j==0) return 0;
      if(dpMaxScore[i][j]!=-1) return dpMaxScore[i][j];

      int cellScore=(i==n-1 && j==n-1)?0:board[i][j]-'0'; 

      int left=findMaxScore(i,j-1,board);
      int up=findMaxScore(i-1,j,board);
      int diagonal=findMaxScore(i-1,j-1,board);

      return dpMaxScore[i][j]=cellScore+max({left,up,diagonal});
    }

    int findPaths(int i,int j,int leftScore, auto&board){
        if(i>=n || j>=n || board[i][j]=='X') return 0;
        if(i==n-1 && j==n-1) {
           if(leftScore==0) return 1;
           return 0;
        }
        if(leftScore<0) return 0;
        if(dpPath[i][j][leftScore]!=-1) return dpPath[i][j][leftScore];
        int cellScore=(i==0 && j==0)?0:board[i][j]-'0';

        int ans=0;
        int newleftScore=leftScore-cellScore;

        ans=(ans+findPaths(i+1,j,newleftScore,board))%MOD;
        ans=(ans+findPaths(i,j+1,newleftScore,board))%MOD;
        ans=(ans+findPaths(i+1,j+1,newleftScore,board))%MOD;


        return dpPath[i][j][leftScore]=ans;







    }






   vector<int> pathsWithMaxScore(vector<string>& board) {

     n=board.size();
    if(board[0][0]=='X' || board[n-1][n-1]=='X') return {0,0};
    memset(dpMaxScore,-1,sizeof(dpMaxScore));
    int max_score=findMaxScore(n-1,n-1,board);

    if(max_score<0) return {0,0};


    memset(dpPath,-1,sizeof(dpPath));

    int pathCnt=findPaths(0,0,max_score,board);

    return {max_score,pathCnt};










        
    
        
    }
};