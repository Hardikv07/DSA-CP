class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n = (int)nums.size();

        auto fun = [&](int num,int idx)->void{
             for(int i=2; i*i<=num; i++)
             {
                if(num%i==0)
                {
                    mpp[i].push_back(idx);
                    while(num%i==0)num/=i;
                }
             }
             if(num>1)
             {
                mpp[num].push_back(idx);
             }
        };

        vector<int> vis(n+1);

        for(int i=0; i<n; i++)
        {
            mpp[nums[i]].push_back(i);
            fun(nums[i],i);
        }

        queue<int> q;
        q.push(0);

        int jumps = 0;

        auto isp = [&](int num)->bool{
            if(num==0 || num==1)return false;
            for(int i=2; i*i<=num; i++)if(num%i==0)return false;
            return true;
        };

        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto cur = q.front();
                q.pop();
                if(cur==n-1)return jumps;
                if(vis[cur])continue;
                vis[cur]=1;
                if(isp(nums[cur]))
                {
                    if(mpp.count(nums[cur]))
                    {
                       auto it = mpp[nums[cur]];
                       for(auto j  : it)if(!vis[j])q.push(j);
                       mpp.erase(nums[cur]);
                    }
                }

                if(cur+1<n && !vis[cur+1])
                {
                    q.push(cur+1);
                }
                
                if(cur-1>=0 && !vis[cur-1])
                {
                    q.push(cur-1);
                }
            }
            jumps++;
        }
        return -1;
    }
};