#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int sum_left[n],sum_right[n];
	    sum_left[0]=a[0];
	    sum_right[n-1]=a[n-1];
	    for(int i=1;i<n;i++)
	        sum_left[i]=sum_left[i-1]+a[i];
	    for(int i=n-2;i>=0;i--)
	        sum_right[i]=sum_right[i+1]+a[i];
	    bool flag = false;
	    for(int i=0;i<n;i++)
	    {
	        int x = i>0?sum_left[i-1]:0;
	        int y = i<n-1?sum_right[i+1]:0;
	        if(x==y)
	        {
	            flag = true;
	            cout<<(i+1)<<"\n";
	            break;
	        }
	    }
	    if(!flag)
	        cout<<"-1\n";
	}
	return 0;
}
