#include <stdio.h>
#include <iostream>
#include <string>

template<typename T>
class Node{
    public: 
        Node<T> * previous;
        T data;
        Node<T> * next;

        Node(){
            previous = nullptr;
            next = nullptr;
        }
};

template<typename T>
class DoublyLinkedList{
    public:
        Node<T> * head;
        Node<T> * tail;

        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        ~DoublyLinkedList(){
            
            Node<T> * currentNode = head;

            while(currentNode){
            
                Node<T> * temporalNode = currentNode;
                currentNode = currentNode->next;
                delete temporalNode;

            }

        }

        /**
         * Adds the given value at the end of the list.
         * If the lists is empty, the head and tail nodes are set to
         * the new node.
         * @param value: the value to add.
         */
        void add(T value){
            
            Node<T> * newNode = new Node<T>;
            newNode->data = value;

            if(head == nullptr){

                head = newNode;
                head->previous = nullptr;
                head->next = nullptr;
                tail = head;

            }
            else {

                newNode->previous = tail;
                tail->next = newNode;
                newNode->next = nullptr;
                tail = newNode;

            }

        }

        /**
         * Adds values from a raw array.
         * @param rawArray: the raw array that contains the values.
         * @param size: the size of the array.
         */
        void addFromRawArray(T* rawArray, int size){
            
            for(int i = 0; i < size; i++){
                this->add(rawArray[i]);
            }

        }

        /**
         * Prints the content of the list as a string.
         */
        void display(){
            
            Node<T> * currentNode = head;

            while(currentNode){
                
                std::cout<<currentNode->data<<" <-> ";
                currentNode = currentNode->next;

            }

            std::cout<<"\n";
        }

        /**
         * Returns the size of the list.
         * @return size of the list.
         */
        int lenght(){

            Node<T> * currentNode = head;
            int size = 0;

            while(currentNode){
                
                size++;
                currentNode = currentNode->next;

            }

            return size;
        }
};

int main(){

    DoublyLinkedList<std::string> dbll;
    dbll.add("Aloha!");
    dbll.add("Konichiwa!");
    dbll.add("Ohaiyo!");
    dbll.add("Holis!");
    dbll.display();
    std::cout<<"The list has: "<<dbll.lenght()<<" elements.\n";

    double A[] = {1.0, 1.1, 1.2, 1.3};
    DoublyLinkedList<double> dbll2;
    dbll2.addFromRawArray(A, 4);
    dbll2.display();
}