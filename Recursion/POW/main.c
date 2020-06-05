#include <stdio.h>

int power(int m, int n){

    if(n == 0){

        return 1;
    }

    return power(m, n-1) * m;
}

int power1(int m, int n){

    if(n == 0){

        return 1;
    }

    if(n % 2 == 0){

        return power1(m * m, n/2);
    }

    return m * power1(m * m, (n-1)/2);
} 

int main(){
    int r;
    r = power(5, 9);
    printf("Normal recursion: %d\n", r);
    r = power1(5, 9);
    printf("Enhanced recursion: %d\n", r);
    return 0;
}