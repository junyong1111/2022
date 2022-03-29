// 백준(2562) 최댓값

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 9;
    int arr[n];
    int idx = 1;
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    idx = 1;
    for(int i=1; i<n; i++){
        if(max <= arr[i]){
            max = arr[i];
            idx = i+1;
        }
    }
    printf("%d\n", max);
    printf("%d\n", idx);

    return 0;
}