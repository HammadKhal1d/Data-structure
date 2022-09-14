#include<iostream>
using namespace std;
 
class node{
 
    public:
    int data;
    node* next;
 
    node(int val){
        data=val;
        next=NULL;
    }
};
 
void insertAtHead(node* &head, int val){
    node* n=new node(val);
 
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
 
void insertAtTail(node* &head, int val){
 
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
 
    node* n = new node(val);
    node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
 
    temp->next=n;
    n->next=head;
}
 
void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
 
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
 
    delete todelete;
}
 
void deletion(node* &head, int pos){
 
    if(pos==1){
        deleteAtHead(head);
        return;
    }
      node* temp=head;
      int count=1;
 
      while(count!=pos-1){
          temp=temp->next;
          count++;
      }
 
      node* todelete=temp->next;
      temp->next=temp->next->next;
 
      delete todelete;
}
 
void display(node* head){
 
 
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
}
 
 
int main(){
 
    node* head=NULL;
    int size,no;
    cout<<"no of Nodes:";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        int ele;
        cout<<"Enter elemenet: ";
        cin>>ele;
    insertAtTail(head,ele);

    }
    
    display(head);
    insertAtHead(head,5);
    display(head);
    cout<<"Node no you want to delete: ";
    cin>>no;
    deletion(head,no);
    display(head);
    
 
    return 0;
}