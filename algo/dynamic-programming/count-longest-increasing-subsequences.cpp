class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,0);
        vector<int> count(n,0);
        int max=0,ans=0;
        for(int i=0;i<n;i++)
        {
            LIS[i]=count[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(LIS[j]+1==LIS[i])
                    {
                        count[i]+=count[j];
                    }
                    else if(LIS[j]+1>LIS[i])
                    {
                        count[i] = count[j];
                        LIS[i] = LIS[j]+1;
                    }
                }
            }
            if(max<LIS[i])
            {
                max = LIS[i];
                ans = count[i];
            }
            else if(max == LIS[i])
            {
                ans+=count[i];
            }
        }
        return ans;
    }
};
