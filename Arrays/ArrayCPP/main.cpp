#include <iostream>
using namespace std;

template <class T> 
class Array { 

    private:
        T* A;
        int size;
        int length;

    public:
        Array(){

            size = 10;
            length = 0;
            A = new T[size];
        }

        Array(int sz){

            size = sz;
            length = 0;
            A = new T[size];
        }

        ~Array(){

            delete []A;
        }

        void Display();
        void Insert(int index, T x);
        T Delete(int index);

};

template <class T>
void Array<T>::Display(){
    std::cout << "\nElements are\n";
    
    for (int i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

template<class T>
void Array<T>::Insert(int index, T x){

    if(index >= 0 && index <= length){

        for(int i = length - 1; i > index; i--){

            A[i+1] = A[i];
        }
        
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index){

    T x;
    if(index >= 0 && index < length){
        x = A[index];
        for(int i = index; i < length - 1; i++){
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}

int main(){

    Array<char> arr(10);

    arr.Insert(0, 'a');
    arr.Insert(1, 'x');
    arr.Insert(2, 'c');
    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();
    return 0;
}

/*
int Array::LinearSearch(int key){

    int i;
    for(i = 0; i < length; i++){
        
        if(key == A[i]){

            Swap(&A[i], &A[i-1]);
            return i;
        }
    }
    return -1;
}

void Array::Swap(int *x, int *y){

    int tempo;
    tempo = *x;
    *x = *y;
    *y = tempo;

}

int Array::BinarySearch(int key){

    int low = 0;
    int mid;
    int high = length-1;

    while(low <= high){

        mid = (low + high) / 2;

        if(key == A[mid]){
            return mid;
        }
        else if(key < A[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;
} 

int Array::Get(int index){

    if(index >= 0 && index < length){
        return A[index];
    }

    return -1;
}

void Array::Set(int index, int x){
    if(index >= 0 && index < length){
        A[index] = x;
    }
}

int Array::Max(){
    int max = A[0];
    int i;
    for(i = 1; i < length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    int i;
    for(i = 1; i < length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::Sum(){
    int s = 0;
    int i;
    for(i = 0; i < length; i++){
        s += A[i];
    }
    return s;
}

double Array::Avg(){
    return (double) Sum()/length;
}

void Array::Reverse (){
    int *B;
    int i;
    int j;

    B = new int[length];
    for(i = length-1, j=0; i >= 0; i--, j++){
        B[j] = A[i];
    }
    for(i = 0; i < length; i++){
        A[i] = B[i];
    }

}

void Array::Reverse2(){

    int i;
    int j;

    for(i = 0, j = length-1; i < j; i++, j--){

        Swap(&A[i], &A[j]);
    }
}

void Array::InsertSort(int x){

    int i = length-1;
    if(length == size){
        return;
    }
    while(i >= 0 && A[i] > x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;

}

bool Array::IsSorted(){

    int i;
    for(i = 0; i < length-1; i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }
    return true;
}

void Array::Rearrange(){

    int i;
    int j;
    i = 0;

    while(i < j){

        while(A[i] < 0) i++;
        while(A[j] >= 0) j--;
        if(i < j) Swap(&A[i], &A[j]);
    }
}

Array Array::Merge(struct Array arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    Array *arr3 = new Array(length + arr2.getLength);

    while(i < length && j < arr2.length){
        if(A[i] < arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else{
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for(;i < length; i++){
        arr3->A[k++] = A[i];
    }
    for(;j < arr2.length; j++){
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;

    return arr3;
}
*/