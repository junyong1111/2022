// 백준(10809) 알파벳 찾기

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){
    char str[101];
    int alpha[26];
    int check = 0;
    for(int i=0; i<26; i++){
        alpha[i] = -1;
    }
    int i = 0;
    int temp = 0;
    scanf("%s", str);
    int len = strlen(str);
    while(len--){
        temp = str[i] - 97;
        if(alpha[temp] == -1){
            alpha[temp] =i;
            i++;
        } // 처음 나온 알파벳이면 idx 저장
        else{ //중복 처리
            i++;
            continue;
        }
    } //while
    for(int i=0; i<26; i++){
        printf("%d ", alpha[i]);
    }
    printf("\n");
    return 0;
}