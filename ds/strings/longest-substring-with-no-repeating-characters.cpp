#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        string a;
        cin>>a;
        int n = a.size();
        int wR = 1;
        int ans = 1;
        int lastseen[256];
        int curr = 1;
        memset(lastseen,-1,sizeof(lastseen));
        lastseen[a[0]] = 0;
        while(wR<n)
        {
            int c = a[wR];
            if(lastseen[c]==-1 || lastseen[c]<(wR - curr))
                curr++;
            else
            {
                ans = max(ans,curr);
                curr = wR - lastseen[c];
            }
            lastseen[c] = wR;
            wR++;
        }
        ans = max(ans,curr);
        cout<<ans<<"\n";
    }
	return 0;
}
