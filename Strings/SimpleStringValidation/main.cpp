#include <iostream>
using namespace std;

class StringValidator{
    public:
        bool validate(char char_array[]){
            for(int i = 0; char_array[i]!= '\0'; i++){
                if(
                    !(char_array[i] >= 65 && char_array[i] <= 90) &&
                    !(char_array[i] >= 97 && char_array[i] <= 122) &&
                    !(char_array[i] >= 48 && char_array[i] <= 57) &&
                    !(char_array[i] == ' ')
                ){
                    return false;
                }
            }

            return true;
        }
};

int main(){
    char array_1[] = "Holis";
    char array_2[] = "Holis!";
    char array_3[] = "Holis Como esta usted";
    char array_4[] = "Holis Como esta usted?";
    char array_5[] = "abc123";
    char array_6[] = "abc 123";
    char array_7[] = "abc?123";
    StringValidator sv;
    cout<<"1: "<<array_1<<" : "<<sv.validate(array_1)<<"\n";
    cout<<"2: "<<array_2<<" : "<<sv.validate(array_2)<<"\n";
    cout<<"3: "<<array_3<<" : "<<sv.validate(array_3)<<"\n";
    cout<<"4: "<<array_4<<" : "<<sv.validate(array_4)<<"\n";
    cout<<"5: "<<array_5<<" : "<<sv.validate(array_5)<<"\n";
    cout<<"6: "<<array_6<<" : "<<sv.validate(array_6)<<"\n";
    cout<<"7: "<<array_7<<" : "<<sv.validate(array_7)<<"\n";
}