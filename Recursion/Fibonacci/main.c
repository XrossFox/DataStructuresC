#include <stdio.h>
#include <stdlib.h>

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

int *F;

int _memofib(int n);

int memofib(int n){

    F = (int*) malloc(n * sizeof(int));
    int i = 0;

    for(i = 0; i < n; i++){

        F[i] = -1;
    }

    int result = _memofib(n);
    free(F);
    return result;
}

int _memofib(int n){

    if(n <= 1){

        F[n] = n;
        return n;
    }
    else{

        if(F[n-2] == -1){

            F[n-2] = _memofib(n - 2);   
        }
        if(F[n-1] == -1){

            F[n-1] = _memofib(n - 1);
        }

        F[n] = F[n-2] + F[n-1];
        return F[n-2] + F[n-1];
    }
}

int main(){

    printf("Iterative: %d \n", fib(6));
    printf("Recursive: %d \n", rfib(6));
    printf("Recursive Memo: %d \n", memofib(6));
    return 0;
}