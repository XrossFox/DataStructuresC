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

int BinarySearch(struct Array arr, int key){

    int low = 0;
    int mid;
    int high = arr.length-1;

    while(low <= high){

        mid = (low + high) / 2;

        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;
}

int RBinSearch(int a[], int low, int high, int key){
    int mid;

    if(low <= high){
        mid = (low + high) / 2;
        
        if(key == a[mid]){
            return mid;
        }
        else if(key < a[mid]){
            return RBinSearch(a, low, mid-1, key);
        }
        else{
            return RBinSearch(a, mid+1, high, key);
        }
    }

    return -1;
}

int main(){
    struct Array arr = {{2,3,4,5,6}, 10,5};

    printf("Recursive: %d\n", RBinSearch(arr.A, 0, arr.length, 9));
    printf("Loop: %d\n", BinarySearch(arr, 9));
    Display(arr);

    return 0;

}