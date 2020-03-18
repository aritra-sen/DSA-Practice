#include <iostream>
#include <climits>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int maxim = a[0];
        int curr_min = a[0],curr_max = a[0];
        for(int i=1;i<n;i++)
        {
            int temp = curr_min;
            curr_min = min(min(curr_min*a[i],curr_max*a[i]),a[i]);
            curr_max = max(max(temp*a[i],curr_max*a[i]),a[i]);
            maxim = max(maxim,curr_max);
        }
        cout<<maxim<<"\n";
    }
	return 0;
}
