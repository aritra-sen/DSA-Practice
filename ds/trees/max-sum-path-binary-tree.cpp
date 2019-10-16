#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
int maxSumPath(Node *node);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    cout<<maxSumPath(root)<<endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this method*/
int maxSum(Node* root,int &sum)
{
  if(root == NULL)
    return 0;

  int l = maxSum(root->left,sum);
  int r = maxSum(root->right,sum);

  // Case Where I take left tree + current Node + Right Tree path
  int max_turning_here = l + r + root->data;
  // Case where I travel through current Node upwards
  int max_through_here = max(max(l,r) + root->data,root->data);

  sum = max(max_through_here,max_turning_here);
  return max_through_here;
}

int maxSumPath(Node* node)
{
  int ans = 0;
  maxSum(node,ans);
  return ans;
}
