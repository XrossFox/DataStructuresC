#include <iostream>
#include <utility>
using namespace std;

class StringVowelConsonantCounter{
    public:

        pair<int, int> count_characters(char char_array[]){
            pair<int, int> vowel_consonant;
            int vowels = 0;
            int consonants = 0;
            for(int i = 0; char_array[i] != '\0'; i++){
                if(char_array[i]=='a'|| char_array[i]=='A'||
                    char_array[i]=='e'|| char_array[i]=='E'||
                    char_array[i]=='i'|| char_array[i]=='I'||
                    char_array[i]=='o'|| char_array[i]=='O'||
                    char_array[i]=='u'|| char_array[i]=='U'){

                    vowels++;
                }
                else if(char_array[i] == ' '){
                    continue;
                }
                else if((char_array[i] >= 65 || char_array[i] <= 90) ||
                         (char_array[i] >= 97 || char_array[i] <= 122) ){
                    
                    consonants++;
                }
            }

            vowel_consonant.first = vowels;
            vowel_consonant.second = consonants;
            return vowel_consonant;
        }

};

int main(){
    char char_array[] = "How are you";
    StringVowelConsonantCounter svcc;
    pair<int, int> vo_co;
    vo_co = svcc.count_characters(char_array);
    cout<<"Vowels: "<<vo_co.first<<"\n"<<"Consonants: "<<vo_co.second<<endl;
}