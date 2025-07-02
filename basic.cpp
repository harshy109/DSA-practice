#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

Node* insertAtHead(int value, Node* &head, Node* &tail){
    //if LL is empty -> head and tail both NULL ko point kr rhe honge
    if(head == NULL && tail == NULL){
        //1. create a node
        Node* newNode = new Node(value);
        //2. head ko node par laga do
        head = newNode;
        //3. tail ko node par laga do
        tail = newNode;
    }
    else{
        // LL is not empty
        //insert at head
        //1. Create node
        Node* newNode = new Node(value);
        //2. Connect newNode to head node
        newNode->next = head;
        //3. head update kardo
        head = newNode;
    }
    return head;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    //LL is empty
    head = insertAtHead(10, head, tail);
    //10->NULL
    head = insertAtHead(20, head, tail);
    //20->10->NULL
    head = insertAtHead(30, head, tail);
    //30->20->10->NULL

    //stack memory
    //Node first;
    //Dynamic memory
    //Node* first = new Node(10);
    return 0;
}