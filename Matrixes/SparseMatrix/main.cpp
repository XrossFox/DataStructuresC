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

        friend istream& operator>>(istream & is, SparseMatrix & mat);
        friend ostream& operator<<(ostream & os, SparseMatrix & mat);
        SparseMatrix * operator+(SparseMatrix & mat);
};

istream & operator>>(istream & is, SparseMatrix & mat)
{
    cout<<"Enter Non-Zero elements\n";
    for(int i = 0; i < mat.num; i++){
        cin>>mat.matrix[i].row>>mat.matrix[i].column>>mat.matrix[i].value;
    }
    return is;
}

ostream & operator<<(ostream & os, SparseMatrix & mat){
    for(int i = 0; i < mat.rows; i++){
        for(int j = 0; j < mat.columns; j++){
            int k = mat.search(i, j);
            if(k > 0){
                cout<<k<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
    return os;
}

SparseMatrix * SparseMatrix::operator+(SparseMatrix & mat){
    int i = 0;
    int j = 0;
    int k = 0;

    if(rows != mat.rows || columns != mat.columns){
        return NULL;
    }
    SparseMatrix * sum = new SparseMatrix(rows, columns, num + mat.num);
    while(i < num && j < mat.num){
        if(matrix[i].row < mat.matrix[j].row){
            sum->matrix[k++] = matrix[i++];
        }
        else if(matrix[i].row > mat.matrix[j].row){
            sum->matrix[k++] = mat.matrix[j++];
        }
        else{
            if(matrix[i].column < mat.matrix[j].column){
                sum->matrix[k++] = matrix[i++];
            }
            else if(matrix[i].column > mat.matrix[j].column){
                sum->matrix[k++] = mat.matrix[j++];
            }
            else{
                sum->matrix[k] = matrix[i];
                sum->matrix[k++].value = matrix[i++].value + mat.matrix[j++].value;
            }
        }
    }

    for(;i < num; i++){
        sum->matrix[k++] = matrix[i];
    }
    for(;j < num; j++){
        sum->matrix[k++] = matrix[j];
    }

    sum->num = k;
    sum->display();
    return sum;
}

int main(){
    SparseMatrix mt1(5,5,5);
    SparseMatrix mt2(5,5,5);
    //mt1.initialize_randomly();
    //mt1.display();
    //cin>>mt1;
    //cout<<mt1;
    cin>>mt1;
    cin>>mt2;

    SparseMatrix * sum = mt1 + mt2;

    cout<<"First: \n"<<mt1;
    cout<<"sECOND: \n"<<mt2;
    cout<<"Sum: \n";
    sum->display();

    return 0;
}
