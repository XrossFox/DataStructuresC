#include <iostream>
using namespace std;

class StringCaseOperations{
    public:
        void to_lower_case(char& c){
            if(c >= 65 && c <= 90){
                c += 32;
            }
        }

        void to_upper_case(char& c){
            if(c >= 'a' && c <= 122){
                c -= 32;
            }
        }

        void toggle_case(char& c){
            if(c >= 65 && c <= 90){
                c += 32;
            }
            else if(c >= 'a' && c <= 122){
                c -= 32;
            }
        }

};

int main(){
    char A[] = "Welcome1";
    char B[] = "wELCOME2";
    char C[] = "WElcOmE3";

    StringCaseOperations sco;

    for(char e: A){
        sco.to_upper_case(e);
        cout<<e;
    }

    cout<<"\n";

    for(char e: B){
        sco.to_lower_case(e);
        cout<<e;
    }

    cout<<"\n";

    for(char e: C){
        sco.toggle_case(e);
        cout<<e;
    }

    cout<<"\n";

}