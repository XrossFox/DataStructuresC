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

        int max(){
            int m = INT32_MIN;
            Node* p = head;

            while(p){
                if(p->data > m){
                    m = p->data;
                }
                p = p->next;
            }
            delete p;
            return m;
        }

        int max_recursive(Node *p){
            int x = INT32_MIN;
            if(p == 0){
                return x;
            }
            x = max_recursive(p->next);
            if(x > p->data){
                return x;
            }
            else{
                return p->data;
            }
        }

        int linear_search(int value){
            Node* p = head;
            
            while (p)
            {
                if(value == p->data){
                    delete p;
                    return value;
                }
                p = p->next;
            }
            delete p;
            throw runtime_error("value not found");
        }

        int linear_search_move_to_head(int value){
            Node* p = head;
            Node* q = nullptr;
            
            while (p)
            {
                if(value == p->data){
                    q->next = p->next;
                    p->next = head;
                    head = p;
                    delete p;
                    delete q;
                    return value;
                }
                q = p;
                p = p->next;
            }
            delete p;
            delete q;
            throw runtime_error("value not found"); 
        }

        void insert(int index, int value){
            if(index < 0 || index > count()){
                throw runtime_error("Index out of bounds");
            }
            Node* current_node = head;
            Node* new_node = new Node;
            new_node->data = value;
            if(index == 0){
                new_node->next = current_node;
                head = new_node;
            }
            else{
                for(int i = 0; i < index; i++){
                    current_node = current_node->next;
                }
                new_node->next = current_node->next;
                current_node->next = new_node;
            }
        }

        void sorted_insert(int value){
            Node * p = head;
            Node * t;
            Node * q = nullptr;

            t = new Node;
            t->data = value;
            t->next = nullptr;

            if(head == nullptr){
                head = t;
                delete p, t, q;
                return;
            }
            else{
                while(p && p->data < value){
                    q = p;
                    p = p->next;
                }
                if(p == head){
                    t->next = head;
                    head = t;
                    delete p, t, q;
                    return;
                }
                else{
                    t->next = q->next;
                    q->next = t;
                    delete p, t, q;
                    return;
                }
            }
            throw runtime_error("Could not be inserted");
        }

        int delete_node(int index){
            Node * current_node = head;
            Node * trailing_node = nullptr;
            int x = 0;

            if(index < 1 || index > count()){
                throw runtime_error("Error: index not found");
            }
            if(index == 1){
                trailing_node = head;
                x = head->data;
                head = head->next;
                delete trailing_node, current_node;
                return x;
            }
            else{
                for(int i = 0; i < index-1; i++){
                    trailing_node = current_node;
                    current_node = current_node->next;
                }
                trailing_node->next = current_node->next;
                x = current_node->data;
                delete trailing_node, current_node;
                return x;
            }

            throw runtime_error("Error: index not found");
        }

        bool is_sorted(){
            int value = INT32_MIN;
            Node * current_node = head;

            while(current_node){
                if(current_node->data < value){
                    return false;
                }
                value = current_node->data;
                current_node = current_node->next;
            }
            return true;
        }
};

int main(){
    int A[] = {3, 5, 7};
    LinkedList ll;
    ll.init_from_array(A, 3);
    ll.recursive_display(ll.head);
    cout<<"\nIs sorted?: "<<ll.is_sorted();
    cout<<"-----\n";
    int B[] = {3, 8, 7};
    LinkedList ll2;
    ll2.init_from_array(B, 3);
    ll2.recursive_display(ll2.head);
    cout<<"\nIs sorted?: "<<ll2.is_sorted();

    return 0;
}

