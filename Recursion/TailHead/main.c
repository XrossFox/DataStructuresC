#include <stdio.h>

void fun(int n)
{

    if(n>0){
        // Head Recurssion
        // printf("%d ", n);
        fun(n-1);
        // Tail Recurssion
        printf("%d ", n);
    }
}

int main(){

    int x=3;

    fun(x);

    return 0;
}