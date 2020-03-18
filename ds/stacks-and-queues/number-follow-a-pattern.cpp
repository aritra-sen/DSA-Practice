#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string x;
        cin>>x;
        string decrypt="";
        stack<char> s;
        int n=x.size();
        for(int i=0;x[i];i++)
        {
            s.push(i+1+'0');
            while(!s.empty() && x[i]=='I')
            {
                decrypt+=s.top();
                s.pop();
            }
        }
        s.push('0'+x.size()+1);
        while(!s.empty())
        {
            decrypt+=s.top();
            s.pop();
        }
        cout<<decrypt<<"\n";

    }
    return 0;
}
