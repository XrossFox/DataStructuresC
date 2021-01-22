#include <iostream>
using namespace std;

class ReverseAString{
    public:
        char* reverse_string_1(char char_array[]){
            int size = 0;
            for(size = 0; char_array[size] != '\0'; size++){
            }
            char* new_array = new char[size];
            size--;
            int j = 0;
            for(j = 0; size >= 0; size--, j++){
                new_array[j] = char_array[size];
            }
            new_array[j] = '\0';
            return new_array;
        }

        void reverse_string_2(char* char_array){
            int size;
            int i = 0;
            char t;
            
            for(size = 0; char_array[size] != '\0'; size++){}
            size--;
            
            for(i = 0; i < size; i++, size--){
                t = char_array[i];
                char_array[i] = char_array[size];
                char_array[size] = t;
            }
        }
};

int main(){
    char char_array[] = "Python";
    char char_array_2[] = "Python3";
    ReverseAString ras;
    char* new_array = ras.reverse_string_1(char_array);
    cout<<"original: "<<char_array<<" reverse: "<<new_array;
    cout<<"\n";
    cout<<"original: "<<char_array_2;
    ras.reverse_string_2(char_array_2);
    cout<<" reverse: "<<char_array_2;

}