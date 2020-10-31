#include <stdio.h>
#include <stdlib.h>

struct Array{

    int A[10];
    int size;
    int length;
};

void Append(struct Array *arr, int x){

    if (arr->length < arr->size){
        
        arr->A[arr->length++] = x;
    }

}

void Insert(struct Array *arr, int index, int x){

    int i;
    if(index >= 0 && index <= arr->length){

        for(i = arr->length; i > index; i--){

            arr->A[i] = arr->A[i-1];
        }
        
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete (struct Array *arr, int index){

    int x = 0;
    int i;

    if(index >= 0 && index <= arr->length-1){

        x = arr->A[index];

        for(i = index; i < arr->length-1; i++){

            arr->A[i] = arr->A[i+1];

        }
        arr->length--;
        return x;
    }

    return 0;
}

void Display(struct Array arr){

    int i;
    printf("\nElements are\n");
    
    for (i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
}

void Swap(int *x, int *y){

    int tempo;
    tempo = *x;
    *x = *y;
    *y = tempo;

}

int LinearSearch(struct Array *arr, int key){

    int i;
    for(i = 0; i < arr->length; i++){
        
        if(key == arr->A[i]){

            //swap - transposition
            Swap(&arr->A[i], &arr->A[i-1]);
            //swap - to head
            //Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

void Reverse (struct Array *arr){
    int *B;
    int i;
    int j;

    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1, j=0; i >= 0; i--, j++){
        B[j] = arr->A[i];
    }
    for(i = 0; i < arr->length; i++){
        arr->A[i] = B[i];
    }

}

void Reverse2(struct Array *arr){

    int i;
    int j;

    for(i = 0, j = arr->length-1; i < j; i++, j--){

        Swap(&arr->A[i], &arr->A[j]);
    }
}

int main(){
    struct Array arr = {{2,3,4,5,6}, 10,5};

    Reverse(&arr);
    Display(arr);

    return 0;

}