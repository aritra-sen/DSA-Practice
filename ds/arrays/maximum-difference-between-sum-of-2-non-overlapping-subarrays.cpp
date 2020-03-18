#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],leftMin[n],rightMin[n],leftMax[n],rightMax[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int min_sum = 1001, min_sum_till = 1001;
	    for(int i=0;i<n;i++)
	    {
	        min_sum_till = min(min_sum_till+a[i],a[i]);
	        min_sum = min(min_sum,min_sum_till);
	        leftMin[i] = min_sum;
	    }
	    min_sum = 1001;
	    min_sum_till = 1001;
	    for(int i=n-1;i>=0;i--)
	    {
	        min_sum_till = min(min_sum_till+a[i],a[i]);
	        min_sum = min(min_sum,min_sum_till);
	        rightMin[i] = min_sum;
	    }
	    int max_sum = -1001, max_sum_till = -1001;
	    for(int i=0;i<n;i++)
	    {
	        max_sum_till = max(max_sum_till+a[i],a[i]);
	        max_sum = max(max_sum,max_sum_till);
	        leftMax[i] = max_sum;
	    }
	    max_sum = -1001;
	    max_sum_till = -1001;
	    for(int i=n-1;i>=0;i--)
	    {
	        max_sum_till = max(max_sum_till+a[i],a[i]);
	        max_sum = max(max_sum,max_sum_till);
	        rightMax[i] = max_sum;
	    }
	    int ans = 0;
	    for(int i = 0;i<n-1;i++)
	    {
	        ans = max(ans,abs(leftMax[i]-rightMin[i+1]));
	        ans = max(ans,abs(leftMin[i]-rightMax[i+1]));
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
