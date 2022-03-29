#include <stdio.h>
#include <stdlib.h>


int main(){
    int matrix1[2][2];
    int matrix2[2][3];
    int matrix3[2][3];
    int sum =0;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            scanf("%d",&matrix1[i][j]);
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            scanf("%d",&matrix2[i][j]);
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<2; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
            sum = 0;
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}