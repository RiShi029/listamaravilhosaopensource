// Singly Linked lists
#include <iostream>
#include <map>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  
  //constructor
  Node(int data)
  {
    this->data=data;
    this->next=NULL;
  }
  
  //destructor
  ~Node()
  {
      int val=this->data;
      //memory free
      if(this->next!=NULL)
      {
          delete next;
          this->next=NULL;
      }
      cout<<"Memory is free for node : "<<val<<endl;
  }
};
void insertAtHead(Node* &head,int data)
{
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
    
}
void insertAtTail(Node* &tail,int data)
{
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtPos(Node* &head, Node* &tail,int p,int d)
{
    if(p==1)
    {
        insertAtHead(head,d);
        return;
    }
    int c=1;
    Node* temp=head;
    while(c<p-1)
    {
        temp=temp->next;
        c++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node* insert=new Node(d);
    insert->next=temp->next;
    temp->next=insert;
    
    
}
void deleteNode(Node* &head,Node* &tail,int pos)
{
    if(pos==1)
    {
        //Node at first position
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //Node at middle or last position
        
        Node* curr=head;
        Node* prev=NULL;
        
        int c=1;
        while(c<=pos)
        {
            prev=curr;
            curr=curr->next;
            c++;
        }
        prev->next=curr->next;
        if(prev->next ==NULL)
        tail=prev;
        curr->next=NULL;
        delete curr;
        
    }
}
bool isCircularNode(Node* head)
{
    if(head==NULL)
    return false;

    Node* temp=head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    if(temp==head)
    return true;

    return false;

}
bool detectLoop(Node* head)
{
    if(head==NULL)
    return false;

    map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        return true;

       visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
bool floydCircularDetect(Node* head)
{
    if(head==NULL)
    return false;
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        fast=fast->next;

        slow=slow->next;
    }
    if(fast==slow)
    return true;

    return false;
}
int main()
{
    // cout<<"Hello World";
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
     
    insertAtTail(tail,12);
    insertAtTail(tail,14);
    insertAtTail(tail,18);
    // print(head);
    insertAtPos(head,tail,4,16);
    // print(head);
    
    // deleteNode(head,tail,4);
    // print(head);
    tail->next=head->next;
    // print(head);
    // cout<<"Head data : "<<head->data<<endl;
    // cout<<"Tail data : "<<tail->data<<endl;

    /*
    if(isCircularNode(head))
    cout<<"List is Circular.."<<endl;
    else
    cout<<"List is not circular"<<endl;
    */

    if(detectLoop(head))
    cout<<"List is Circular.."<<endl;
    else
    cout<<"List is not circular"<<endl;
    return 0;
}
