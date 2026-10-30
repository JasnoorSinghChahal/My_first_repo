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
    Node* sixth = new Node(6);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "Before Moving:" << endl;
    printlist(head);
    cout <<" "<<endl;
    
    int k = 2;
    int i = 0;
    
    Node* tempp = head;
    
    while(tempp != NULL){
        i++;
        tempp = tempp -> next;
    }
    
    Node* temp1 = head;
    for (int j = 0; j < i - k - 1; j++){
        temp1 = temp1->next;
    }
    Node* newHead = temp1->next;
    temp1 -> next = NULL;
    
    Node* temp = newHead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head = newHead;

    cout <<"After Moving" << endl;
    printlist(head);
}