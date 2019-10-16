#include<iostream>
using namespace std;

template<class T>
class Trie
{
  class Node
  {
    public:
    int endFor;
    Node* next[26];
    Node()
    {
        for(int i=0;i<26;i++)
          next[i]=NULL;
        endFor = 0;
    }
  };
  Node* root;
  public:
  Trie()
  {
    root = new Node();
  }
  void insert(string x)
  {
    Node* temp = root;
    for(int i=0;i<x.size();i++)
    {
      if(temp->next[x[i]-'a']==NULL)
        temp->next[x[i]-'a'] = new Node();
      temp = temp->next[x[i]-'a'];
    }
    temp->endFor++;
  }
  bool search(string x)
  {
    Node* temp = root;
    for(int i=0;i<x.size();i++)
    {
      if(temp->next[x[i]]-'a')==NULL)
        return false;
      temp = temp->next[x[i]-'a'];
    }
    if(temp->endFor > 0)
      return true;
    else
      return false;
  }

  bool hasChild(Node* head)
  {
    for(int i=0;i<26;i++)
      if(head->next[i]!=NULL)
        return true;
    return false;
  }

  bool deleter(string x,int i,Node* head)
  {
    if(i==x.size() && head->endFor > 0)
    {
      head->endFor = 0;
      if(hasChild(head))
        return false;
      delete head;
      head = NULL;
      return true;
    }
    else
    {
      if(head != NULL && head->next[x[i]-'a']!=NULL && deleter(x,i+1,head->next[x[i]-'a']) && temp->endFor == 0)
      {
        if(hasChild(head))
          return false;
        delete head;
        head = NULL;
        return true;
      }
    }
    return false;
  }
  void delete(string x)
  {
    deleter(x,0,root);
  }


};

int main()
{
  return 0;
}
