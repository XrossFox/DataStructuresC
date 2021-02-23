#include <iostream>

class Node{
    public:
        int data;
        Node * next;
};

class CircularLinkedList{
    public:
        Node * head;

        CircularLinkedList(){
            head = nullptr;
        }

        ~CircularLinkedList(){
            Node * currentNode;
            currentNode = head;
            while(currentNode->next != head){
                currentNode = currentNode->next;
            }

            currentNode->next = nullptr;
            currentNode = head;

            while(currentNode){
                Node * nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
            }
        }

        /**
         * Pushes a value to the end of the loop. This is, by finding
         * the value that points to the head node, 
         * then inserts at the end and closes the loop again.
         * @param value: int value to push
         */
        void push(int value){
            
            Node * newNode = new Node;
            Node * lastNode;
            Node * currentNode;
            newNode->data = value;

            if(head == nullptr){
                head = newNode;
                head->next = head;
                newNode = nullptr;
                return;
            }

            currentNode = head;
            while(currentNode->next != head){
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
            newNode->next = head;
            newNode = nullptr;
        }

        /**
         * Pushes elements from a raw array into de list
         * @param arr: arr C++ built in raw array.
         * @param size: the size of the array.
         */
        void pushFromRawArray(int arr[], int size){
            for(int i = 0; i < size; i++){
                this->push(arr[i]);
            }
        }

        /**
         * Prints content of list to Standard Output
         */
        void display(){
            Node * currentNode = head;
            do{
                std::cout<<":"<<currentNode->data<<" -> ";
                currentNode = currentNode->next;
            }while(currentNode != head);
            std::cout<<"\n";
        }

        /**
         * Prints content of list recursively to Standard Output.
         * @param currentNode: a pointer to the head of the list;
         * @param firstHead: a flag to check wether its the head node for the first time.
         * It must be true when called or there will be no putput.
         */
        void recursiveDisplay(Node * currentNode, bool firstHead = true){
            if(currentNode != head || firstHead == true){
                std::cout<<":"<<currentNode->data<<" -> ";
                recursiveDisplay(currentNode->next, false);
            }
        }

        /**
         * Returns the actual lenght of the circular linked list.
         */ 
        int lenght(){
            Node * currentNode = head;
            int nodes = 0;
            while(currentNode){
                nodes++;
                if(currentNode->next == head){
                    break;
                }
                currentNode = currentNode->next;
            }
            return nodes;
        }

        /**
         * Inserts the value at the givend index.
         * @param index: index to insert at.
         * @param value: value to insert.
         */
        void insert(int index, int value){
            Node * currentNode = head;
            Node * newNode;

            if(index < 0 || index > lenght()){
                throw std::runtime_error("Index out of bounds.");
            }

            if(index == 0){

                newNode = new Node;
                newNode->data = value;

                if(head == nullptr){

                    head = newNode;
                    head->next = head;

                }
                else{

                    while(currentNode->next != head){
                        currentNode = currentNode->next;
                    }

                    currentNode->next = newNode;
                    newNode->next = head;
                    head = newNode;

                }
            }
            else{

                newNode = new Node;
                newNode->data = value;
                
                for(int i = 0; i < index-1; i++){
                    currentNode = currentNode->next;
                }

                newNode->next = currentNode->next;
                currentNode->next = newNode;
                
            }
        }

        int deleteAt(int index){
            
            Node * currentNode = head;
            Node * forwardNode = nullptr;
            int value;

            if(index < 0 || index > lenght()){
                throw std::runtime_error("Index out of bounds.");
            }

            if(index == 0){

                while(currentNode->next != head){
                    currentNode = currentNode->next;
                }

                value = head->data;

                if(head == currentNode){

                    delete head;
                    head = nullptr;

                }
                else{

                    currentNode->next = head->next;
                    delete head;
                    head = currentNode->next;

                }

            }
            else{

                for(int i = 0; i < index-1; i++){
                    currentNode = currentNode->next;
                }

                forwardNode = currentNode->next;
                currentNode->next = forwardNode->next;
                value = forwardNode->data;
                delete forwardNode;

            }

            return value;
        }
};

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    CircularLinkedList cll;
    cll.pushFromRawArray(A, 7);
    std::cout<<"\ndelete 1\n";
    cll.deleteAt(0);
    cll.display();
    std::cout<<"\ndelete 4\n";
    cll.deleteAt(2);
    cll.display();
    std::cout<<"\ndelete 7\n";
    cll.deleteAt(4);
    cll.display();
    return 0;
}