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

        int Min(){
            int min = A[0];
            int i;
            for(i = 1; i < length; i++){
               if(A[i] < min){
                    min = A[i];
                }
            }
            return min;
        }

        int Max(){
            int max = A[0];
            int i;
            for(i = 1; i < length; i++){
                if(A[i] > max){
                    max = A[i];
                }
            }
            return max;
        }

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

        void MultipleMissingElements2(){

            int low = Min();
            int h = Max();
            
            int * tmp = new int[h];
            for(int i = 0; i < h; i++) tmp[i] = 0;

            for(int i = 0; i < length; i++){
                tmp[A[i]]++;
            }

            for(int i = low; i < h; i++){
                if(tmp[i] == 0){
                    cout<<i<<endl;
                }
            }
            delete(tmp);
        }

        void SortedDuplicateElements(){
            int lastDuplicate = A[0];

            for(int i = 0; i < length; i++){
                if(A[i] == A[i+1] && A[i] != lastDuplicate){
                    cout<<A[i]<<endl;
                    lastDuplicate = A[i];
                }
            }
        }

        void SortedCountDuplicates(){
            int j = 0;
            for(int i = 0; i < length-1; i++){
                if(A[i] == A[i+1]){
                    j = i+1;
                    while(A[j] == A[i]) j++;
                    cout<<A[i]<<" Has appeared "<<j-i<<" times"<<endl;
                    i = j+1;
                }
            }
        }

        void SortedCountDuplicatesHash(){
            int maxLength = Max();
            int * tmp = new int[maxLength];
            for(int i = 0; i < maxLength; i++){
                tmp[i] = 0;
            }
            for(int i = 0; i < length; i++){
                tmp[A[i]]++;
            }

            for(int i = 0; i < maxLength; i++){
                if(tmp[i] > 1){
                    cout<<i<<" Has appeared: "<<tmp[i]<<" times\n";
                }
            }

            delete(tmp);
        }

        void UnsortedCountDuplicates(){
            int count = 1;
            for(int i = 0; i < length-1; i++){                
                if(A[i] != -1){
                    for(int j = i+1; j < length; j++){
                        if(A[i] == A[j]){
                           count++;
                           A[j] = -1;
                        }
                    }
                    if(count > 1){
                        cout<<A[i]<<" Has appeared "<<count<<" times\n";
                        count = 1;
                    }
                }
            }
        }

        void FindFromSum(int expectedSum){
            for(int i = 0; i < length-1; i++){
                for(int j = i+1; j < length; j++){
                    if(A[i] + A[j] == expectedSum){
                        cout<<A[i]<<" + "<<A[j]<<" = "<<expectedSum<<"\n";
                    }
                }
            }
            cout<<"END"<<endl;
        }

        void FindFromSumWithHash(int expectedSum){
            int * H = new int[Max()];
            for(int i = 0; i <= Max(); i++){
                H[i] = 0;
            }

            for(int i = 0; i < length; i++){
                if(H[expectedSum - A[i]] != 0){
                    cout<<A[i]<<" + "<<expectedSum - A[i]<< " = "<<expectedSum<<"\n";
                }
                H[A[i]]++;
            }
            cout<<"END"<<endl;
        }

        void FindFromSumSorted(int expectedSum){
            int i = 0;
            int j = length - 1;
            while(i < j){
                if(A[i] + A[j] == expectedSum){
                    cout<<A[i]<<" + "<<A[j]<<" = "<<expectedSum<<"\n";
                    i++;
                    j--;
                }
                else if(A[i] + A[j] < expectedSum){
                    i++;
                }
                else{
                    j--;
                }
            }
            cout<<"END"<<endl;
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

    arr1->Push(1);
    arr1->Push(3);
    arr1->Push(4);
    arr1->Push(5);
    arr1->Push(6);
    arr1->Push(8);
    arr1->Push(9);
    arr1->Push(10);
    arr1->Push(12);
    arr1->Push(14);

    arr1->Display();
    cout<<"Expected Sum: "<<endl;
    arr1->FindFromSumSorted(10);

    return 0;
};