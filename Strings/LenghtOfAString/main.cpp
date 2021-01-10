#include <iostream>
using namespace std;

class StringOperations{
    public:
        StringOperations() {};
        int GetLength();
};

int StringOperations::GetLength(){
    cout<<"whatever"<<endl;
    return 0;
}

StringOperations* createObject(){
    StringOperations *so = new StringOperations();
    return so;
}

void objectbyRef(StringOperations *&obj){
    obj->GetLength();
}

void objectbyRef2(int &obj){
    cout<<obj<<endl;
}

int main(){
    int a = 15;
    int* b = new int;
    *b = 156;
    StringOperations* kek = createObject();
    kek->GetLength();
    objectbyRef(kek);
    objectbyRef2(a);
    objectbyRef2(*b);
    delete kek;
    return 0;
};