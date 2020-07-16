#include <stdio.h>
#include <stdlib.h>

int main(){

    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {1,3,5,7}};

    int *B[3];

    int **C;

    int i, j;

    printf("-------- A\n");
    for(i = 0; i < 3; i++){

        for(j = 0; j < 4; j++){

            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    B[0] = (int *)malloc(4*sizeof(int));
    B[0][0] = 1;
    B[0][1] = 1;
    B[0][2] = 1;
    B[0][3] = 1;
    B[1] = (int *)malloc(4*sizeof(int));
    B[1][0] = 1;
    B[1][1] = 1;
    B[1][2] = 1;
    B[1][3] = 1;
    B[2] = (int *)malloc(4*sizeof(int));
    B[2][0] = 1;
    B[2][1] = 1;
    B[2][2] = 1;
    B[2][3] = 1;

    printf("-------- B\n");
    for(i = 0; i < 3; i++){

        for(j = 0; j < 4; j++){

            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    C = (int **)malloc(3*sizeof(int *));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

    printf("-------- C\n");
    for(i = 0; i < 3; i++){

        for(j = 0; j < 4; j++){

            printf("%d ", C[i][j]);
        }
        printf("\n");
    }


    return 0;
}