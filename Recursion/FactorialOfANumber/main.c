#include <stdio.h>

int fact(int n){

    if(n < 0){

        return 0;
    }
    if(n == 0){

        return 1;
    }

    return fact(n - 1) * n;
}

int Ifact(int n){

    if(n < 0){

        return 0;
    }

    int f = 1;
    int i;
    for(i = 1; i <= n; i++){

        f = f * i;
    }

    return f;
}

int main(){

    int r;
    r = fact(7);
    printf("Recursion: %d \n", r);
    r = Ifact(7);
    printf("Iterative: %d \n", r);
    return 0;
}
