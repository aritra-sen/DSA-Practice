#include<iostream>
using namespace std;

template<class T>
class LinkedList
{
  class Node
  {
    T data;
    Node* next;
    public:
    Node(T data)
    {
        this.data = data;
        this.next = NULL;
    }
  };
  Node* head;
  public :
  void insert_at_beginning(T val)
  {
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
  }
  void insert_at_middle(T val,int pos)
  {
    if(pos==1)
      insert_at_beginning(val);
    else
    {
      Node* temp = head;
      pos--;
      while(--pos && temp!=NULL)
        temp = temp->next;
      Node* add = new Node(val);
      add->next = temp->next;
      temp->next = add;
    }
  }

  void insert_at_end(T val)
  {
    if(head==NULL)
      head = new Node(val);
    else if(head->next==NULL)
      head->next = new Node(val);
    else
    {
      Node* temp = head;
      while(temp->next!=NULL)
        temp=temp->next;
      temp->next = new Node(val);
    }
  }

  void delete_head()
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  void delete_pos(int pos)
  {
    if(pos==1)
      delete_head();
    else
    {
      pos--;
      Node* temp = head;
      while(--pos && temp!=NULL)
        temp = temp->next;
      Node* sub = temp->next;
      if(sub!=NULL)
        temp->next = sub->next;
      else
        temp->next = NULL;
      delete sub;
    }
  }

  void delete_val(T val)
  {
    if(head->data == val)
      delete_head();
    else
    {
      Node* temp = head;
      while(temp->next!=NULL)
      {
        if(temp->next->data==val)
        {
          Node* del = temp->next;
          temp->next = temp->next->next;
          delete del;
          break;
        }
      }
    }
  }

  void delete_intermediate_when_node_given(Node* node)
  {
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
  }

  bool checkLoop()
  {
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
        return true;
    }
    return false;
  }

  Node* findLoopHead()
  {
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
        break;
    }
    if(fast==NULL ||  fast->next==NULL)
      return NULL;
    else
    {
      fast = head;
      while(fast!=slow)
      {
        slow=slow->next;
        fast=fast->next;
      }
      return slow;
    }
  }

  void removeTheLoop()
  {
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
        break;
    }
    if(fast==NULL ||  fast->next==NULL)
      return ;
    else
    {
      fast = head;
      while(fast->next!=slow->next)
      {
        slow=slow->next;
        fast=fast->next;
      }
      slow->next = NULL;
    }
  }

  Node* getMiddle()
  {
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if(slow==fast)
        return NULL;
    }
    return slow;
  }
  void RotateByKCounterClock(int k)
  {
    Node* temp = head;
    if(k==0)
      return ;
    while(--k)
    {
      if(temp->next==NULL)
        temp=head;
      else
        temp=temp->next;
    }
    Node* end = temp;
    while(end->next!=NULL)
      end=end->next;
    end->next=head;
    head=temp->next;
    temp->next = NULL;
  }

//ToDO: To complete
/*
  void RotateByKClock(int k)
  {
    Node* temp = head;

  }
*/

  void reverse()
  {
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        Node* tmp = temp->next;
        temp->next = prev;
        prev = temp;
        temp = tmp;
    }
    head = prev;
  }

  void deleteLinkedList()
  {
    Node* temp = head;
    while(temp!=NULL)
    {
        Node* prev = temp;
        temp=temp->next;
        prev->next = NULL;
        delete prev;
    }
    head = NULL;
  }

};


int main()
{
    return 0;
}
