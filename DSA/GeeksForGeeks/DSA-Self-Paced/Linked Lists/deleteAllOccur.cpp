// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

  // TO BE REMOVED
  for (int i=0; i<2000; i++);


    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    printList(head);
    }
    return 0;
}

// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node *deleteNode(Node *prv, Node *curr, Node *head)
{
    if(curr == head)
    {
        head = curr->next;
        free(curr);
        return head;
    }
    else
    {
        prv->next = curr->next;
        curr->next = NULL;
        free(curr);
        return head;
    }
}

Node* deleteAllOccurances(Node *head, int x)
{
    if(head == NULL)
        return head;
    
    Node *temp = head;
    Node *prv;
    
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            if(temp == head)
            {
                head = temp->next;
                free(temp);
                temp = head;
            }
            else
            {
                prv->next = temp->next;
                temp->next = NULL;
                free(temp);
                temp = prv;
            }
        }
        
        prv = temp;
        temp = temp->next;
    }
    
    return head;
}
