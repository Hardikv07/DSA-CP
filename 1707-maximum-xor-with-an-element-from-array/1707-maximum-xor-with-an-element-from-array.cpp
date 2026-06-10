struct Trie{
    Trie* bits[2] = {nullptr};

    void put(int bit,Trie* node)
    {
        bits[bit] = node;
    }

    Trie* get(int bit)
    {
        return bits[bit];
    }

    bool contains(int bit)
    {
        return bits[bit]!=nullptr;
    }
};

class Solution {
public:
    Trie* root = new Trie();

    void insert(int num)
    {
        Trie* tmp = root;
        for(int i=30; i>=0; i--)
        {
            int bit = (num>>i)&1;
            if(!tmp->contains(bit))
            {
                tmp->put(bit,new Trie());
            }
            tmp = tmp->get(bit);
        }
    }

    int maxi(int num)
    {
        Trie* tmp = root;
        int mx = 0;
        for(int i=30; i>=0; i--)
        {
            int bit = (num>>i)&1;
            if(tmp->contains(1-bit))
            {
                mx |= (1<<i);
                tmp = tmp->get(1-bit);
            }
            else
            {
                tmp = tmp->get(bit);
            }
        }
        return mx;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int m =q.size();
        vector<int> ans(m);
        sort(nums.begin(),nums.end());
        vector<pair<pair<int,int>,int>> v;
        for(int i=0; i<m; i++)
        {
           v.push_back({{q[i][1],q[i][0]},i});
        }
        sort(v.begin(),v.end());
        int idx = 0;

        for(auto it : v)
        {
            int y = it.first.second;
            int x = it.first.first;
            int pos = it.second;

            if(nums[idx]>x && !idx)
            {
                ans[pos]=-1;
                continue;
            }

            while(idx<n && nums[idx]<=x)
            {
                insert(nums[idx]);
                idx++;
            }

            ans[pos] = maxi(y);
        }
        return ans;
    }
};