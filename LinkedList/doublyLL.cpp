#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* pre;
    Node(int data)
    {
          this->data=data;
          this->next=NULL;
          this->pre=NULL;

    }
    ~Node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            this->next=NULL;
            delete next;
        }
           cout << " memory is free for node with data " << value << endl;
    }
};
void insertAtHead(Node * &head,Node * &tail,int d)
{  Node* temp =new Node(d);
    if(head==NULL)
    {
       head=temp;
       tail=temp;
    }else{
   
    temp->next=head;
    head->pre=temp;
    head=temp;
    }
}
void insertAtTail(Node* &head,Node *&tail,int d)
{
  Node* temp =new Node(d);
  if(tail==NULL)
    {  head=temp;
       tail=temp;
    }else{
  temp->pre=tail;
  tail->next=temp;
  tail=temp;
    }
}
void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(head,tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
     temp -> next->pre = nodeToInsert;
     temp->next=nodeToInsert;
     nodeToInsert->pre=temp;
}

void print(Node * &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(Node* &head)
{
    Node *temp=head;
    int cnt=0;
    while (temp!=NULL)
    {
        /* code */
        cnt++;
        temp=temp->next;

    }
    return cnt;
    
}
void deleteNode(int position, Node* & head,Node * & tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
       temp->next->pre=NULL;
       head=temp->next;
       temp->next=NULL;
       delete temp;

    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
          if(curr->next==NULL)
          {
              tail=prev;
          }
          curr->pre=NULL;
          prev->next=curr->next;
          curr->next=NULL;
          delete curr;

    }
}
int main()
{   
   
    Node*head=NULL;
    Node*tail=NULL;
   // cout<<"length :"<<getLength(head)<<endl;
    insertAtHead(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtPosition(tail,head,3,4);
    print(head);
    deleteNode(3,head,tail);
    print(head);
    cout<<"head:"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    return 0;
}