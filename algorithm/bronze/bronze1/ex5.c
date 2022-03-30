//백준(2740) 행렬 곱셈

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,M,K;
    int sum = 0;
    scanf("%d %d",&N,&M);
    int matrix1[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",&matrix1[i][j]);
        }
    } //A 행렬 입력
    scanf("%d %d",&M,&K);
    int matrix2[M][K];
    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++){
            scanf("%d",&matrix2[i][j]);
        }
    } // B 행렬 입력
    int matrix3[N][K];

    for(int i=0; i<N; i++){ //A행렬의 행만큼
        for(int j=0; j<K; j++){ //B행렬의 열만큼
            for(int k=0; k<M; k++){ // A행렬의 열 == B행렬의 행 만큼
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
            sum = 0;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            printf("%d ",matrix3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
