#include <stdio.h>
#include <stdlib.h>

int f(int *x, int c){

    c = c - 1;
    if(c == 0){
        return 1;
    }
    *x = *x+1;
    return f(&x, c) * *x;
}

int main(){

    int a = 5;
    int *p = 5;
    printf("%d", *p);
    printf("%d", f(&p, *p));
    free(p);
}