#include <iostream>
using namespace std;

class StringPermutator{
    public: 
        StringPermutator(int flag_size, int char_array_size){
            flag_array = new int[flag_size];
            for(int i = 0; i < char_array_size; i++){
                flag_array[i] = 0;
            }
            res_array = new char[char_array_size];
        }

        StringPermutator(){

        }

        void permute(char* char_array, int k){
            int i = 0;
            if(char_array[k] == '\0'){
                res_array[k] = '\0';
                cout<<"->"<<res_array<<"<-"<<"\n";
            }
            else{
                for(i = 0; char_array[i] != '\0'; i++){
                    if(flag_array[i] == 0){
                        res_array[k] = char_array[i];
                        flag_array[i] = 1;
                        permute(char_array, k+1);
                        flag_array[i] = 0;
                    }
                }
            }
        }

        void permute_2(char* char_array, int l, int h){
            if(l == h){
                cout<<"->"<<char_array<<"<-\n";
            }
            else {
                for(int i = l; i <=h; i++){
                    swap(char_array, l, i);
                    permute_2(char_array, l+1, h);
                    swap(char_array, l, i);
                }
            }
        }

        ~StringPermutator(){
            delete flag_array;
            delete res_array;
        }

    private:
        int* flag_array;
        char* res_array;

        void swap(char* char_array, int a, int b){
            char tmp = char_array[b];
            char_array[b] = char_array[a];
            char_array[a] = tmp;
        }
};

int main(){
    char my_string[] = "ABCD";
    int char_size1;
    for(char_size1 = 0; my_string[char_size1] != '\0'; char_size1++){}

    StringPermutator sp1(char_size1+1, char_size1);
    sp1.permute(my_string, 0);
    
    cout<<"--------------"<<"\n";
    
    char my_string_2[] = "ABCD";
    int char_size2;
    for(char_size2 = 0; my_string_2[char_size2] != '\0'; char_size2++){}

    StringPermutator sp2; 
    sp2.permute_2(my_string_2, 0, char_size2-1);

}