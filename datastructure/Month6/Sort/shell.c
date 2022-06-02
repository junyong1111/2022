#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void shell_sort(int A[]){

    printf("Before Sort : ");
    for(int i=0; i<SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n<<<<<<<<<<<< Shell Sorting.... >>>>>>>>>>>>>>\n\n");

    for(int gap=5; gap>=1; gap-=2){
        for(int i = gap; i<= SIZE-1; i++){
            int key = A[i];
            int j = i;

            while(j>=gap && A[j-gap] > key){
                A[j] = A[j-gap];
                j -= gap;
            }
            A[j] = key;
        }
        
        
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
    
    shell_sort(A);
    

    return 0;
}