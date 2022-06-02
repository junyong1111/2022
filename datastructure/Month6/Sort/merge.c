#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void merge(int list[], int sorted[], int left, int mid, int right){
    int i = left;
    int j = mid +1;
    int k = left;

    while(i<=mid && j<=right){
        if(list[i]<=list[j]){
            sorted[k] = list[i];
            k++;
            i++;
        }
        else{
            sorted[k++] = list[j++];
        }
    }

    if(i>mid){
        for(int l=j; l<=right; l++)
            sorted[k++] = list[l];
    }
    else{
        for(int l=i; l<=mid; l++)
            sorted[k++] = list[l];
    }
    for(int l= left; l<=right; l++){
        list[l] = sorted[l];
    }
}

void mergeSort(int list[], int sorted[], int left, int right){
    if(left < right){ //자를 수 있다면
        int mid = (left+right) /2;
        mergeSort(list,sorted, left, mid);
        mergeSort(list,sorted, mid+1, right);
        merge(list, sorted, left, mid, right);
    }
}

int main(){
    int list[SIZE],sorted[SIZE];
    srand(time(NULL));

    for(int i=0; i<SIZE; i++)
        list[i] = rand()%100;
    for(int i=0; i<SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
    
    mergeSort(list, sorted, 0, SIZE-1);
    
    for(int i=0; i<SIZE; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    return 0;
}