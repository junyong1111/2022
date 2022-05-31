#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void insertion_Sort(int A[]){
    printf("Before Sort : ");
    for(int i=0; i<SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n<<<<<<<<<<<< insertion Sorting.... >>>>>>>>>>>>>>\n");

    for(int i=1; i<=SIZE-1; i++){
        int key = A[i];
        int j = i-1;

        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        
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
    
    insertion_Sort(A);
    

    return 0;
}