#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }
        else if(QueryType==2)
            cout<<qs->pop()<<" ";
        cout<<"\n";
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.size()==0)
        return -1;
    while(q1.size()>1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int x = q1.front();
    q1.pop();
    swap(q1,q2);
    return x;
}
