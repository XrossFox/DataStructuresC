#include <stdio.h>

int fib(int n){

    int t0 = 0, t1 = 1, s = 0, i;

    if (n <= 1){
        return n;
    }

    for(i = 1; i <= n; i++){

        s = t0 + t1;
        t0 = t1;
        t1 = s;

    }

    return s;
}

int rfib(int n){

    if(n <= 1){

         return n;
    }

    return rfib(n-2) + rfib(n-1);
}
// WIP create gloal array in Heap to work
int memofib(int n){
    int F[n];
    int i = 0;

    for(i = 0; i < n; i++){

        F[i] = -1;
    }

    return _memofib(F, n);
}

int _memofib(int F[], int n){

    if(n <= 1){

        F[n] = n;
        return n;
    }
    else{

        if(F[n-2] == -1){
            F[n-2] = _memofib(F, n-2);
            
        }
    }
}

int main(){

    printf("Iterative: %d \n", fib(10));
    return 0;
    printf("Recursive: %d \n", rfib(10));
    return 0;
}