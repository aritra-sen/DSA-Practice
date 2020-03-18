//Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}

	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();

	return p1<p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];

        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);

        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;

        cout<<f;
        cout<<endl;

    }
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*The function should return a string denoting the
order of the words in the Alien Dictionary */
string printOrder(string dict[], int N, int k)
{
    string order = "";
    vector<int> adj[k];
    for(int i=1;i<N;i++)
    {
        string curr = dict[i],prev = dict[i-1];
        for(int j=0;j<min(curr.size(),prev.size());j++)
        {
            if(curr[j]!=prev[j])
            {
                adj[prev[j]-'a'].push_back(curr[j]-'a');
                break;
            }
        }
    }
    vector<int> inorder(k,0);
    for(int i=0;i<k;i++)
        for(int x : adj[i])
            inorder[x]++;

    queue<int> q;
    for(int i=0;i<k;i++)
        if(inorder[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int top = q.front();
        order += top+'a';
        q.pop();
        for(int x : adj[top])
        {
            if(--inorder[x] == 0)
                q.push(x);
        }
    }
    return order;
}
