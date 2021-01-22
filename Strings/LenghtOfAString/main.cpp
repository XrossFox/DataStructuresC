#include <iostream>
using namespace std;

class StringOperations{
    public:
        StringOperations() {};
        int GetLength(char *myStringArray);
};

int StringOperations::GetLength(char *myStringArray){
    int i;
    for(i = 0; myStringArray[i] != '\0'; i++){
        // Hai Domo!
    }
    return i;
}

int main(){
    char thisString[] = "Hai Domooooo";
    StringOperations so;
    int n = so.GetLength(thisString);
    cout<<n<<endl;
}
/*
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
*/