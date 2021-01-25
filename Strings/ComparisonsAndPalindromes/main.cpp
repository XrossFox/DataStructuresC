#include <iostream>
using namespace std;

class ComparisonAndPalindromes{
    public:

        bool compare(char* array_1, char* array_2){
            int i;
            int j;
            for(i = 0, j = 0; array_1[i] != '\0' || array_2[j] != '\0'; i++, j++){
                if(array_1[i] != array_2[j]){
                    return false;
                }
            }
            return true;
        }

        bool is_palindrome(char* array_1){
            int i;
            int j;
            for(j = 0; array_1[j] != '\0'; j++){}
            j--;

            for(i = 0; i < j; i++, j--){
                if(array_1[i] != array_1[j]){
                    return false;
                }
            }
            return true;
        }

};

int main(){
    char array_1[] = "Paint";
    char array_2[] = "Painter";
    char array_3[] = "Paint";

    ComparisonAndPalindromes cap;

    cout<<"Arr 1 y 2: "<<cap.compare(array_1, array_2)<<"\n";
    cout<<"Arr 1 y 3: "<<cap.compare(array_1, array_3)<<"\n";
    cout<<"----"<<"\n";

    char array_4[] = "anitalavalatina";
    char array_5[] = "bob";
    char array_6[] = "madam";
    char array_7[] = "tijuana";

    cout<<"Arr 4: "<<cap.is_palindrome(array_4)<<"\n";
    cout<<"Arr 5: "<<cap.is_palindrome(array_5)<<"\n";
    cout<<"Arr 6: "<<cap.is_palindrome(array_6)<<"\n";
    cout<<"Arr 7: "<<cap.is_palindrome(array_7)<<"\n";

}