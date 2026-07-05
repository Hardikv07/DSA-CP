class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(n, -2));     
        vector<vector<int>> ways(n, vector<int>(n, -1));   

        function<pair<int,int>(int,int)> dfs = [&](int x,int y)->pair<int,int>{

            if(x<0 || y<0 || board[x][y]=='X')
                return {-1,0};

            if(x==0 && y==0)
                return {0,1};

            if(dp[x][y]!=-2)
                return {dp[x][y], ways[x][y]};

            int best = -1;
            long long cnt = 0;

            vector<pair<int,int>> dirs = {
                {x-1,y},
                {x,y-1},
                {x-1,y-1}
            };

            for(auto [nx,ny]:dirs){
                auto [score,w]=dfs(nx,ny);
                if(score==-1) continue;

                if(score>best){
                    best=score;
                    cnt=w;
                }
                else if(score==best){
                    cnt=(cnt+w)%MOD;
                }
            }

            if(best==-1){
                dp[x][y]=-1;
                ways[x][y]=0;
                return {-1,0};
            }

            if(board[x][y]!='S' && board[x][y]!='E')
                best += board[x][y]-'0';

            dp[x][y]=best;
            ways[x][y]=cnt%MOD;

            return {dp[x][y],ways[x][y]};
        };

        auto [score,cnt]=dfs(n-1,n-1);

        if(score==-1) return {0,0};
        return {score,cnt};
    }
};