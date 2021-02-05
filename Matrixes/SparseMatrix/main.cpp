#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Element{

    public:
        int row;
        int column;
        int value;
};

class SparseMatrix{
    private:
        int rows;
        int columns;
        int num;
        Element* matrix;

        int rngeesus(int min, int max){
            return min + (rand() % static_cast<int>(max - min + 1));
        }

    public:
        SparseMatrix(int rows, int columns, int num){
            this->rows = rows;
            this->columns = columns;
            this->num = num;
            srand((unsigned int)time(0));
            matrix = new Element[this->num];
        }

        ~SparseMatrix(){
            delete[] matrix;
        }

        void initialize_randomly(){
            for(int i = 0; i < num; i++){
                matrix[i].row = rngeesus(0, rows-1);
                matrix[i].column = rngeesus(0, columns-1);
                matrix[i].value = rngeesus(1, 20);
                cout<<"row: "<<matrix[i].row<<" column: "<<matrix[i].column<<" value: "<<matrix[i].value<<"\n";
            }
        }

        int search(int row, int column){
            for(int i = 0; i < num; i++){
                if(matrix[i].row == row && matrix[i].column == column){
                    return matrix[i].value;
                }
            }
            return -1;
        }

        void display(){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    int k = search(i, j);
                    if(k > 0){
                        cout<<k<<" ";
                    }
                    else{
                        cout<<"0 ";
                    }
                }
                cout<<"\n";
            }
        }
};

int main(){
    SparseMatrix mt1(5,5,5);
    mt1.initialize_randomly();
    mt1.display();
}
