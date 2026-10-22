class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))return 0;
        int n = nums.size();

        int pos0 = -1;
        for(int i=0; i<n; i++)
            {
                if(nums[i]==0)
                {
                    pos0=i;
                    break;
                }
            }
        int tmp = n;
        int idx = pos0;
        int f = 0;
        int st = 0;
        while(tmp--)
            {
                // cout << idx%n << " " << st << "\n";
                
                if(nums[idx%n]!= st)
                {
                    break;
                }
                idx++,st++;
                if(idx==pos0)break;
            }

        f |= (tmp>0);

        if(tmp<=0)
        {
           return min(pos0,n-pos0+2);
        }

        tmp = n;
        idx=pos0;
        st=0;
        while(tmp--)
            {
                if(idx<0)idx=n-1;
                if(nums[idx]!=st)
                {
                    break;
                }
                st++,idx--;
                if(idx==pos0)break;
            }

        f &= (tmp>0);
        if(f)return -1;
        // return 7;

        return min((n-pos0),pos0+2);
        
    }
};