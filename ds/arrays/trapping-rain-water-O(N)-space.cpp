#include <iostream>
using namespace std;

int main() {
	int  t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int  i=0;i<n;i++)
	        cin>>a[i];
	    int max_l[n],max_r[n];
	    max_l[0]=0;
	    max_r[n-1]=0;
	    for(int i=1;i<n;i++)
	        max_l[i]=max(a[i-1],max_l[i-1]);
	    for(int i=n-2;i>=0;i--)
	        max_r[i]=max(a[i+1],max_r[i+1]);
	    int val = 0;
	    for(int i=0;i<n;i++)
	    {
	        int barrier = min(max_l[i],max_r[i]);
	        if(a[i]<barrier)
	            val+=barrier-a[i];
	    }
	    cout<<val<<"\n";
	}
	return 0;
}
