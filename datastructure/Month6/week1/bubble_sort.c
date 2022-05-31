#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define FALSE 0
#define TRUE 1

void swap(int A[], int j){
    int temp = A[j-1];
    A[j-1] =  A[j];
    A[j] = temp;
}

void bubble_Sort(int A[]){
    printf("Before Sort : ");
    for(int i=0; i<SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n<<<<<<<<<<<< Bubble Sorting.... >>>>>>>>>>>>>>\n");

    for(int i=1; i<=SIZE-1; i++){
        int flag = FALSE;
        for(int j=1; j<= SIZE-i; j++)
            if(A[j-1] > A[j])
            {
                swap(A,j);
                flag = TRUE;
            }

        if (flag == FALSE)
            break;
                
        

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
    
    bubble_Sort(A);
    

    return 0;
}