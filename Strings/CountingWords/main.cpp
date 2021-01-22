#include <iostream>
using namespace std;

class WordCounter{
    public:
        int count(char char_array[]){
            int words = 0;
            for(int i = 0; char_array[i] != '\0'; i++){
                if(char_array[i] == ' ' && char_array[i-1] != ' '){
                    words++;
                }
            }
            if(words > 0){
                words++;
            }
            return words;
        }
};

int main(){
    char char_array_1[] = "how are you";
    char char_array_2[] = "how are    u";
    // warning, it doesn't work with string that are pure blank spaces
    char char_array_3[] = "   ";

    WordCounter wd;
    cout<<"1: "<<wd.count(char_array_1)<<"\n";
    cout<<"2: "<<wd.count(char_array_2)<<"\n";
    cout<<"3: "<<wd.count(char_array_3)<<endl;
}