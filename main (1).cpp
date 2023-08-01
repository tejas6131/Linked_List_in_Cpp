#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

node* head=NULL;


void insert(int x)
{
    node *new_node=new node(x);
    new_node->next=head;
    head=new_node;
}




void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}





void reverseLinkedList(){
    node *prev=NULL;
    node *next=NULL;
    node *curr=head;
    
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    head=prev;
    
}




node* reverseLinkedList(node* head)
{
    node *temp=head;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    temp=reverseLinkedList(head->next);
    
    head->next->next=head;
    head->next=NULL;
    
    return temp;
    
}






void insertAfter(int n,int data)
{
    if(n==0)
    {
        node* new_node=new node(data);
        new_node->next=head;
        head=new_node;
        return;
    }
    int i=1;
    node* ptr=head;
    while(i<n)
    {
        if(ptr->next==NULL)
        {
            node *new_node=new node(data);
            ptr->next=new_node;
            new_node->next=NULL;
            return;
        }
        ptr=ptr->next;
        i++;
    }
    node *new_node=new node(data);
    new_node->next=ptr->next;
    ptr->next=new_node;
    
}






int main()
{
    insert(10);
    insert(20);
    insert(15);
    cout<<"The linked list is :"<<endl;
    display();
    cout<<endl;
    reverseLinkedList();
    cout<<"The Reversed linked list is :"<<endl;
    display();
    cout<<endl;
    head=reverseLinkedList(head);
    cout<<"The Reversed linked list using recursion :"<<endl;
    display();
    cout<<endl;
    int i=0;
    int data=30;
    insertAfter(i,data);
    cout<<"The linked list after adding "<<data<<" at position "<<i<<" : "<<endl;
    display();
}