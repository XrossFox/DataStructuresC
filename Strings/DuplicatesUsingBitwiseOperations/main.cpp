#include <iostream>

using namespace std;

class DuplicatesUsingBitwiseOperations{
    public:
        void find(char* char_array){
            long int H = 0;
            long int x = 0;
            for(int i = 0; char_array[i] != '\0'; i++){
                cout<<" current char: "<<char_array[i]<<"\n";
                x = 1;
                x = x<<char_array[i]-97;

                if(x&H < 0){
                    cout<<char_array[i]<<" is a duplicate\n";
                }
                else{
                    H = x | H;
                }
            }
        }

};

int main(){
    char char_array_1[] = "bbasadbb";
    char char_array_2[] = "blitzkrieg";
    char char_array_3[] = "gawr gura";

    DuplicatesUsingBitwiseOperations dubo;

    dubo.find(char_array_1);
    dubo.find(char_array_2);
    dubo.find(char_array_3);
}
