#include <iostream>
using namespace std;

class Anagrams{
    public:
        bool check(char* char_array_1, char* char_array_2){
            int i;
            int hash_table[26];

            int size1 = 0;
            int size2 = 0;

            for(int j = 0; char_array_1[j] != '\0'; j++){
                size1++;
            }

            for(int j = 0; char_array_2[j] != '\0'; j++){
                size2++;
            }

            if(size1 != size2){
                return false;
            }

            for(int j = 0; j < 26; j++){
                hash_table[j] = 0;
            }

            for(i = 0; char_array_1[i] != '\0'; i++){
                hash_table[char_array_1[i] - 97] += 1;
            }

            for(i = 0; char_array_2[i] != '\0'; i++){
                hash_table[char_array_1[i]-97] -= 1;
                if(hash_table[char_array_1[i]-97] < 0){
                    return false;
                }
            }
            return true;
        }

};

int main(){
    char array1[] = "decimal";
    char array2[] = "medical";
    char array3[] = "decima";
    char array4[] = "medicals";
    char array5[] = "lana";
    char array6[] = "anal";
    Anagrams an;
    cout<<array1<<" : "<<array2<<" : "<<an.check(array1, array2)<<"\n";
    cout<<array3<<" : "<<array4<<" : "<<an.check(array3, array4)<<"\n";
    cout<<array5<<" : "<<array6<<" : "<<an.check(array5, array6)<<"\n";
}
