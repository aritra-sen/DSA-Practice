/*
 * Giving a dictionary and a string ‘str’, your task is to find the longest string in dictionary of size x
 * which can be formed by deleting some characters of the given ‘str’.
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 bool isSubseq(string orig,string small)
 {
     if(small.size()>orig.size())
         return false;
     int j = 0;
     for(int i=0;i<orig.size() && j<small.size();i++)
     {
         if(orig[i]==small[j])
             j++;
     }
     if(j==small.size())
         return true;
     return false;
 }

 int main() {
 	int t;
 	cin>>t;
 	while(t--)
 	{
 	    int n;
 	    cin>>n;
 	    vector<string> dict;
 	    for(int i=0;i<n;i++)
 	    {
 	        string x;
 	        cin>>x;
 	        dict.push_back(x);
 	    }
 	    string str;
 	    cin>>str;
 	    string ans = "";
 	    for(string x : dict)
 	    {
 	        if(isSubseq(str,x))
 	            ans = ans.size()<(x).size()?x:ans;
 	    }
 	    cout<<ans<<"\n";
 	}
 	return 0;
 } 
