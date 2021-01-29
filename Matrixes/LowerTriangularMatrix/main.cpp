#include <iostream>
using namespace std;

class LowerTriangularMatrix{
    public:
        LowerTriangularMatrix(int size){
            this->size = size;
            inner_array = new int[size*(size+1)/2];
        }

        void set(int row, int col, int value){
            if(row >= col){
                inner_array[row*(row-1)/2+col-1] = value;
            }
        }

        int get(int row, int col){
            if(row >= col){
                return inner_array[row*(row-1)/2+col-1];
            }
            return 0;
        }

        void display(){
            for(int i = 1; i <= size; i++){
                for(int j = 1; j <= size; j++){
                    if(i >= j){
                        cout<<inner_array[i*(i-1)/2+j-1]<<" ";
                    }
                    else{
                        cout<<0<<" ";
                    }
                }
                cout<<"\n";
            }
        }

        ~LowerTriangularMatrix(){
            delete [] inner_array;
        }

    private:
        int* inner_array;
        int size;
};

class LowerTriangularMatrixColMaj{
    public:
        LowerTriangularMatrixColMaj(int size){
            this->size = size;
            inner_array = new int[size*(size+1)/2];
        }

        void set(int row, int col, int value){
            if(row >= col){
                inner_array[row*(col-1)-(col-2)*(col-1)/2+row-col] = value;
            }
        }

        int get(int row, int col){
            if(row >= col){
                return inner_array[row*(col-1)-(col-2)*(col-1)/2+row-col];
            }
            return 0;
        }

        void display(){
            for(int i = 1; i <= size; i++){
                for(int j = 1; j <= size; j++){
                    if(i >= j){
                        cout<<inner_array[i*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
                    }
                    else{
                        cout<<0<<" ";
                    }
                }
                cout<<"\n";
            }
        }

        ~LowerTriangularMatrixColMaj(){
            delete [] inner_array;
        }

    private:
        int* inner_array;
        int size;
};

int rngeesus(int min, int max){
    return min + (rand() % static_cast<int>(max - min + 1));
}

int main(){
    int d;
    cout<<"enter matrix dimensions:\n";
    cin>>d;
    LowerTriangularMatrixColMaj ltm(d);
    
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= d; j++){
            ltm.set(i, j, rngeesus(1, 15));
        }
    }

    ltm.display();
    
}
