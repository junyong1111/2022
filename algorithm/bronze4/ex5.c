// 백준(5543) 상근날드

#include <stdio.h>
#include <stdlib.h>
# define N 5
int main(){
    int arr[N] = {0};
    for(int i=0; i< N; i++){
        scanf("%d", &arr[i]);
    }
    int min_h = arr[0];
    int min_s = arr[3];
    for(int i=1; i<N; i++){
        if(i<3){
            if(min_h >=arr[i]){
                min_h = arr[i];
            } 
        }
        else{
            if(min_s >=arr[i]){
                min_s = arr[i];            }

        }
    }
    int sum = (min_h + min_s) -50;
    printf("%d\n", sum);

  return 0;
}