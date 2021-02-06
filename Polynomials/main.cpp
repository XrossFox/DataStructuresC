#include <iostream>
using namespace std;

class Term{
    public:
        int coefficient;
        int exponent;
};

class Polynomial{
    public:

        int length;
        Term * terms;

        Polynomial(int length){
            this->length = length;
            terms = new Term[this->length];
        }

        ~Polynomial(){
            delete [] terms;
        }

        Polynomial(const Polynomial& poly){
            length = poly.length;
            terms = new Term[length];

            for(int i = 0; i < length; i++){
                terms[i] = poly.terms[i];
            }
        }

        friend istream& operator>>(istream& is, Polynomial & poly);

        void display(){
            for(int i = 0; i < length; i++){
                cout<<terms[i].coefficient<<"x^"<<terms[i].exponent<<"+";
            }
            cout<<endl;
        }

        Polynomial operator+(const Polynomial& poly){
            Polynomial sum(length + poly.length);
            int i, j, k;
            i = j = k = 0;

            while(i < length && j < poly.length){
                if(terms[i].exponent > poly.terms[j].exponent){
                    sum.terms[k++] = terms[i++];
                }
                else if(terms[i].exponent < poly.terms[j].exponent){
                    sum.terms[k++] = poly.terms[j++];
                }
                else{
                    sum.terms[k].exponent = terms[i].exponent;
                    sum.terms[k++].coefficient =
                        terms[i++].coefficient + poly.terms[j++].coefficient;
                }
            }

            for(; i < length; i++){
                sum.terms[k++] = terms[i];
            }
            for(; j < poly.length; j++){
                sum.terms[k++] = poly.terms[j];
            }
            sum.length = k;
            return sum;
        }

};

istream& operator>>(istream& is, Polynomial & poly){

    cout<<"Enter Coefficient Exponent values:\n";
    for(int i = 0; i < poly.length; i++){
        cin>>poly.terms[i].coefficient>>poly.terms[i].exponent;
    }
    return is;
}

int main(){
    int len;
    cout<<"Hoe many terms? first\n";
    cin>>len;
    Polynomial poly1(len);
    cin>>poly1;

    int len2;
    cout<<"Hoe many terms? second\n";
    cin>>len2;
    Polynomial poly2(len2);
    cin>>poly2;

    Polynomial poly3 = poly1 + poly2;

    poly1.display();
    poly2.display();
    poly3.display();

    return 0;
}