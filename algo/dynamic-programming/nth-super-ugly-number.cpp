class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int ugly[n];
        ugly[0]=1;
        int p = primes.size();
        int index[p];
        int next[p];
        for(int i=0;i<p;i++)
            next[i]=primes[i];
        memset(index,0,sizeof(index));
        for(int i=1;i<n;i++)
        {
            int min = *min_element(next,next+p);
            ugly[i] = min;
            for(int j=0;j<p;j++)
            {
                if(min == next[j])
                {
                    index[j]++;
                    int ind = index[j];
                    next[j] = ugly[ind]*primes[j];

                }
            }
        }
        return ugly[n-1];
    }
};
