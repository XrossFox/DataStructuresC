#include <iostream>
using namespace std;

class DuplicateInString{
    public:
        void find(char* array_1){
            int hash_table[26];

            for(int i = 0; i < 26; i++){
                hash_table[i] = 0;
            }

            for(int i = 0; array_1[i] != '\0'; i++){
                hash_table[array_1[i]-97]++;
            }

            for(int i = 0; i < 26; i++){
                if(hash_table[i] > 1){
                    cout<<char(i+97)<<" : "<<hash_table[i]<<"\n";
                }
            }
        }
};

int main(){
    char array_1[] = "alohomora";
    char array_2[] = "thisistijuana";
    char array_3[] = "this";

    DuplicateInString dis;
    dis.find(array_1);
    cout<<"-----"<<"\n";
    dis.find(array_2);
    cout<<"-----"<<"\n";
    dis.find(array_3);

}