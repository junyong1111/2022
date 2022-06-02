#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t) )

int partition(int list[], int left, int right){
    int pivot = list[left];
    int low = left;
    int high = right + 1;
    int temp;

    do{
        do
            low++;
        while(list[low] < pivot);
        do
            high --;
        while(list[low] > pivot);

        if(low <high)
            SWAP(list[low], list[high], temp);
    }
    while(low < high);
    SWAP(list[left], list[high], temp);


}

void quickSort(int list[], int left, int right){
    if(left < right){
        int p = partition(list, left, right);
        quickSort(list, left , p-1);
        quickSort(list, p+1, right);    
    }
}

int main(){
    int list[SIZE];
    srand(time(NULL));

    for(int i=0; i<SIZE; i++)
        list[i] = rand()%100;
    for(int i=0; i<SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");

    quickSort(list, 0 , SIZE-1);

    for(int i=0; i<SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
    
   
    


    return 0;
}