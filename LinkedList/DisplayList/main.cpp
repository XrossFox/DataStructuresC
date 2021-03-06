#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

int main(){
    // list init
    int A[] = {3, 5, 7, 10, 15, 20, 30 ,50};
    Node* head = new Node;
    Node* tmp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // fill list
    for(int i = 1; i < sizeof(A)/sizeof(A[0]); i++){
        tmp = new Node;
        tmp->data = A[i];
        tmp->next = nullptr;

        last->next = tmp;
        last = tmp;

    }

    // display
    Node* p = head;

    while(p != nullptr){
        cout << p->data << " -> " << flush;
        p = p->next;
    }

    return 0;
}

