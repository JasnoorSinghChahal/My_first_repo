#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node (int value){
        data = value;
        next = nullptr;
    }
};

void deleteNode(Node* node1){
    if (node1 == nullptr || node1 -> next == nullptr){
        return;
    }
    node1 -> data = node1 -> next -> data;
    Node* temp = node1 -> next;
    node1 -> next = node1 -> next -> next;
    
    delete temp;
}

void printlist(Node* head){
    while (head != nullptr){
        cout << head->data << " -> ";
        head = head -> next;
    }
    cout << "Null" << endl;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    cout << "Before deletion :" << endl;
    printlist(head);
    cout << " "<<endl;
    
    Node* X = third;
    
    deleteNode(X);
    
    cout<<"After Deletion :"<<endl;
    printlist(head);
    
}