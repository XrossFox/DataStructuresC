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

int Get(struct Array arr, int index){

    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }

    return -1;
}

int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i = 1; i < arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for(i = 1; i < arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int s = 0;
    int i;
    for(i = 0; i < arr.length; i++){
        s += arr.A[i];
    }
    return s;
}

float Avg(struct Array arr){
    return (float) Sum(arr)/arr.length;
}

void Set(struct Array *arr, int index, int x){
    if(index >= 0 && index < arr->length){
        arr->A[index] = x;
    }
}

int main(){
    struct Array arr = {{2,3,14,25,6}, 10,5};

    printf("Get: %d\n", Get(arr,0));
    printf("Setting index\n");
    Set(&arr,0,23);
    Display(arr);
    printf("\nMax value: %d\n", Max(arr));
    printf("Min value: %d\n", Min(arr));
    printf("Sum value: %d\n", Sum(arr));
    printf("Avg value: %f\n", Avg(arr));

    Display(arr);
    return 0;

}