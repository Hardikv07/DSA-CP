struct Trie{
    Trie* links[2] = {nullptr};

    bool contains(int bit)
    {
        return links[bit]!=nullptr;
    }

    void put(int bit,Trie* node)
    {
        links[bit] = node;
    }

    Trie* get(int bit)
    {
        return links[bit];
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

   int getMx(int num)
   {
    int mx = 0;
    Trie *tmp = root;
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


    int findMaximumXOR(vector<int>& nums) {

        
        for(auto it : nums)
        {
          insert(it);
        }

        int ans = 0;
        for(auto it : nums)ans = max(ans,getMx(it));
        return ans;
    }
};