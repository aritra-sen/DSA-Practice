#include <iostream>
using namespace std;

void merge(int a[],int l,int mid,int r, long &ans)
{
    int temp[r-l+1];
    int i = l,j = mid+1,k=0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
            temp[k++] = a[i++];
        else
        {
            ans += mid - i + 1;
            temp[k++] = a[j++];
        }
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=r)
        temp[k++] = a[j++];
    k = 0;
    for(int i=l;i<=r;i++)
        a[i] = temp[k++];
}

void solve(int a[],int l,int r,long &ans)
{
    if(l<r)
    {
        int mid =  (l + r)/2;
        solve(a,l,mid,ans);
        solve(a,mid+1,r,ans);
        merge(a,l,mid,r,ans);
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)  cin>>a[i];
	    long inv_count = 0;
	    solve(a,0,n-1,inv_count);
	    cout<<inv_count<<"\n";
	}
	return 0;
}
