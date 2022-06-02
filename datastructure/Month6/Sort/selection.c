#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void selectionSort(int A[]){
    printf("Before Sort : ");
    for(int i=0; i<SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n<<<<<<<<<<<< Selection Sorting.... >>>>>>>>>>>>>>\n");

    for(int i=0; i<=SIZE-2; i++){
        int min = i;
        for(int j= i+1; j<=SIZE-1; j++)
            if(A[j]<A[min])
                min = j;
            int temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        
    }
    for(int i=0; i<SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

}

int main(){
    srand(time(NULL));
    int A[SIZE];
    for(int i=0; i<SIZE; i++)
        A[i] = rand() % 100; 
    
    selectionSort(A);
    

    return 0;
}