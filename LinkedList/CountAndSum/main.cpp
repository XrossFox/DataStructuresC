#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        Node* head;
        Node* tmp;
        Node* last;

        LinkedList(){}

        ~LinkedList(){
            delete head;
            delete tmp;
            delete last;
        }

        void init_from_array(int* le_array, int size){
            head = new Node;
            head->data = le_array[0];
            head->next = nullptr;
            last = head;

            for(int i = 1; i < size; i++){
                tmp = new Node;
                tmp->data = le_array[i];
                tmp->next = nullptr;
                last->next = tmp;
                last = tmp;
            }
        }
        
        void recursive_display(Node* first){
            if(first != nullptr){
                cout<<first->data<<" -> ";
                recursive_display(first->next);
            }
        }

        int count(){
            int len = 0;
            Node *p = head;
            while(p){
                len++;
                p = p->next;
            }
            delete p;
            return len;
        }

        int sum_values(){
            int sum = 0;
            Node* p = head;
            while(p){
                sum += p->data;
                p = p->next;
            }
            delete p;
            return sum;
        }
};

int main(){
    int A[] = {3, 5, 7, 10, 15, 20, 30 ,50};
    LinkedList ll;
    ll.init_from_array(A, 8);
    ll.recursive_display(ll.head);
    cout<<"\nlen is: "<<ll.count()<<"\n";
    cout<<"the sum of the elements is: "<<ll.sum_values()<<"\n";
    return 0;
}

