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

void InsertSort(struct Array *arr, int x){

    int i = arr->length-1;
    if(arr->length == arr->size){
        return;
    }
    while(i >= 0 && arr->A[i] > x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;

}

int isSorted(struct Array arr){

    int i;
    for(i = 0; i < arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr){

    int i;
    int j;
    i = 0;

    while(i < j){

        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if(i < j) Swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else{
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(;i < arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(;j < arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

int main(){

    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,4,7,18,20},10,5};
    struct Array *arr3;

    arr3 = Merge(&arr1, &arr2);

    Display(*arr3);

    return 0;

}   