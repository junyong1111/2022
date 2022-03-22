// 예제_6 : 1차원 배열에 1~100 난수를 저장 후 최댓값 구하기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 최댓값 함수 구현 값을 반환해야 하므로 int자료형으로 선언
int findMax(int A[], int N){ //배열과 정수 인자
    int Max = A[0]; //초기 최댓값은 모르기 때문에 배열의 첫번째 Index값을 삽입
    for(int i=1; i<N; i++){
        if (Max <= A[i]){ //Max값보다 더 큰 값이 존재하면 
            Max = A[i]; // 교체 
        }
        else{
            continue;
        }
    }
    return Max;
};

int main(void){
    int A [50], N;
    scanf("%d", &N);

    srand(time(NULL)); //실행마다 항상 바뀌기 때문에 rand에서는 seed값이 항상 변함

    for (int i=0; i<N; i++){
        // C에서 rand에서는 seed값이 고정되어있어서 seed값을 time값으로 난수 발생
        A[i] = rand()%100 +1; // 1~100 사이 난수
    }
    for (int i=0; i<N; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("%d\n", findMax(A, N)); // 함수 실행
    return 0;
}
