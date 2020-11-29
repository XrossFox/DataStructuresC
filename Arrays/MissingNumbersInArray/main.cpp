#include <iostream>
using namespace std;

template <class T>
class Array{

    private:
        T *A;
        int size;
        int length;

    public:
        Array(){
            size = 10;
            A = new T[10];
            length = 0;
        }

        Array(int sz){
            size = sz;
            length = 0;
            A = new T[size];
        }
        
        ~Array(){

        }

        void Display();
        void Insert(int index, T x);
        T Delete(int index);
        void Push(T value);
        T Sum();

        /*
        * This method returns a missing element when Array is an array of natural numbers (1 to infinity)
        * and the array start from 1.
        */
        T MissingElement(){
            T expectedSum = (A[length-1]*(A[length-1] + 1))/2;
            T actualSum = 0;
            return expectedSum - Sum();
        }

        /*
        * this method returns the missing elemnt when the starting element in the array is not 1
        */
        int MissingElementDiff(){
            T low = A[0];
            T h = A[length-1];
            T diff = low - 0;

            for(int i = 0; i < length; i++){
                if(A[i] - i != diff){
                    return i + diff;
                }
            }

        }

        /**
         * Prints the missing elements of a sequence of numbers.
         */
        void MultipleMissingElements(){

            T low = A[0];
            T h = A[length-1];
            T diff = low - 0;

            for(int i = 0; i < length; i++){
                // found a missing element
                if(A[i]-i != diff){
                    // if old diff is less than new diff, it means there is a gap of elements between them
                    while(diff < A[i]-i){
                        cout<<i+diff<<endl;
                        diff++;
                    }
                }
            }

        }
};

template<class T>
void Array<T>::Display(){
    for (int i=0; i < length; i++){
        cout<<A[i]<<" ";
    cout<<endl;
    }
}

template<class T>
void Array<T>::Insert(int index, T x){
    if(index >= 0 && index <= length){
        for(int i = length-1; i >= index; i--){
            A[i+1] = A[i];
        }
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index){
    int x;
    if(index >= 0 && index < length){
        x = A[index];
        for(int i = index; i < length-1; i++){
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}

template<class T>
void Array<T>::Push(T value){
    A[length] = value;
    length++;
}

template<class T>
T Array<T>::Sum(){
    T sum = 0;
    for(int i = 0; i < length; i++){
        sum += A[i];
    }
    return sum;
}

int main(int argc, const char * argv[]){
    Array<int> *arr1 = new Array<int>();
    arr1->Push(6);
    arr1->Push(7);
    arr1->Push(8);
    arr1->Push(9);
    arr1->Push(10);
    arr1->Push(11);
    arr1->Push(13);
    arr1->Push(14);
    arr1->Push(15);
    arr1->Push(16);
    arr1->Push(18);
    arr1->Push(21);

    arr1->Display();
    cout<<"Missing: "<<endl;
    arr1->MultipleMissingElements();
    //cout<<"Sum is: "<<arr1->Sum()<<"\n";
    //cout<<"Missing number is: "<<arr1->MissingElementDiff();
    return 0;
};