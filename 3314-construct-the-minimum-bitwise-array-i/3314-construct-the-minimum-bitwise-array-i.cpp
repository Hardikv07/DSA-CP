class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(auto &it : nums)
        {
            if((it&(it+1))==0)
            {
                it = (it+1)/2 - 1;
            }
            else
            {
                if(it==2)it=-1;
                else
                {
                   int p2=0;
                   while((it&(1<<p2))!=0)
                   {
                     p2++;
                   }
                   p2--;
                   it = min(it-1,it^(1<<p2));
                }
            }
        }
        return nums;
    }
};