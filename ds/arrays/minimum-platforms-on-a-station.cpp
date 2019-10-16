#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arrival[n],dept[n];
        for(int i=0;i<n;i++)
            cin>>arrival[i];
        for(int i=0;i<n;i++)
            cin>>dept[i];
        sort(arrival,arrival+n);
        sort(dept,dept+n);
        int i=1,j=0;
        int p = 1 , r = 1;
        while(i<n && j<n)
        {
            if(arrival[i]<=dept[j])
            {
                p++;
                i++;
                r = max(p,r);
            }
            else
            {
                p--;
                j++;
            }
        }
        cout<<r<<"\n";
    }
	return 0;
}
