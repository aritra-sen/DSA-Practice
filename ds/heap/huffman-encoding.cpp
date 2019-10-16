#include<iostream>
#include<queue>
#include<utility>
using namespace std;

class Node
{
  public:
    char ch;
    int freq;
    Node *left,*right;
    Node(int freq,char ch,Node* left=NULL,Node* right=NULL)
    {
      this->ch = ch;
      this->freq = freq;
      this->left = left;
      this->right = right;
    }
};

class comp
{
    public:
    bool  operator()(Node* x,Node* y)
    {
      return x->freq > y->freq;
    }
};

void encode(Node* root,string code,string codes[])
{
  if(root->ch != '\0')
  {
    codes[root->ch - 'a'] = code;
    return ;
  }
  encode(root->left,code+"0",codes);
  encode(root->right,code+"1",codes);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x;
    cin>>x; //x --> String to be Huffman Encoded
    priority_queue<Node*,vector<Node*>,comp> minHeap;
    int count[26]={0};
    for(int i=0;i<x.size();i++)
      count[x[i]-'a']++;
    for(int i=0;i<26;i++)
      minHeap.push(new Node(x[i],(char)(i+'a')));
    while(minHeap.size()>1)
    {
      Node* left = minHeap.top();
      minHeap.pop();
      Node* right = minHeap.top();
      minHeap.pop();
      minHeap.push(new Node(left->freq + right->freq,'\0',left,right));
    }
    Node* root = minHeap.top();  //root ---> root of Huffman Tree

    string code[26];
    encode(root,"",code);

    for(int i=0;i<26;i++)
     cout<<(char)(i+'a')<<" "<<code[i]<<"\n";
    cout<<"\n";
  }
  return 0;
}
