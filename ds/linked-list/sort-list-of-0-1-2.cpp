#include <bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;
struct Node* sortList(struct Node *head);
// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("");
}
/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}
int main() {
    int n;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        insert(n);
        struct Node *newHead = sortList(start);
        printList(newHead);
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* sortList(Node *head) {
    Node* Zero = new Node(-1);
    Node* One = new Node(-1);
    Node* Two = new Node(-1);
    Node* OneStart = One;
    Node* ZeroStart = Zero;
    Node* TwoStart = Two;
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            Zero->next = temp;
            Zero = Zero->next;
            temp = temp->next;
        }
        else if(temp->data == 1)
        {
            One->next = temp;
            One = One->next;
            temp = temp->next;
        }
        else if(temp->data == 2)
        {
            Two->next = temp;
            Two = Two->next;
            temp = temp->next;
        }
    }
    Zero->next = OneStart->next ? OneStart->next : TwoStart->next;
    One->next = TwoStart->next;
    Two->next = NULL;

    head = ZeroStart->next;

    delete ZeroStart,OneStart,TwoStart;
    return head;
}
