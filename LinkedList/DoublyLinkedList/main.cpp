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

        /**
         * Inserts a new element into the list at the given index
         * @param index: the position to insert at.
         * @param value: the actual value.
         */
        void insertAt(int index, T value){
            
            Node<T> * currentNode = head;
            Node<T> * newNode = nullptr;

            if(index < 0 || index > lenght()){
                throw std::runtime_error("Index out of bounds.");
            }
            
            if(!currentNode){

                newNode = new Node<T>;
                newNode->data = value;
                newNode->previous = nullptr;
                newNode->next = nullptr;
                head = newNode;
                tail = head;

            }
            else if(index == 0){

                newNode = new Node<T>;
                newNode->data = value;
                newNode->previous = nullptr;
                newNode->next = currentNode;
                currentNode->previous = newNode;
                head = newNode;

            }
            else{

                for(int i = 0; i < index-1; i++){
                    currentNode = currentNode->next;
                }

                newNode = new Node<T>;
                newNode->data = value;
                newNode->previous = currentNode;
                newNode->next = currentNode->next;
                if(currentNode->next){
                    currentNode->next->previous = newNode;
                }
                currentNode->next = newNode;

            }

        }

        /**
         * Deletes the node at the given index
         * @param index: The index of the node to be deleted.
         * @return The value of the deleted node.
         */
        T deleteAt(int index){
            
            Node<T> * currentNode = head;
            T value;

            if(index < 0 || index > lenght() || lenght() == 0){
                throw std::runtime_error("Index out of bounds.");
            }

            if(index == 0){

                value = currentNode->data;
                head = currentNode->next;
                if(head){
                    head->previous = nullptr;
                }
                else{
                    tail = nullptr;
                }

                delete currentNode;

            }
            else{

                for(int i = 0; i < index; i++){
                    currentNode = currentNode->next;
                }

                currentNode->previous->next = currentNode->next;
                if(currentNode->next){
                    currentNode->next->previous = currentNode->previous;
                }
                else{
                    tail = currentNode->previous;
                }
                value = currentNode->data;
                delete currentNode;
            }

            return value;
        }
};

int main(){

    DoublyLinkedList<std::string> dbll;
    try{
        dbll.deleteAt(0);
    }catch(const std::exception &e){
        std::cerr<<"holy cow, mate, you fell for it, list is empty: "<<e.what()<<"\n";
    }
    try{
        dbll.deleteAt(-1);
    }catch(const std::exception &e){
        std::cerr<<"under zero: "<<e.what()<<"\n";
    }
    try{
        dbll.deleteAt(15);
    }catch(const std::exception &e){
        std::cerr<<"beyond the size of the list: "<<e.what()<<"\n";
    }

    dbll.add("La wea come galletas!");
    dbll.display();
    dbll.deleteAt(0);
    dbll.add("la wea");
    dbll.add("cuatica");
    dbll.add("cosmica");
    dbll.display();
    dbll.deleteAt(1);
    dbll.display();
    dbll.deleteAt(1);
    dbll.add("Ajua!");
    dbll.display();
}