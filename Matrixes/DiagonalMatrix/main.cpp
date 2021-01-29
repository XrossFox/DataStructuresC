#include <iostream>
using namespace std;

class Diagonal{
    public:
        Diagonal(int size){
            this->size = size;
            inner_array = new int[size];
        }

        void set(int row, int col, int value){
            if(row == col){
                inner_array[row-1] = value;
            }
        }

        int get(int row, int col){
            if(row == col){
                return inner_array[row-1];
            }
            return 0;
        }

        void display(){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(i == j){
                        cout<<inner_array[i]<<" ";
                    }
                    else{
                        cout<<0<<" ";
                    }
                }
                cout<<"\n";
            }
        }

        ~Diagonal(){
            delete [] inner_array;
        }

    private:
        int* inner_array;
        int size;
};

int main(){
    Diagonal dm(4);
    dm.set(1,1,1);
    dm.set(2,2,1);
    dm.set(3,3,1);
    dm.set(4,4,1);
    dm.display();
    cout<<dm.get(1,1)<<"\n";
    cout<<dm.get(2,1)<<"\n";
}
