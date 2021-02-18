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
        Node* last;

        LinkedList(){
            head = nullptr;
            last = nullptr;
        }

        LinkedList(const LinkedList &linked_list){
            head = nullptr;
            last = nullptr;
            Node * current_node = linked_list.head;

            while(current_node){
                this->push(current_node->data);
                current_node = current_node->next;
            }
        }

        ~LinkedList(){
            delete head;
            delete last;
        }

        void init_from_array(int* le_array, int size){
            for(int i = 0; i < size; i++){
                this->push(le_array[i]);
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
            return len;
        }

        int sum_values(){
            int sum = 0;
            Node* p = head;
            while(p){
                sum += p->data;
                p = p->next;
            }
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
                    return value;
                }
                p = p->next;
            }
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
                    return value;
                }
                q = p;
                p = p->next;
            }
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
                    return;
                }
                else{
                    t->next = q->next;
                    q->next = t;
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
                return x;
            }
            else{
                for(int i = 0; i < index-1; i++){
                    trailing_node = current_node;
                    current_node = current_node->next;
                }
                trailing_node->next = current_node->next;
                x = current_node->data;
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

        void remove_duplicate(){
            Node * current_node = head;
            Node * forward_node = current_node->next;

            while(forward_node != nullptr){

                if(current_node->data != forward_node->data){
                    current_node = forward_node;
                    forward_node = forward_node->next;
                }
                else{
                    current_node->next = forward_node->next;
                    if(forward_node == last){
                        last = current_node;
                    }
                    forward_node = current_node->next;
                }
            }
        }

        void reverse_elements(){
            Node * current_element = head;
            int * tmp_array;
            int i = 0;
            tmp_array = new int[count()];

            while(current_element != nullptr){
                tmp_array[i] = current_element->data;
                current_element = current_element->next;
                i++;
            }

            current_element = head;
            i--;

            while(current_element != nullptr){
                current_element->data = tmp_array[i];
                current_element = current_element->next;
                i--;
            }
            delete [] tmp_array;
        }

        void reverse_links(){
            Node * trailing_node = head;
            Node * current_node = nullptr;
            Node * previous_node = nullptr;
            bool new_last = true;
            
            while(trailing_node){
                previous_node = current_node;
                current_node = trailing_node;
                trailing_node = trailing_node->next;
                current_node->next = previous_node;
                if(new_last){
                    last = current_node;
                    new_last = false;
                }
            }
            head = current_node;
        }
        /**
         * DO NOT PASS THE BOOL ARGUMENT. IT´S USED TO CHECK WHEN TO SET
         * LAST NODE OF THE LIST.
         */
        void reverse_recursively(Node * previous_node, Node * current_node, bool is_first=true){
            if(current_node){
                if(is_first){
                    last = current_node;
                }
                reverse_recursively(current_node, current_node->next, false);
                current_node->next = previous_node;
            }
            else{
                head = previous_node;
            }
        }

        void display(){
            Node * current_node = head;
            while(current_node){
                cout<<current_node->data<<" -> ";
                current_node = current_node->next;
            }
        }

        /**
         * push a value at the end of the list. If "head" is nullptr, then
         * adds a value at the head, and points "last" to head.
         */
        void push(int value){
            Node * new_node = new Node;
            new_node->data = value;
            new_node->next = nullptr;

            if(head == nullptr){
                head = new_node;
                last = head;
                return;
            }
            last->next = new_node;
            last = new_node;
        }

        LinkedList concat(LinkedList second){

            LinkedList new_list;
            Node * current_node = head;

            while(current_node){
                new_list.push(current_node->data);
                current_node = current_node->next;
            }

            current_node = second.head;

            while(current_node){
                new_list.push(current_node->data);
                current_node = current_node->next;
            }
            return new_list;
        }

        LinkedList merge(LinkedList second){
            Node * current_primary = head;
            Node * current_secondary = second.head;
            LinkedList new_list;

            if(current_primary->data < current_secondary->data){
                new_list.push(current_primary->data);

                current_primary = current_primary->next;
            }
            else{
                new_list.push(current_secondary->data);

                current_secondary = current_secondary->next;
            }

            while(current_primary && current_secondary){
                if(current_primary->data < current_secondary->data){
                    new_list.push(current_primary->data);
                    current_primary = current_primary->next;
                }
                else if(current_secondary->data < current_primary->data){
                    new_list.push(current_secondary->data);
                    current_secondary = current_secondary->next;
                }
            }

            if(current_primary){
                while(current_primary){
                    new_list.push(current_primary->data);
                    current_primary = current_primary->next;
                }
            }

            if(current_secondary){
                while(current_secondary){
                    new_list.push(current_secondary->data);
                    current_secondary = current_secondary->next;
                }
            }

            return new_list;
        }

        bool is_loop(){
            
            Node * current_node = head;
            Node * previous_node = head;

            do{
            
                current_node = current_node->next;
                previous_node = previous_node->next;
                current_node = current_node ? current_node->next: current_node;
            
            }
            while(current_node && previous_node && current_node != previous_node);

            if(current_node == previous_node){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){

    int A[] = {1, 2, 3, 4, 5, 6};
    
    LinkedList ll, ll2;
    ll.init_from_array(A, 6);
    ll2.init_from_array(A, 6);
    // there is a loop since the last node now points to node 3 instead of nullptr
    ll.last->next = ll.head->next->next;
    cout<<"List 1: "<<ll.is_loop()<<"\n";
    cout<<"List 2: "<<ll2.is_loop()<<"\n";

    return 0;
}

