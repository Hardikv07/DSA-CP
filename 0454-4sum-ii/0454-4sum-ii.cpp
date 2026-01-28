
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int a = nums1.size();
        int b = nums2.size();
        int c = nums3.size();
        int d = nums4.size();
        int cnt = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                mpp[nums1[i]+nums2[j]]++;
            }
        }

        for(int j=0; j<c; j++)
        {
            for(int i=0; i<d; i++)
            {
                cnt += mpp[-(nums3[j]+nums4[i])];
            }
        }
        return cnt;
    }
};