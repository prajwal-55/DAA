//Insert aT Head 
//Insert aT Tail
//Insert aT Middle

#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    //Destructor
    ~Node(){
        int val = this->data;

        if(next != NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};

// traversing a Linked List
void print(Node* &head){

    Node* temp= head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//gives length of Linked List
int getLength(Node* &head){

    int len=0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

//Inserting at front or last 
void insertAtHead(Node* &head,int d){

    Node* temp = new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

//Inserting at last or end
void insertAtTail(Node* &tail,int d){

    Node* temp = new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

//Insertion at nth position
void insertAtPosition(Node* &tail,Node* &head,int position,int d){

    //Insert At Start
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int cnt=1;

    while(cnt < position -1 ){
        temp=temp->next;
        cnt++;
    }

    //Inserting at last position
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    //Creating a Node for d
    Node* NodeToInsert= new Node(d);

    NodeToInsert->next=temp->next;
    NodeToInsert->prev=temp;
    temp->next=NodeToInsert;
    temp->next->prev=NodeToInsert;
}

//Deleting the Node
void deleteNode(int position,Node* &head){

    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        curr->prev=NULL;
        prev -> next =curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    print(head);
    //cout<<getLength(head)<<endl;

    insertAtHead(head,11);
    print(head);

    insertAtHead(head,87);
    print(head);
    
    insertAtHead(head,45);
    print(head);

    insertAtTail(tail,23);
    print(head);

    insertAtTail(tail,77);
    print(head);

    insertAtPosition(tail,head,4,53);
    print(head);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;

    deleteNode(7,head);
    print(head);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;


return 0;
}